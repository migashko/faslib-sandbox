#ifndef FAS_SERIALIZATION_DESER_AD_CONTAINER_HPP
#define FAS_SERIALIZATION_DESER_AD_CONTAINER_HPP

#include <fas/range/typerange.hpp>
#include <fas/range/orange.hpp>

namespace fas{ namespace serialization{ namespace deser{

struct ad_container
{
  
  template<typename T, typename J, typename V>
  void operator()(T& /*t*/, J, V& /*v*/)
  {
  }
  

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target target;
    typedef typename target::tag _tag_;
    typename typerange<V>::orange vr = orange(v, true);
    return t.get_aspect().template get<_tag_>()( t, target(), vr, r);
  }
};

}}}

#endif
