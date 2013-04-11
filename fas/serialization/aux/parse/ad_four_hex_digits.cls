// #include <fas/serialization/<<implementation defined>>/try_throw.hpp>
// #include <fas/serialization/<<implementation defined>>/unexpected_end_fragment.hpp>
// #include <fas/serialization/<<implementation defined>>/parse_error.hpp>
// #include <fas/serialization/<<implementation defined>>/out_of_range.hpp>
// #include <fas/range/distance.hpp>
// #include <utility>

struct ad_four_hex_digits
{
  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return r && (
                     ( *r >= '0' && *r <='9' )
                  || ( *r >= 'A' && *r <='F' )
                  || ( *r >= 'a' && *r <='f')
                );
  }

  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator()(T& t, RI ri, RO ro)
  {
    return this->parse(t, std::make_pair(ri, ro) );
  }

private:

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    for (register int i=0; i < 4; ++i)
    {
      if ( !this->peek(t, rr.first) )
      {
        if (rr.first)
          return throw_( t, parse_error( distance(rr.first) ), rr);
        else
          return throw_( t, unexpected_end_fragment(), rr);
      }

      if ( !rr.second )
        return throw_( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);
    }
    return rr;
  }
};

