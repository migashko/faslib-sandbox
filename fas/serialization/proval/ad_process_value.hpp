//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PROVAL_AD_PROCESS_VALUE_HPP
#define FAS_SERIALIZATION_PROVAL_AD_PROCESS_VALUE_HPP

#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace serialization{ namespace proval{

template<typename TgStatus>
struct ad_process_value
{
  typedef TgStatus _status_;
  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef typename J::targets targets;
    typedef typename fas::normalize<targets>::type target_list;
    
    _(t, v, target_list() );
  }
  
private:

  template<typename T, typename V, typename TargetList>
  void _( T& t, V& v, TargetList)
  {
    typedef typename head< TargetList >::type target;
    typedef typename tail< TargetList >::type target_list;
    
    t.get_aspect().template get< typename target::tag >()(t, target(), v);
    if ( !t.get_aspect().template get<_status_>() )
      return;
    _(t, v, target_list() );
  }
  
  template<typename T, typename V>
  void _(T&, V& , empty_list) {  }
};

}}}

#endif
