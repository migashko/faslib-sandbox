#ifndef FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP
#define FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP

#include <fas/serialization/tags.hpp>
#include <fas/range.hpp>

namespace fas{ namespace serialization{ namespace deser{

struct ad_element
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target target;
    typedef typename target::tag _tag_;

    typedef typename range_traits<V>::value_type value_type;
    value_type value = value_type();
    r = t.get_aspect().template get<_tag_>()(t, target(), value, r);
    if ( t.get_aspect().template get<_status_>() )
    {
      if ( v )
        *(v++) = value;
      else
      {
        // TODO: out_of_range
      }
    }
    return r;
  }
};

}}}

#endif
