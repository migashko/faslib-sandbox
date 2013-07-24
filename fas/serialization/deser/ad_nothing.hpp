#ifndef FAS_SERIALIZATION_DESER_AD_NOTHING_HPP
#define FAS_SERIALIZATION_DESER_AD_NOTHING_HPP

#include <fas/range/orange.hpp>
#include <fas/typemanip/reference_wrapper.hpp>

namespace fas{ namespace serialization{ namespace deser{


struct ad_nothing
{
  template<typename T, typename J, typename V>
  void operator()(T&, J, V&) 
  {
    
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T&, J, V&, R r)
  {
    return r;
  }
};

}}}

#endif
