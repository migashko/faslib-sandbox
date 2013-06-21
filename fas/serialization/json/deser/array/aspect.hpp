#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/deser/array/tags.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/array/ad_array.hpp>

namespace fas{ namespace json{ namespace deser{ namespace array{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _array_, ad_array >
  >::type >
{};

}}}}

#endif
