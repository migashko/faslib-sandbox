//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PROVAL_AD_PROVAL_HPP
#define FAS_SERIALIZATION_PROVAL_AD_PROVAL_HPP

#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{ namespace proval{

// excludes the range of further processing
template<typename TgNext>
struct ad_proval
{
  typedef TgNext   _next_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    t.get_aspect().template get<_status_>() = true;
    t.get_aspect().template get<_next_>()(t, J(), v);
    if ( !t.get_aspect().template get<_status_>() )
      return throw_<_except_>(t, invalid_value( distance(r) ), r);
    return r;
  }
};

}}}

#endif
