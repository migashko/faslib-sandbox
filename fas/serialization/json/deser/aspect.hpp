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

#include <fas/serialization/deser/ad_deser.hpp>
#include <fas/serialization/deser/ad_target_n.hpp>
//#include <fas/serialization/deser/ad_utf8_letter.hpp>
#include <fas/serialization/deser/ad_value.hpp>
#include <fas/serialization/deser/ad_target.hpp>
#include <fas/serialization/deser/ad_access.hpp>
//#include <fas/serialization/deser/sequence/sequence.hpp>
#include <fas/serialization/deser/ad_brute_list.hpp>
#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/deser/sequence/ad_sequence_each.hpp>
#include <fas/serialization/deser/ad_tstring.hpp>
#include <fas/serialization/deser/ad_nothing.hpp>
#include <fas/serialization/deser/ad_parser.hpp>


#include <fas/serialization/deser/ad_value2range.hpp>
#include <fas/serialization/deser/ad_push2range.hpp>
#include <fas/serialization/deser/ad_process_or_parse.hpp>
#include <fas/serialization/deser/target_list/ad_least_once.hpp>
#include <fas/serialization/json/parse/tags.hpp>


/// ////////////////////////
#include <fas/serialization/json/deser/array/aspect.hpp>
#include <fas/serialization/json/deser/object/aspect.hpp>


namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::parser;
using ::fas::serialization::deser::deser;

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

struct ad_string_helper: ::fas::serialization::deser::ad_value2range<_string_content_> {};

// TODO: meta для вставки или back_inserter<string>
// то же для массивов 
// TODO: для всех - reference_wrapper
struct ad_string:
  ::fas::serialization::deser::ad_entity2< type_list_n<
      parser< ::fas::json::parse::_quote_>,
      deser<_string_helper_>,
      parser< ::fas::json::parse::_quote_>
  >::type >
{
};


struct ad_parse_field:
  ::fas::serialization::deser::ad_parser<
    ::fas::json::parse::_object_field_
  >
{};

struct ad_parse_item:
  ::fas::serialization::deser::ad_parser<
    ::fas::json::parse::_array_item_
  >
{};


struct ad_empty
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& , J, V , R r)
  {
    return r;
  }
};


struct _target_list_;
struct _primary_list_;

// advanced
/*
struct ad_array_list:
  ::fas::serialization::deser::ad_sequence_smart<
    ::fas::serialization::deser::sequence::smart
    _tag_,
    ::fas::json::parse::_array_item_,
    ::fas::json::parse::_right_bracket_
  >
{};
*/



struct aspect:
  ::fas::aspect< type_list_n<
    array::aspect,
    object::aspect,
    advice< _jstring_,     ad_jstring >,
    advice< _optional_,    ::fas::serialization::deser::ad_nothing>,
    advice< _parse_field_, ad_parse_field >,
    advice< _parse_item_, ad_parse_item>,
    //advice< _field_,    ad_field >,
    //advice< _array_list_, ad_array_list>,
    alias<  _prop_, _field_>,
    alias<  _attr_, _field_>,
    advice< _target_, ::fas::serialization::deser::ad_target >,
    advice< _tag_, ::fas::serialization::deser::ad_tag >,
    advice< _value_,       ::fas::serialization::deser::ad_value >,
    advice< _access_,        ::fas::serialization::deser::ad_access<_target_> >,
    advice< _string_helper_,  ad_string_helper >,
    advice< _string_content_, ad_string_content >,
    advice< _string_,         ad_string >,
    advice< _error_, ad_parse_error >,
    advice< _integer_,        ::fas::serialization::deser::ad_integer >,
    advice< _tstring_,    ::fas::serialization::deser::ad_tstring>,
    type_list_n<
      advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser >,
      value_advice< ::fas::serialization::_status_, bool>,
      advice< _empty_, ad_empty>,
//      advice< _push2range_, ::fas::serialization::deser::ad_push2range< _target_ > >,
//      advice< _value2range_, ::fas::serialization::deser::ad_value2range< _target_ > >,
      advice< _push2range_, ::fas::serialization::deser::ad_push2range2 >,
      advice< _value2range_, ::fas::serialization::deser::ad_value2range2 >,
      advice< _least_once_, ::fas::serialization::deser::ad_least_once<_target_> >
    >::type
  >::type >
{};

}}}

#endif
