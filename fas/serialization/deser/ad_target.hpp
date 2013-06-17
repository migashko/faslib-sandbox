//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_TARGET_HPP
#define FAS_SERIALIZATION_DESER_AD_TARGET_HPP

namespace fas{ namespace serialization{ namespace deser{

struct ad_tag
{  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::tag _tag_;
    return t.get_aspect().template get<_tag_>()(t, J(), v, r);
  }
};

struct ad_target
{  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target target;
    typedef typename J::tag _tag_;
    return t.get_aspect().template get<_tag_>()(t, target(), v, r);
  }
};


}}}

#endif
