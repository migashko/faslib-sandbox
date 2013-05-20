#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/serialization/json/deser/simple/aspect.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/json/deser/ad_value.hpp>
#include <fas/serialization/json/deser/ad_empty.hpp>
#include <fas/serialization/json/deser/ad_restriction.hpp>
//#include <fas/serialization/json/deser/ad_space.hpp>

#include <fas/aop.hpp>

namespace fas{ namespace json{ namespace deser{

struct aspect:
  ::fas::aspect< type_list_n<
      //alias< ::fas::serialization::_deser_, _value_>,
      alias< ::fas::serialization::_status_, _status_>,
      value_advice<_status_, bool>//,
      //advice<_value_, ad_value>,
      //advice<_empty_, ad_empty>,
      //advice<_restriction_, ad_restriction>/*,
      //advice<_space_, ad_space>,*/
      //simple::aspect
    >::type >
{};

}}}

#endif
