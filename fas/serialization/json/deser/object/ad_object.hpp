#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_OBJECT_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parser;
using ::fas::serialization::deser::ad_entity;

struct ad_object:
  ad_entity< type_list_n<
    parser< ::fas::json::parse::_left_brace_>,
    _target_,
    parser< ::fas::json::parse::_right_brace_>
   >::type >
{};

}}}

#endif
