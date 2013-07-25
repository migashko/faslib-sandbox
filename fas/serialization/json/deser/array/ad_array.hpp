#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_ARRAY_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_ARRAY_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parse;
using ::fas::serialization::deser::parse_if;
using ::fas::serialization::deser::target;
//using ::fas::serialization::deser::ad_entity;
using ::fas::serialization::deser::ad_entity2;

struct ad_array: ad_entity2< type_list_n<
  parse_if< ::fas::json::parse::_left_bracket_>,
  target,
  parse< ::fas::json::parse::_right_bracket_>
>::type >
{};

}}}

#endif
