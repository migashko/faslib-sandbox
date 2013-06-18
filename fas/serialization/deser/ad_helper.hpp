#ifndef FAS_SERIALIZATION_DESER_AD_HELPER_HPP
#define FAS_SERIALIZATION_DESER_AD_HELPER_HPP

#include <fas/range/orange.hpp>
#include <fas/range/typerange.hpp>

namespace fas{ namespace serialization{ namespace deser{

// helper for ranged value
// helper not set status
// TODO: rename
template<typename TgTarget, bool Clear = true>
struct ad_back_inserter
{
  typedef TgTarget _target_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    //return t.get_aspect().template get<_target_>()(t, std::make_pair(r, orange(v, true))).first;
    typename typerange<V>::orange vr = orange(v, Clear);
    return t.get_aspect().template get<_target_>()(t, J(), vr, r);
  }
};

}}}

#endif
