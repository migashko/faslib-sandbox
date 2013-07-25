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

namespace fas{ namespace json{

using ::fas::serialization::container;

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
  typedef _insert_ tag;
};


///
/// parser
///
  
struct ignore_field
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_object_field_ parser_tag;
};

struct ignore_item
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_array_item_ parser_tag;
};

struct ignore_string
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_string_ parser_tag;
};

struct ignore_bool
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_boolean_ parser_tag;
};

struct ignore_null
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_null_ parser_tag;
};

struct ignore_array
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_array_ parser_tag;
};

struct ignore_object
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_object_ parser_tag;
};

struct ignore_value
{
  typedef _parser_ tag;
  typedef ::fas::json::parse::_value_ parser_tag;
};

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
  struct string_helper{ typedef _string_helper_ tag; };

  typedef type_list<string_helper> target_list;
  
  typedef _string_content_ tag;
  
  // Костыль - должн быть exception (типа invalid_string)
  typedef ignore_field alt_target; // TODO:
};


template<typename ProvalList = empty_list>
struct string
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef container< string_content > target;
  typedef _string_ tag;
};

template<typename Target, typename ProvalList = empty_list>
struct string_ex
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef Target target;
  typedef _string_ tag;
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
  typedef _attr_ tag;
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
};

// array

template< typename Target>
struct item
{
  typedef Target target;
  typedef _item_ tag;
};

template<typename TargetList, typename Alt = ignore_item>
struct sequence_items
{
  typedef typename normalize<TargetList>::type target_list;
  typedef _sequence_items_ tag;
  typedef Alt alt_target;
};


// сделать Вторым параметром список целей, пост условий
template< typename Target >
struct array
{
  typedef container< sequence_items< element< item< Target > > > > target;

  typedef _array_ tag;
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
