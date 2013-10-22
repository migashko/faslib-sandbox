#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list.hpp>
#include <fas/integral/int_.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/deser/tags.hpp>
#include <fas/serialization/deser/ad_integer.hpp>
#include <fas/serialization/deser/ad_parser.hpp>

// #include <fas/serialization/json/deser/ad_integer.hpp>
// #include <fas/serialization/json/deser/ad_jstring.hpp>

#include <fas/serialization/deser/aspect.hpp>
#include <fas/serialization/deser/ad_deser.hpp>
//#include <fas/serialization/deser/ad_target_n.hpp>
//#include <fas/serialization/deser/ad_utf8_letter.hpp>
#include <fas/serialization/deser/ad_value.hpp>
//#include <fas/serialization/deser/ad_target.hpp>
#include <fas/serialization/deser/ad_access.hpp>
//#include <fas/serialization/deser/sequence/sequence.hpp>
//#include <fas/serialization/deser/ad_brute_list.hpp>
#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/deser/ad_sequence_each.hpp>
#include <fas/serialization/deser/ad_equal_content.hpp>
//#include <fas/serialization/deser/ad_nothing.hpp>
#include <fas/serialization/deser/ad_parser.hpp>


#include <fas/serialization/deser/ad_container.hpp>
#include <fas/serialization/deser/ad_element.hpp>
//#include <fas/serialization/deser/ad_process_or_parse.hpp>
//#include <fas/serialization/deser/target_list/ad_least_once.hpp>
#include <fas/serialization/json/parse/tags.hpp>


/// ////////////////////////
//#include <fas/serialization/json/deser/array/aspect.hpp>
//#include <fas/serialization/json/deser/object/aspect.hpp>

#include <fas/serialization/except/parse_error.hpp>


#include <fas/serialization/json/deser/ad_object.hpp>
#include <fas/serialization/json/deser/ad_field.hpp>
#include <fas/serialization/json/deser/ad_string_content.hpp>
#include <fas/serialization/json/deser/ad_string.hpp>

namespace fas{ namespace json{ namespace deser{

//using ::fas::serialization::deser::parse;
///using ::fas::serialization::deser::deser;

/*
struct _string_content_variant_;
struct _utf8_letter_;
struct _error_;
struct _empty_;
struct _item_impl_;
*/
/*
struct ad_parse_error
{
  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return fas::throw_< fas::serialization::_except_ >(t, fas::serialization::parse_error( fas::distance(rr.first)  ), rr );
  }
};
*/
/*
struct ad_empty
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& , J, V , R r)
  {
    return r;
  }
};*/


//struct _target_list_;
//struct _primary_list_;

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


struct ad_name
{
  template<typename T, typename J, typename V>
  void operator()(T& /*t*/, J, V& /*v*/)
  {
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V&, R r)
  {
    return _(t, J()(), r);
  }
  
private:
  template<typename T, typename RN, typename R>
  R _(T& t, RN rn, R r)
  {
    using ::fas::serialization::_status_;
    t.get_aspect().template get<_status_>() = false;
    R orig = r;
    if ( *r != '"' )
      return orig;
    ++r;
    for (;r && rn && *r==*rn; ++r, ++rn);
    
    if ( !r || *r!='"' || ( rn && *rn!='\0') )
      return orig;
    ++r;
    t.get_aspect().template get<_status_>() = true;
    return r;
  }
};

struct aspect:
  ::fas::aspect< type_list_n<
    //array::aspect,
    alias<_item_,  ::fas::serialization::_entity_>,
    alias<_array_, ::fas::serialization::_entity_>,
    alias<_sequence_items_, ::fas::serialization::_sequence_each_>,

    // object::aspect,
    advice<_name_, ad_name>,
    //alias<_field_,  ::fas::serialization::_entity_>,
    advice<_field_,  ad_field>,
    alias<_field_list_smart_, ::fas::serialization::_sequence_smart_ >,
    //alias<_object_, ::fas::serialization::_entity_>,
    advice<_object_, ad_object>,
    alias< _ignore_, ::fas::serialization::deser::_parse_skip_>,
    //alias< _string_content_,  ::fas::serialization::_sequence_each_ >,
    advice< _string_content_,  ad_string_content >,
    advice< _string_,  ad_string >,
    //alias< _string_,         ::fas::serialization::_entity_ >,
    type_list_n<
      advice< _value_,       ::fas::serialization::deser::ad_value >,
      advice< _access_,        ::fas::serialization::deser::ad_access >,
      advice< _integer_,        ::fas::serialization::deser::ad_integer >,
      advice< _equal_content_,    ::fas::serialization::deser::ad_equal_content>,
      advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser >,
      advice< _element_, ::fas::serialization::deser::ad_element >,
      advice< _container_, ::fas::serialization::deser::ad_container >
    >::type
  >::type >
{};

}}}

#endif
