#ifndef FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP
#define FAS_SERIALIZATION_DESER_AD_PUSH2RANGE_HPP

//#include <fas/typemanip/reference_wrapper.hpp>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename Tg>
struct ad_push2range
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    //typedef typename V::type::value_type value_type;
    //value_type value = value_type();
    typedef typename V::value_type value_type;
    value_type value = value_type();
    r = t.get_aspect().template get<Tg>()(t, J(), value, r);
    if ( t.get_aspect().template get<_status_>() )
      *(v++) = value;
    return r;
  }
};


struct ad_push2range2
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    //typedef typename V::type::value_type value_type;
    //value_type value = value_type();
    typedef typename J::target target;
    typedef typename target::tag _tag_;

    typedef typename V::value_type value_type;
    value_type value = value_type();
    r = t.get_aspect().template get<_tag_>()(t, target(), value, r);
    if ( t.get_aspect().template get<_status_>() )
      *(v++) = value;
    return r;
  }
};

}}}

#endif
