#ifndef FAS_SERIALIZATION_JSON_DESER_SIMPLE_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_SIMPLE_ASPECT_HPP

#include <fas/serialization/json/deser/simple/ad_integer.hpp>
#include <fas/serialization/json/deser/simple/tags.hpp>

#include <fas/aop.hpp>

namespace fas{ namespace json{ namespace deser{ namespace simple{

struct aspect: ::fas::aspect< type_list_n<
  advice< _integer_, ad_integer>
>::type >
{};

}}}}

#endif
