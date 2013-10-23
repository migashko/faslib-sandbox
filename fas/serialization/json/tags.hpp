#ifndef FAS_SERIALIZATION_JSON_TAGS_HPP
#define FAS_SERIALIZATION_JSON_TAGS_HPP

#include <fas/serialization/tags.hpp>

namespace fas{ namespace json{

using ::fas::serialization::_container_;
using ::fas::serialization::_element_;

// Основные общие 
struct _array_;
struct _sequence_items_;
struct _item_;
struct _name_;
struct _equal_content_;
//struct _jstring_;
struct _object_;
struct _parse_field_;
struct _parse_item_;
struct _optional_;
struct _field_;
struct _field_list_;
struct _string_content_;
struct _string_helper_;

// Основные вспомогательные
//struct _target_;
//struct _tag_;
//struct _parser_;
struct _ignore_;
struct _nothing_;

//struct _back_inserter_; // в json

/// old


struct _integer_;
struct _string_;

struct _prop_;
struct _attr_;
struct _access_;


struct _value_;

// struct _field_list_;

struct _inserter_;

struct _item_list_;

}}

#endif
