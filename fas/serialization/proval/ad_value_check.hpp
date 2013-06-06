//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PROVAL_AD_VALUE_CHECK_HPP
#define FAS_SERIALIZATION_PROVAL_AD_VALUE_CHECK_HPP

#include <fas/serialization/except/invalid_value.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/except/throw_.hpp>

namespace fas{ namespace serialization{ namespace proval{

struct ad_value_check
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    if ( !J()(v) )
      return throw_<_except_>(t, invalid_value( distance(r) ), r);
    return r;
  }
};

}}}

#endif
