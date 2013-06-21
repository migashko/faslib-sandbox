#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list.hpp>
#include <fas/integral/int_.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/deser/tags.hpp>
#include <fas/serialization/deser/ad_integer.hpp>
#include <fas/serialization/deser/ad_parse_copy.hpp>

#include <fas/serialization/json/deser/ad_integer.hpp>
#include <fas/serialization/json/deser/ad_jstring.hpp>
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
#include <fas/serialization/deser/ad_tstring.hpp>
#include <fas/serialization/deser/ad_value2range.hpp>
#include <fas/serialization/deser/ad_push2range.hpp>
#include <fas/serialization/deser/ad_process_or_parse.hpp>
#include <fas/serialization/json/parse/tags.hpp>


/// ////////////////////////
#include <fas/serialization/json/deser/array/aspect.hpp>
#include <fas/serialization/json/deser/object/aspect.hpp>


namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parser;

struct _string_helper_;
struct _string_content_;
struct _string_content_variant_;
struct _utf8_letter_;
struct _error_;
struct _empty_;
struct _item_impl_;

struct ad_parse_error
{
  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return fas::throw_< fas::serialization::_except_ >(t, fas::serialization::parse_error( fas::distance(rr.first)  ), rr );
  }
};


struct ad_string_content:
  ::fas::serialization::deser::ad_parse_copy< type_list_n<
    ::fas::json::parse::_utf8_letter_
  >::type, ::fas::json::parse::_quote_ >
{};


struct _value2range_; // в json

struct ad_empty
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& , J, V , R r)
  {
    return r;
  }
};

struct ad_string_helper: ::fas::serialization::deser::ad_value2range<_string_content_> {};

// TODO: meta для вставки или back_inserter<string>
// то же для массивов 
// TODO: для всех - reference_wrapper
struct ad_string:
  ::fas::serialization::deser::ad_entity< type_list_n<
      parser< ::fas::json::parse::_quote_>,
      _string_helper_,
      parser< ::fas::json::parse::_quote_>
  >::type >
{
};

struct _target_list_;
struct _primary_list_;
//
//struct _tag_;

//struct _field_value_;



// array

/*
template<typename Tg, typename TgParse>
struct ad_process_or_parse
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V v, R r)
  {
    t.get_aspect().template get< ::fas::serialization::_status_>() = true;
    R orig = r;
    r = t.get_aspect().template get<Tg>()(t, J(), v, r);
    if ( !t.get_aspect().template get< ::fas::serialization::_status_>() )
    {
      t.get_aspect().template get< ::fas::serialization::_status_>() = true;
      // TODO: сделать _parse_(t, tag<TgParse>(), r);
      r = t.get_aspect().template get<TgParse>() (t, std::make_pair(orig, mrange(orig)) ).first;
    }
    return r;
  }
};
*/


// struct _process_item_;
/*
struct ad_process_item:
  ::fas::serialization::deser::ad_process_or_parse< _push2range_, ::fas::json::parse::_array_item_>
{};

*/


// struct _process_sequence_items_;
/*struct ad_process_sequence_items:
  ::fas::serialization::deser::ad_sequence<
    _process_item_,
    ::fas::json::parse::_right_bracket_
  >    
{};*/

/*
struct ad_sequence_items:
  ::fas::serialization::deser::ad_value2range<_process_sequence_items_>
{
 
};
*/
/*

struct ad_array:
  ::fas::serialization::deser::ad_entity< type_list_n<
      parser< ::fas::json::parse::_left_bracket_>,
      _target_,
      parser< ::fas::json::parse::_right_bracket_>
   >::type >
{};
*/

// advanced

struct ad_array_list:
  ::fas::serialization::deser::ad_smart<
    _tag_,
    ::fas::json::parse::_array_item_,
    ::fas::json::parse::_right_bracket_
  >
{};


// object
/*
struct ad_field:
  ::fas::serialization::deser::ad_entity< type_list_n<
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
*/
/*
struct ad_field_list_smart:
  ::fas::serialization::deser::ad_smart<
    _tag_,
    ::fas::json::parse::_object_field_,
    ::fas::json::parse::_right_brace_
  >
{};
*/

/*
struct ad_object:
  ::fas::serialization::deser::ad_entity< type_list_n<
    parser< ::fas::json::parse::_left_brace_>,
    _target_,
    parser< ::fas::json::parse::_right_brace_>
   >::type >
{};
*/

struct aspect:
  ::fas::aspect< type_list_n<
    array::aspect,
    object::aspect,
    advice< _jstring_,     ad_jstring >,
    advice< _field_,    ad_field >,
    // advice< _array_, ad_array >,
    advice< _array_list_, ad_array_list>,
    alias<  _prop_, _field_>,
    alias<  _attr_, _field_>,
    //advice< _field_list_smart_, ad_field_list_smart >,
    // advice< _item_, ad_item >,
    //advice< _item_impl_, ad_item_impl >,
    //advice< _value2range_, ad_value2range >,
    // alias<  _value_, _target_list_>,
    //advice< _object_, ad_object >,
    advice< _target_, ::fas::serialization::deser::ad_target >,
    advice< _tag_, ::fas::serialization::deser::ad_tag >,
    advice< _value_,       ::fas::serialization::deser::ad_value >,
    advice< _access_,        ::fas::serialization::deser::ad_access<_target_> >,
    advice< _string_helper_,  ad_string_helper >,
    advice< _string_content_, ad_string_content >,
//    advice< _string_content_variant_, ad_string_content_variant >,
    advice< _string_,         ad_string >,
    advice< _error_, ad_parse_error >,
    advice< _integer_,        ::fas::serialization::deser::ad_integer >,
    advice< _tstring_,    ::fas::serialization::deser::ad_tstring>,
    // advice< _field_key_,     ::fas::serialization::deser::ad_target_n<int_<0> > >,
    // advice< _field_value_,    ::fas::serialization::deser::ad_target_n<int_<1> > >,
    // Перенести в serializer
    type_list_n<
    advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser/*<_target_list_>*/ >,
    value_advice< ::fas::serialization::_status_, bool>,
    //advice< _sequence_items_, ad_sequence_items >,
    // advice< _process_sequence_items_, ad_process_sequence_items >,
    //advice< _sequence_items2_, ad_sequence_items2 >,
    advice< _empty_, ad_empty>,
    // advice< _process_item_, ad_process_item>,
    // advice< _item_assign_, ad_item_assign>,
    advice< _push2range_, ::fas::serialization::deser::ad_push2range< _target_ > >/*,
    advice< _value2range_, ad_value2range< _tag_> >*/
    >::type
  >::type >
{};

}}}

#endif
