#ifndef FAS_SERIALIZATION_JSON_META_IGNORE_HPP
#define FAS_SERIALIZATION_JSON_META_IGNORE_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

struct ignore_field: parse_skip_if< ::fas::json::parse::_object_field_ >{};

struct ignore_item: parse_skip_if< ::fas::json::parse::_array_item_ >{};

struct ignore_string: parse_skip_if< ::fas::json::parse::_string_ >{};

struct ignore_boolean: parse_skip_if< ::fas::json::parse::_boolean_ >{};

struct ignore_null: parse_skip_if< ::fas::json::parse::_null_ >{};

struct ignore_array: parse_skip_if< ::fas::json::parse::_array_ >{};

struct ignore_object: parse_skip_if< ::fas::json::parse::_object_ >{};

struct ignore_value: parse_skip_if< ::fas::json::parse::_value_ >{};

}}

#endif
