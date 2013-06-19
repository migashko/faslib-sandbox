#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list.hpp>
#include <fas/integral/int_.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/deser/tags.hpp>
#include <fas/serialization/deser/ad_integer.hpp>
#include <fas/serialization/deser/ad_helper.hpp>
#include <fas/serialization/deser/ad_helper_list.hpp>

#include <fas/serialization/json/deser/ad_integer.hpp>
#include <fas/serialization/json/deser/ad_name.hpp>
#include <fas/serialization/json/deser/ad_field.hpp>

#include <fas/serialization/deser/ad_deser.hpp>
#include <fas/serialization/deser/ad_target_n.hpp>
#include <fas/serialization/deser/ad_utf8_letter.hpp>
#include <fas/serialization/deser/ad_value.hpp>
#include <fas/serialization/deser/ad_target.hpp>
#include <fas/serialization/deser/ad_access.hpp>
#include <fas/serialization/deser/ad_smart.hpp>
#include <fas/serialization/deser/ad_brute_list.hpp>
#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/deser/ad_sequence.hpp>
#include <fas/serialization/deser/ad_equal_range.hpp>
#include <fas/serialization/json/parse/tags.hpp>


namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parser;
// using ::fas::serialization::deser::ad_sequence;
// using ::fas::serialization::deser::ad_sequence;

struct _string_helper_;
struct _string_content_;
struct _string_content_variant_;
struct _utf8_letter_;
struct _error_;

struct ad_parse_error
{
  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return fas::throw_< fas::serialization::_except_ >(t, fas::serialization::parse_error( fas::distance(rr.first)  ), rr );
  }
};


struct ad_string_content:
  ::fas::serialization::deser::ad_parse_copy2range< type_list_n<
    ::fas::json::parse::_utf8_letter_
  >::type, ::fas::json::parse::_quote_ >
{};

/*
struct ad_string_content_variant:
  ::fas::serialization::deser::ad_entity< type_list_n<
    parser< ::fas::json::parse::_utf8_letter_>
  >::type, true >
{};


struct ad_string_content:
  ::fas::serialization::deser::ad_sequence<
    _string_content_variant_, 
    _error_,  
    ::fas::json::parse::_quote_ 
  >
{};*/


struct ad_string_helper: ::fas::serialization::deser::ad_back_inserter<_string_content_> {};

//struct ad_string_helper: ad_string_content {};

// TODO: meta для вставки или back_inserter<string>
// то же для массивов 
// TODO: для всех - reference_wrapper
struct ad_string:
  ::fas::serialization::deser::ad_entity< type_list_n<
      parser< ::fas::json::parse::_quote_>,
      //_string_helper_,
      _string_content_,
      parser< ::fas::json::parse::_quote_>
  >::type >
{
};

struct _target_list_;
struct _primary_list_;
struct _target_;
struct _tag_;
struct _first_target_;
struct _second_target_;
//struct _sequence_items_;



/*
struct ad_field:
  ::fas::serialization::deser::ad_separate<
    _field_name_,
    ::fas::json::parse::_colon_,
    _field_value_
  >
{};
*/


// array

struct ad_item:
  ::fas::serialization::deser::ad_entity< type_list_n<
    parser< ::fas::json::parse::_space_>,
    _target_,
    parser< ::fas::json::parse::_space_>,
    parser< ::fas::json::parse::_sequence_separator_>
  >::type >
{};

struct ad_sequence_items:
  ::fas::serialization::deser::ad_sequence<
    _item_,
    ::fas::json::parse::_array_item_,
    ::fas::json::parse::_right_bracket_
  >    
{};

struct ad_array:
  ::fas::serialization::deser::ad_entity< type_list_n<
      parser< ::fas::json::parse::_left_bracket_>,
      _target_,
      parser< ::fas::json::parse::_right_bracket_>
   >::type >
{};

// advanced

struct ad_array_list:
  ::fas::serialization::deser::ad_smart<
    _tag_,
    ::fas::json::parse::_array_item_,
    ::fas::json::parse::_right_bracket_
  >
{};


// object

struct ad_field:
  ::fas::serialization::deser::ad_entity< type_list_n<
    parser< ::fas::json::parse::_space_>,
    _first_target_,
    parser< ::fas::json::parse::_space_>,
    parser< ::fas::json::parse::_colon_>,
    parser< ::fas::json::parse::_space_>,
    _second_target_,
    parser< ::fas::json::parse::_space_>,
    parser< ::fas::json::parse::_sequence_separator_>
  >::type >
{};


struct ad_field_list:
  ::fas::serialization::deser::ad_smart<
    _tag_,
    ::fas::json::parse::_object_field_,
    ::fas::json::parse::_right_brace_
  >
{};

struct ad_object:
  ::fas::serialization::deser::ad_entity< type_list_n<
    parser< ::fas::json::parse::_left_brace_>,
    _target_,
    parser< ::fas::json::parse::_right_brace_>
   >::type >
{};


struct aspect:
  ::fas::aspect< type_list_n<
    advice< _name_,     ad_name >,
    advice< _field_,    ad_field >,
    advice< _array_, ad_array >,
    advice< _array_list_, ad_array_list>,
    alias<  _prop_, _field_>,
    alias<  _attr_, _field_>,
    advice< _field_list_, ad_field_list >,
    advice< _item_, ad_item >,
    // alias<  _value_, _target_list_>,
    advice< _object_, ad_object >,
    advice< _target_, ::fas::serialization::deser::ad_target >,
    advice< _tag_, ::fas::serialization::deser::ad_tag >,
    advice< _value_,       ::fas::serialization::deser::ad_value >,
    advice< _access_,        ::fas::serialization::deser::ad_access >,
    advice< _string_helper_,  ad_string_helper >,
    advice< _string_content_, ad_string_content >,
//    advice< _string_content_variant_, ad_string_content_variant >,
    advice< _string_,         ad_string >,
    advice< _error_, ad_parse_error >,
    advice< _integer_,        ::fas::serialization::deser::ad_integer >,
    advice< _equal_range_,    ::fas::serialization::deser::ad_equal_range>,
    advice< _first_target_,     ::fas::serialization::deser::ad_target_n<int_<0> > >,
    advice< _second_target_,    ::fas::serialization::deser::ad_target_n<int_<1> > >,
    // Перенести в serializer
    advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser/*<_target_list_>*/ >,
    value_advice< ::fas::serialization::_status_, bool>,
    advice< _sequence_items_, ad_sequence_items >
  >::type >
{};

}}}

#endif
