#ifndef FAS_SERIALIZATION_DESER_AD_ACCESS_HPP
#define FAS_SERIALIZATION_DESER_AD_ACCESS_HPP

#include <fas/range/orange.hpp>
#include <fas/typemanip/reference_wrapper.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgNext>
struct ad_access
{
  typedef TgNext _tag_;
  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    t.get_aspect().template get<_tag_>()(t, J(), J()(v));
  }
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    //std::cout << "ad_access" << std::endl;
    return t.get_aspect().template get<_tag_>()(t, J(), J()(v), r);
  }
};

}}}

#endif
