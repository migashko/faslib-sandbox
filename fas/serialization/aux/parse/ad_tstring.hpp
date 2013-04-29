//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_AUX_PARSE_AD_TSTRING_HPP
#define FAS_SERIALIZATION_AUX_PARSE_AD_TSTRING_HPP

#include <fas/serialization/aux/except/unexpected_end_fragment.hpp>
#include <fas/serialization/aux/except/expected_of.hpp>
#include <fas/serialization/aux/except/out_of_range.hpp>

#include <fas/except/throw_.hpp>


#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace aux{ namespace parse{

template<typename TString, typename TgExcept>
struct ad_tstring
{
  typedef TgExcept _except_;
  typedef TString tstring;
  typedef string_range< typename TString::value_type > tstring_range;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    tstring_range rr = tstring_range( tstring()() );
    for ( ; rr; ++rr )
    {
      if ( *r != *rr )
        return false;
    }
    return true;
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

      if ( *ri != *rr )
        return throw_<_except_>( t, expected_of(tstring()(),  distance(ri) ), std::pair<RI, RO>(ri, ro));

      *(ro++) = *(ri++);
    }

    return std::pair<RI, RO>(ri, ro);
  }
};

}}}}

#endif

