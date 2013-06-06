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
#include <fas/serialization/deser/ad_peek_and_parse.hpp>
#include <fas/serialization/deser/ad_parse.hpp>
#include <fas/serialization/deser/ad_target_n.hpp>
#include <fas/serialization/deser/ad_utf8_letter.hpp>
#include <fas/serialization/deser/ad_target_list.hpp>
#include <fas/serialization/deser/ad_targets.hpp>
#include <fas/serialization/deser/ad_access.hpp>
#include <fas/serialization/deser/ad_primary_list.hpp>
#include <fas/serialization/deser/ad_enclosed.hpp>
#include <fas/serialization/deser/ad_equal_range.hpp>
#include <fas/serialization/json/parse/tags.hpp>


namespace fas{ namespace json{ namespace deser{

struct _string_helper_;
struct _string_content_;
struct _utf8_letter_;

struct ad_string_content:
  ::fas::serialization::deser::ad_helper_list< type_list_n<
    ::fas::json::parse::_utf8_letter_
  >::type, ::fas::json::parse::_quote_ >
{};

struct ad_string_helper: ::fas::serialization::deser::ad_helper<_string_content_> {};

struct ad_string:
  ::fas::serialization::deser::ad_enclosed< 
      ::fas::json::parse::_quote_,
      _string_helper_,
      ::fas::json::parse::_quote_
  >
{
};

struct _target_list_;
struct _primary_list_;
struct _targets_;

struct ad_field_list: 
  ::fas::serialization::deser::ad_primary_list< 
    ::fas::json::parse::_comma_, 
    ::fas::json::parse::_object_field_, 
    ::fas::json::parse::_right_brace_ 
  > 
{};



struct ad_item_list: 
  ::fas::serialization::deser::ad_primary_list< 
    ::fas::json::parse::_comma_, 
    ::fas::json::parse::_value_, 
    ::fas::json::parse::_right_brace_ 
  > 
{};

struct ad_object: 
  ::fas::serialization::deser::ad_enclosed<
      ::fas::json::parse::_left_brace_,
      /*_field_list_*/_targets_,
      ::fas::json::parse::_right_brace_
   >
{};


struct aspect:
  ::fas::aspect< type_list_n<
  
    //advice< _integer_,  ad_integer >,
    advice< _name_,     ad_name >,
    advice< _field_,    ad_field >,
    
    alias<  _prop_, _field_>,
    alias<  _attr_, _field_>,

    advice< _field_list_, ad_field_list >,
    advice< _item_list_, ad_item_list >,
    alias<  _value_, _field_list_>,
    //advice< _object_, fas::serialization::deser::ad_targets<_object_helper_> >,
    advice< _object_, ad_object >,

    advice< _targets_, ::fas::serialization::deser::ad_targets >,
    advice< _target_list_,       ::fas::serialization::deser::ad_target_list >,
    advice< _access_,        ::fas::serialization::deser::ad_access<_target_list_> >,

    //advice< _utf8_letter_,    ::fas::serialization::deser::ad_utf8_letter >,
    advice< _string_helper_,  ad_string_helper >,
    advice< _string_content_, ad_string_content >,
    advice< _string_,         ad_string >,
    //advice< _left_brace_,  ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_left_brace_> >,
    //advice< _right_brace_, ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_right_brace_> >,
    
    advice< _integer_,        ::fas::serialization::deser::ad_integer >,
    //advice< _quote_,          ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_quote_> >,
    advice< _space_,          ::fas::serialization::deser::ad_parse< ::fas::json::parse::_space_> >,
    advice< _colon_,          ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_colon_> >,
    advice< _equal_range_,    ::fas::serialization::deser::ad_equal_range>,
    advice< _field_name_,     ::fas::serialization::deser::ad_target_n<int_<0> > >,
    advice< _field_value_,    ::fas::serialization::deser::ad_target_n<int_<1> > >,
    
    // Перенести в serializer
    advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser/*<_target_list_>*/ >,
    value_advice< ::fas::serialization::_status_, bool>
  >::type >
{};

}}}

#endif
