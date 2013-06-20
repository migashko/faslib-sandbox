#ifndef FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP
#define FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP

#include <fas/typemanip/reference_wrapper.hpp>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename Tg>
struct ad_push2range
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V v, R r)
  {
    typedef typename V::type::value_type value_type;
    value_type value = value_type();
    r = t.get_aspect().template get<Tg>()(t, J(), ref(value), r);
    if ( t.get_aspect().template get<_status_>() )
      *(v.get()++) = value;
    return r;
  }
};
  
}}}

#endif
