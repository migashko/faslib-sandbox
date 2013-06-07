#ifndef FAS_SERIALIZATION_DESER_AD_ACCESS_HPP
#define FAS_SERIALIZATION_DESER_AD_ACCESS_HPP

#include <fas/range/orange.hpp>

namespace fas{ namespace serialization{ namespace deser{

struct ad_access
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target target;
    typedef typename target::tag tag;
    return t.get_aspect().template get<tag>()(t, target(), J()(v), r);
  }
};

}}}

#endif
