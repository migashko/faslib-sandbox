#ifndef FAS_SERIALIZATION_DESER_AD_HELPER_HPP
#define FAS_SERIALIZATION_DESER_AD_HELPER_HPP

#include <fas/range/orange.hpp>

namespace fas{ namespace serialization{ namespace deser{

// helper for ranged value
// helper not set status
// TODO: rename
template<typename TgTarget>
struct ad_helper
{
  typedef TgTarget    _target_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    return t.get_aspect().template get<_target_>()(t, std::make_pair(r, orange(v)).first;
  }
};

}}}

#endif
