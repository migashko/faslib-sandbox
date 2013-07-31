#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_LIST_SMART_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_LIST_SMART_HPP


#include <fas/serialization/deser/ad_sequence_smart.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace deser{

//using ::fas::serialization::deser::ad_sequence;
//using ::fas::serialization::deser::sequence;

/*
struct ad_field_list_smart:
  ad_sequence<
    sequence::smart,
    ::fas::json::parse::_right_brace_
  >
{};
*/
}}}

/*
#include <fas/serialization/deser/ad_smart.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::ad_smart;

struct ad_field_list_smart:
  ad_smart<
    _tag_,
    ::fas::json::parse::_object_field_,
    ::fas::json::parse::_right_brace_
  >
{};

}}}
*/
#endif
