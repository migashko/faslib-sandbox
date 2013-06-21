#ifndef FAS_SERIALIZATION_DESER_AD_VALUE2RANGE_HPP
#define FAS_SERIALIZATION_DESER_AD_VALUE2RANGE_HPP

#include <fas/range/typerange.hpp>
#include <fas/range/orange.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename Tg>
struct ad_value2range
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    //typedef V value_type;
    typename typerange<V>::orange vr = orange(v);
    return t.get_aspect().template get<Tg>()( t, J(), vr, r);
  }
};
  
}}}

#endif
