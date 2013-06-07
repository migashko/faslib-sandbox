//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_TARGET_N_HPP
#define FAS_SERIALIZATION_DESER_AD_TARGET_N_HPP

#include <fas/type_list/type_at.hpp>


namespace fas{ namespace serialization{ namespace deser{

template<typename TgN>
struct ad_target_n
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    typedef typename type_at<TgN, target_list>::type target;
    typedef typename target::tag tag;

    return t.get_aspect().template get<tag>()(t, target(), v, r);
  }

private:

};

}}}

#endif
