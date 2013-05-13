//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2009, 2010, 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_JSON_STRING_CONTENT_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_JSON_STRING_CONTENT_HPP

#include <fas/serialization/common/except/out_of_range.hpp>
#include <fas/serialization/common/except/unexpected_end_fragment.hpp>
#include <fas/serialization/common/except/parse_error.hpp>
#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>
#include <utility>


namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgUtf8, typename TgCtrl, typename TgHex, typename TgEnd, typename TgExcept>
struct ad_json_string_content
{
  typedef TgUtf8 _utf8_;
  typedef TgCtrl _ctrl_;
  typedef TgHex  _hex_;
  typedef TgEnd _end_;
  typedef TgExcept _except_;


  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return true;
  }

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    for ( ;rr.first; )
    {
      if (t.get_aspect().template get<_end_>().peek(t, rr.first) )
        return rr;

      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      if (*rr.first=='\\')
      {
        *(rr.second++)= *(rr.first++);

        if ( !rr.second )
          return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

        if ( !rr.first )
          return throw_<_except_>( t, unexpected_end_fragment(), rr );

        bool hex = ( *rr.first == 'u');

        rr = t.get_aspect().template get<_ctrl_>()(t, rr);

        if ( !try_<_except_>(t) )
          return rr;

        if (hex)
        {
          rr = t.get_aspect().template get<_hex_>()(t, rr);
          if ( !try_<_except_>(t) )
            return rr;
        }
      }
      else
      {
        rr = t.get_aspect().template get<_utf8_>()(t, rr.first, rr.second);
        if ( !try_<_except_>(t) )
          return rr;
      }
    }
    return throw_<_except_>( t, unexpected_end_fragment(), rr );
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return this->parse(t, rr);
  }
};

}}}}

#endif
