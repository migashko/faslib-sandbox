// #include <fas/range/distance.hpp>
// #include <fas/serialization/<<implementation defined>>/out_of_range.hpp>
// #include <fas/serialization/<<implementation defined>>/unexpected_end_fragment.hpp>
// #include <fas/serialization/<<implementation defined>>/parse_error.hpp>
// #include <fas/serialization/<<implementation defined>>/try_throw.hpp>
// #include <utility>

struct ad_json_number
{
  template<typename T, typename R>
  bool peek( T&, R r) {  return r && ( *r=='-' || ( *r>='0' && *r<='9' ) ); }

  template<typename T, typename R, typename RD>
  std::pair<R, RD> operator()(T& t, R r, RD rd)
  {
    return this->parse(t, std::make_pair(r, rd) );
  }

private:

  template<typename T, typename RR>
  RR parse_digits(T& t, RR rr)
  {
    if ( !rr.first )
      return throw_( t, unexpected_end_fragment(), rr );

    if ( (*rr.first) < '0' || (*rr.first) > '9' )
      return throw_( t, parse_error( distance(rr.first) ), rr);

    for ( ;rr.first && *rr.first >= '0' && *rr.first <= '9';)
    {
      if ( !rr.second )
        return throw_( t, out_of_range(distance(rr.first) ), rr );

      *(rr.second++) = *(rr.first++);
    }
    return rr;
  }

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    if ( !rr.first )
      return throw_( t, unexpected_end_fragment(), rr );

    // if '-'
    if ( *rr.first == '-' )
    {
      if ( !rr.second )
        return throw_( t, out_of_range( distance(rr.first) ), rr );
      *(rr.second++)= *(rr.first++);
    }

    // if '0'
    if ( rr.first && *rr.first == '0')
    {
      if ( !rr.second )
        return throw_( t, out_of_range( distance(rr.first) ), rr );
      *(rr.second++)= *(rr.first++);
      // 00 prohibited
      return rr;
    }
    else
    {
      rr = this->parse_digits(t, rr);

      if ( !try_(t) )
        return rr;
    }

    // if '.'
    if ( rr.first && *rr.first=='.' )
    {
      if ( !rr.second )
        return throw_( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);

      if ( !rr.first )
        return throw_( t, unexpected_end_fragment(), rr );

      rr = this->parse_digits(t, rr);

      if ( !try_(t) )
        return rr;
    }

    // if 'e'
    if ( rr.first && ( *rr.first=='e' || *rr.first=='E' ) )
    {
      if ( !rr.second )
        return throw_( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);

      if ( !rr.first )
        return throw_( t, unexpected_end_fragment(), rr );

      if ( rr.first && (*rr.first=='-' || *rr.first=='+'))
      {
        if ( !rr.second )
          return throw_( t, out_of_range( distance(rr.first) ), rr );

        *(rr.second++)= *(rr.first++);
      }

      rr = this->parse_digits(t, rr);
    }

    return rr;
  }


};
