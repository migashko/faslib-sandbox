#ifndef FAS_SERIALIZATION_DESER_AD_INSERTER_HPP
#define FAS_SERIALIZATION_DESER_AD_INSERTER_HPP

#include <fas/range/orange.hpp>
#include <fas/range/typerange.hpp>

namespace fas{ namespace serialization{ namespace deser{

struct ad_inserter
{  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename typerange<V>::orange range_type;
    typedef typename range_type::value_type value_type;
    value_type value = value_type();
    r = t.get_aspect().template get< typename J::tag >()(t, typename J::targets(), value, r);
    if (t.get_aspect().template get< _status_ >())
      *(orange(v)++) = value;
    return r;
    // typedef typename J::targets targets;
    // return t.get_aspect().template get<_target_>()(t, J(), J()(v), r);
  }
};

}}}

#endif
