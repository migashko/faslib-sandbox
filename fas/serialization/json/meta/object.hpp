#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/typemanip/if_c.hpp>
#include <fas/typemanip/member.hpp>
#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/empty_list.hpp>
#include <fas/range.hpp>

#include "sequence.hpp"

#include <fas/serialization/json/parse/tags.hpp>

// ---
#include <fas/serialization/meta/container.hpp>


#include <fas/serialization/tags.hpp>

namespace fas{ namespace json{

using ::fas::serialization::container;
/*
using ::fas::serialization::deser::parse;
using ::fas::serialization::deser::target;
 */ 
}}
// ---

namespace fas{ namespace json{

///
/// common
///

// TODO: ограничения на размер контенера
//       container< ..., int_<10> >

/*
сделать reverse да и все
template<typename T>
struct front_inserter
{
  // TODO:
};
*/


template<typename T>
struct element
{
  typedef T target;
  typedef _element_ tag;
};


///
/// parser
///

template<typename Tg, typename If = false_, typename Copy = false_>
struct parse2
{
  typedef If parse_if;
  typedef Copy copy;
  
  typedef Tg parser_tag;
  typedef _parser_ tag;
};

template<typename Tg>
struct ignore
{
  typedef true_ parse_if;
  typedef false_ copy;

  typedef Tg parser_tag;
  // Это алиас на _parser_, нужен для сериализатора
  typedef _ignore_ tag;
};

struct ignore_field: ignore< ::fas::json::parse::_object_field_ >{};

struct ignore_item: ignore< ::fas::json::parse::_array_item_ >{};

struct ignore_string: ignore< ::fas::json::parse::_string_ >{};

struct ignore_boolean: ignore< ::fas::json::parse::_boolean_ >{};

struct ignore_null: ignore< ::fas::json::parse::_null_ >{};

struct ignore_array: ignore< ::fas::json::parse::_array_ >{};

struct ignore_object: ignore< ::fas::json::parse::_object_ >{};

struct ignore_value: ignore< ::fas::json::parse::_value_ >{};


///
/// basic
///

template<typename ProvalList = empty_list>
struct integer
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef _integer_ tag;
};

template<typename ProvalList = empty_list>
struct real
{
  typedef typename normalize<ProvalList>::type proval_list;
  //typedef _real_ tag;
};

/// string

struct string_content
{
  struct string_helper
  {
    //typedef _string_helper_ tag; 
    
    typedef ::fas::serialization::_entity_piece_ tag; // сделать алиас на _string_helper_
    typedef typename type_list_n<
      parse2< ::fas::json::parse::_utf8_letter_, true_, true_>
    >::type entity_list;
    
  };

  typedef type_list<string_helper> target_list;
  
  typedef _string_content_ tag;
  //typedef ::fas::serialization::_sequence_each_ tag;
  
  // Костыль - должн быть exception (типа invalid_string)
  typedef ignore_field alt_target; // TODO:
  
  typedef ::fas::json::parse::_quote_ stop_tag;
};


template<typename ProvalList = empty_list>
struct string
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef container< string_content > target;
  typedef _string_ tag;
  
  typedef typename type_list_n<
    parse2< ::fas::json::parse::_quote_, true_>,
    target,  
    parse2< ::fas::json::parse::_quote_>
  >::type entity_list;

};

template<typename Target, typename ProvalList = empty_list>
struct string_ex
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef Target target;
  typedef _string_ tag;
  
  typedef typename type_list_n<
    parse2< ::fas::json::parse::_quote_, true_>,
    target,  
    parse2< ::fas::json::parse::_quote_>
  >::type entity_list;
  
};

template<typename TString>
struct equal_content
  : TString
{
  typedef _equal_content_ tag; 
};

template<typename TString>
struct equal_string
  : string_ex< equal_content<TString> >
{
};

/// object

template<typename Name>
struct name: equal_string<Name>
{
};

template<typename Name, typename Value>
struct field
{
  typedef typename type_list_n<Name, Value>::type target_list;
  typedef _field_ tag;
  typedef typename type_list_n</*
    parse2< ::fas::json::parse::_space_>,
    Target,  // Убрать target, вставить реальный Target
    parse2< ::fas::json::parse::_space_>,
    parse2< ::fas::json::parse::_sequence_separator_>
    */
 
    parse2< ::fas::json::parse::_space_>,
    Name,
    parse2< ::fas::json::parse::_space_>,
    parse2< ::fas::json::parse::_colon_>,
    parse2< ::fas::json::parse::_space_>,
    Value,
    parse2< ::fas::json::parse::_space_>,
    parse2< ::fas::json::parse::_sequence_separator_>
 
  >::type entity_list;

};

template<typename TString, typename V, typename VT, VT V::* m, typename Value>
struct mem_field
  : field< name<TString>, acc< member<V, VT, m>, Value> >
{
};


template< typename TargetList, typename Alt = ignore_field>
struct field_list
{
  // TODO: list categories
  typedef typename normalize<TargetList>::type target_list;
  typedef _field_list_smart_ tag;
  typedef ignore_field alt_target; // TODO: 
  typedef ::fas::json::parse::_right_brace_ stop_tag;
};


template< typename TargetList = empty_list >
struct object
{
  typedef typename if_c< 
    is_type_list<TargetList>::value, 
    field_list<TargetList>, 
    TargetList 
  >::type target;
  
  typedef _object_ tag;
  
  typedef typename type_list_n<
    parse2< ::fas::json::parse::_left_brace_, true_>,
    target,  
    parse2< ::fas::json::parse::_right_brace_>
  >::type entity_list;
};

// array

/*
 * struct ad_item: ad_entity2< type_list_n<
  parse< ::fas::json::parse::_space_>,
  target,
  parse< ::fas::json::parse::_space_>,
  parse< ::fas::json::parse::_sequence_separator_>
>::type >
 */

template< typename Target>
struct item
{
  //typedef ::fas::serialization::deser::parse  parse;
  //typedef ::fas::serialization::deser::target target;

  typedef Target target;
  //typedef _item_ tag;
  //typedef ::fas::serialization::_entity3_ tag; // сделать алиас на _item_
  typedef _item_ tag;
  typedef typename type_list_n<
    parse2< ::fas::json::parse::_space_>,
    Target,  // Убрать target, вставить реальный Target
    parse2< ::fas::json::parse::_space_>,
    parse2< ::fas::json::parse::_sequence_separator_>
  >::type entity_list;
};

template<typename TargetList, typename Alt = ignore_item>
struct sequence_items
{
  typedef typename normalize<TargetList>::type target_list;
  //typedef _sequence_items_ tag;
  typedef Alt alt_target;
  
  // TODO: alias на _sequence_items_
  // typedef ::fas::serialization::_sequence_each_ tag;
  typedef _sequence_items_ tag;
  typedef ::fas::json::parse::_right_bracket_ stop_tag;

};


// сделать Вторым параметром список целей, пост условий
template< typename Target >
struct array
{
  typedef container< sequence_items< element< item< Target > > > > target;

  typedef _array_ tag;

  
  typedef typename type_list_n<
    parse2< ::fas::json::parse::_left_bracket_, true_>,
    target,  
    parse2< ::fas::json::parse::_right_bracket_>
  >::type entity_list;

};


template< typename TargetList>
struct array_list
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef TargetList target_list;
  typedef _array_list_ tag;
};




/*
template< typename Target, bool Clear = true>
struct range
{
  typedef Target target;
  typedef _access_ tag;
  
  template<typename V>
  typename typerange<V>::orange operator()(reference_wrapper<V> v) const
  {
    typename typerange<V>::orange tmp = orange(v.get(), Clear);
    *tmp = "aaaa";
    return tmp;
  }
};
*/


}}

#endif
