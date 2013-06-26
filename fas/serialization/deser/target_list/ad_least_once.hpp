//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_LEAST_ONCE_HPP
#define FAS_SERIALIZATION_DESER_AD_LEAST_ONCE_HPP

namespace fas{ namespace serialization{ namespace deser{

template<typename Tg>
struct ad_least_once
{  
  typedef Tg _target_;
  
  template<typename T, typename TargetList, typename V, typename R>
  R operator()(T& t, TargetList, V& v, R r)
  {
    typedef TargetList target_list;
    int count = 0;
    t.get_aspect().template get<_status_>() = true;
    r =  _(t, target_list(), v, r, count);
    t.get_aspect().template get<_status_>() = (count!=0);
  }
  
private:

  template<typename T, typename TargetList, typename V, typename R>
  R operator()(T& t, TargetList, V& v, R r, int& count)
  {
    typedef typename head<TargetList>::type target;
    typedef typename tail<TargetList>::type target_list;
    r = t.get_aspect().template get<_target_>()(t, target(), v, r);
    if ( t.get_aspect().template get<_status_>() )
      ++count;
    else
      t.get_aspect().template get<_status_>() = true;
    return _(t, target_list(), v, r, count);
  }

  template<typename T, typename V, typename R>
  R operator()(T& , empty_list, V&, R r, int& count)
  {
    return r;
  }

};


}}}

#endif
