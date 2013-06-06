//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PARSE_AD_CHARSET_HPP
#define FAS_SERIALIZATION_PARSE_AD_CHARSET_HPP

#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/expected_of.hpp>
#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>

namespace fas{ namespace serialization{ namespace parse{

template<typename TString>
struct ad_charset
{
  typedef TString tstring;
  typedef string_range< typename TString::value_type > tstring_range;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    std::cout << "ad_charset::peek " << tstring()() << std::endl;
    if ( !r )
      return false;

    tstring_range sr = tstring_range( tstring()() );
    for ( ; sr; ++sr )
    {
      if ( *r == *sr )
        return true;
    }
    return false;
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    std::cout << "ad_charset::() " << tstring()() << std::endl;
    tstring_range sr = tstring_range( tstring()() );
    for (;sr;++sr)
    {
      if (!rr.second)
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      if ( !rr.first )
        return throw_<_except_>( t, unexpected_end_fragment(), rr );

      if ( *rr.first == *sr )
      {
        *(rr.second++) = *(rr.first++);
        return rr;
      }
    }
    return throw_<_except_>( t, expected_of(tstring()(),  distance(rr.first) ), rr);
  }
};

}}}

#endif

