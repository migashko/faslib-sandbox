
// #include <fas/serialization/<<implementation defined>>/try_throw.hpp>
// #include <fas/serialization/<<implementation defined>>/unexpected_end_fragment.hpp>
// #include <fas/serialization/<<implementation defined>>/out_of_range.hpp>

// #include <fas/range/distance.hpp>
// #include <fas/range/string_range.hpp>
// #include <utility>


template<typename TgClose>
struct ad_json_string_content
{
  typedef TgClose _close_;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return true;
  }

  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator()(T& t, RI ri, RO ro)
  {
    for ( ;ri; )
    {
      if (t.get_aspect().template get<_close_>().peek(t, ri) )
        break;

      if (*ri=='\\')
      {
        if ( !(++ri) )
          return throw_( t, unexpected_end_fragment(), std::pair<RI, RO>(ri, ro));

        if ( *ri != '"' && *ri != '\\' && *ri != '/'
             && *ri != 't' && *ri != 'b' && *ri != 'n'
             && *ri != 'r' && *ri != 'f' && *ri != 'u'
           )
            return throw_( t, invalid_json_string( distance(ri) ), std::pair<RI, RO>(ri, ro));


        if ( *(r++) == 'u' )
        {
          r = this->parse_hex(t, r);
          if ( !try_(t) )
            return r;
        }
      }
      else
      {
        r = this->parse_symbol(t, r);
        if ( !try_(t) )
          return r;
      }



    }

    return std::pair<RI, RO>(ri, ro);
    /*
    tstring_range rr = tstring_range( tstring()() );
    for (;rr;++rr)
    {
      if (!ro)
        return throw_t<_except_>( t, out_of_range( distance(ri) ), std::pair<RI, RO>(ri, ro) );

      if ( *ri != *rr )
        return throw_t<_except_>( t, parse_error( distance(ri) ), std::pair<RI, RO>(ri, ro) );

      *(ro++) = *rr;
    }

    return std::pair<RI, RO>(ri, ro);
    */
  }
};

