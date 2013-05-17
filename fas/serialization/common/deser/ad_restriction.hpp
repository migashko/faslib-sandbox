//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_RESTRICTION_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_RESTRICTION_HPP

#include <fas/except/throw_.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgExcept>
struct ad_restriction
{
  typedef TgExcept _except_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    if ( ! J()(v) )
      return throw_<_except_>(t, invalid_value( distance(r) ), r);
    return r;
  }
};

}}}}

#endif
