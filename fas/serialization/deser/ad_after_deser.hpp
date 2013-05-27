//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_AFTER_DESER_HPP
#define FAS_SERIALIZATION_DESER_AD_AFTER_DESER_HPP

#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>
#include <fas/serialization/except/invalid_value.hpp>

#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace serialization{ namespace deser{

// excludes the range of further processing
template<typename TgStatus, typename TgNext>
struct ad_after_deser
{
  typedef TgStatus _status_;
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
