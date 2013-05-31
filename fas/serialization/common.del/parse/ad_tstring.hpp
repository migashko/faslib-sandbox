//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_TSTRING_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_TSTRING_HPP

#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/expected_of.hpp>
#include <fas/serialization/except/out_of_range.hpp>

#include <fas/except/throw_.hpp>

#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TString, typename TgExcept>
struct ad_tstring
{
  typedef TgExcept _except_;
  typedef TString tstring;
  typedef string_range< typename TString::value_type > tstring_range;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    if ( !r )
      return false;
    tstring_range rr = tstring_range( tstring()() );
    for ( ;rr; ++rr, ++r )
    {
      if ( *r != *rr )
        return false;
    }
    return true;
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    tstring_range sr = tstring_range( tstring()() );
    for (;sr;++sr)
    {
      if (!rr.second)
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      if ( !rr.first )
        return throw_<_except_>( t, unexpected_end_fragment(), rr );

      if ( *rr.first != *sr )
        return throw_<_except_>( t, expected_of(tstring()(),  distance(rr.first) ), rr );

      *(rr.second++) = *(rr.first++);
    }

    return rr;
  }
};

}}}}

#endif

