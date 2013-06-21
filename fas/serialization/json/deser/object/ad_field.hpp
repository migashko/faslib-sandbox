#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/json/deser/object/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parser;
using ::fas::serialization::deser::ad_entity;

struct ad_field:
  ad_entity< type_list_n<
    parser< ::fas::json::parse::_space_>,
    _field_key_,
    parser< ::fas::json::parse::_space_>,
    parser< ::fas::json::parse::_colon_>,
    parser< ::fas::json::parse::_space_>,
    _field_value_,
    parser< ::fas::json::parse::_space_>,
    parser< ::fas::json::parse::_sequence_separator_>
  >::type >
{};

}}}

#endif
