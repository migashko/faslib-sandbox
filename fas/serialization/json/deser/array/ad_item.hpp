#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_ITEM_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_ITEM_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parse;
using ::fas::serialization::deser::target;
//using ::fas::serialization::deser::ad_entity;
using ::fas::serialization::deser::ad_entity2;

struct ad_item: ad_entity2< type_list_n<
  parse< ::fas::json::parse::_space_>,
  target,
  parse< ::fas::json::parse::_space_>,
  parse< ::fas::json::parse::_sequence_separator_>
>::type >
{};

}}}

#endif
