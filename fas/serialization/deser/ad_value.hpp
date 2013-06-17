//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_VALUE_HPP
#define FAS_SERIALIZATION_DESER_AD_VALUE_HPP

#include <fas/type_list/type_at.hpp>

namespace fas{ namespace serialization{ namespace deser{

  
struct ad_value
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    return _(t, v, r, target_list() );
  }

private:

  template<typename T, typename V, typename R, typename TargetList>
  R _( T& t, V& v, R r, TargetList)
  {
    typedef typename head<TargetList>::type target;
    typedef typename target::tag _tag_;

    if ( !t.get_aspect().template get<_status_>() || !try_<_except_>(t) )
      return r;
    
    r = t.get_aspect().template get<_tag_>()(t, target(), v, r);

    typedef typename tail<TargetList>::type target_list;

    return _(t, v, r, target_list() );
  }

  template<typename T, typename V, typename R>
  R _( T&, V&, R r, empty_list)
  {
    return r;
  }
};


}}}

#endif
