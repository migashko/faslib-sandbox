//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_CHARSET_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_CHARSET_HPP

#include <fas/serialization/common/except/unexpected_end_fragment.hpp>
#include <fas/serialization/common/except/expected_of.hpp>
#include <fas/serialization/common/except/out_of_range.hpp>

#include <fas/except/throw_.hpp>

#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TString, typename TgExcept>
struct ad_charset
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
    for ( ; rr; ++rr )
    {
      if ( *r == *rr )
        return true;
    }
    return false;
  }

  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator()(T& t, RI ri, RO ro)
  {
    tstring_range rr = tstring_range( tstring()() );
    for (;rr;++rr)
    {
      if (!ro)
        return throw_<_except_>( t, out_of_range( distance(ri) ), std::pair<RI, RO>(ri, ro) );

      if ( !ri )
        return throw_<_except_>( t, unexpected_end_fragment(), std::pair<RI, RO>(ri, ro) );

      if ( *ri == *rr )
      {
        *(ro++) = *(ri++);
        return std::pair<RI, RO>(ri, ro);
      }
    }

    return throw_<_except_>( t, expected_of(tstring()(),  distance(ri) ), std::pair<RI, RO>(ri, ro));

  }
};

}}}}

#endif

