#ifndef FAS_SERIALIZATION_DESER_AD_ACCESS_HPP
#define FAS_SERIALIZATION_DESER_AD_ACCESS_HPP

#include <fas/range/orange.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgTarget>
struct ad_access
{
  typedef TgTarget _target_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    // typedef typename J::targets targets;
    return t.get_aspect().template get<_target_>()(t, J(), J()(v), r);
  }
};

}}}

#endif
