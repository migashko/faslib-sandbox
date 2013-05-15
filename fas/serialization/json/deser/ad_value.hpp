#ifndef FAS_SERIALIZATION_JSON_DESER_AD_VALUE_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_VALUE_HPP

#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/common/deser/ad_integer.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_value
{
  template<typename T, typename M, typename R>
  bool peek(T&, M, R)
  {
    return true;
  }

  template<typename T, typename M, typename V, typename R>
  R operator()(T& , M, V& , R r)
  {
    return r;
  }

private:
};


}}}

#endif
