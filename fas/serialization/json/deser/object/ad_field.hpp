#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/json/deser/object/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace deser{

//using ::fas::serialization::deser::parse;
//using ::fas::serialization::deser::target_n;
//using ::fas::serialization::deser::ad_entity2;

/*
struct ad_field:
  ad_entity2< type_list_n<
    parse< ::fas::json::parse::_space_>,
    target_n<0>,
    parse< ::fas::json::parse::_space_>,
    parse< ::fas::json::parse::_colon_>,
    parse< ::fas::json::parse::_space_>,
    target_n<1>,
    parse< ::fas::json::parse::_space_>,
    parse< ::fas::json::parse::_sequence_separator_>
  >::type >
{};
*/
}}}

#endif
