#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/typemanip/if_c.hpp>
#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/empty_list.hpp>
#include <fas/range.hpp>

#include "sequence.hpp"

namespace fas{ namespace json{
  

struct parse_field
{
  typedef _parse_field_ tag;
};

struct parse_item
{
  typedef _parse_item_ tag;
};

template< typename TargetList>
struct field_list
{
  // TODO: list categories
  typedef typename normalize<TargetList>::type target_list;
  typedef _field_list_smart_ tag;
  typedef parse_field alt_target; // TODO: 
};


template< typename TargetList = empty_list >
struct object
{
  // typedef typename normalize<TargetList>::type targets;
  typedef typename if_c< 
    is_type_list<TargetList>::value, 
    field_list<TargetList>, 
    TargetList 
  >::type target;
  
  typedef _object_ tag;
};

template< typename Target>
struct item
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef Target target;
  typedef _item_ tag;

  /*
  template<typename R>
  typename R::value_type operator()(R r) const
  {
    return *r;
  }*/
};

/*
struct value2range
{
  typedef _value2range_ tag;
}*/

template< typename TargetList>
struct sequence_items// : sequence<Target, _sequence_items_>
{
  typedef typename normalize<TargetList>::type target_list;
  typedef _sequence_items_ tag;

  typedef parse_item alt_target;
  //typedef typename normalize<TargetList>::type target_list;
  /*
  typedef Target target;
  typedef _sequence_items_ tag;
  */
};

// TODO: ограничения на размер контенера
//       container< ..., int_<10> >
template<typename T>
struct container
{
  typedef T target;
  typedef _value2range_ tag;
};

template<typename T>
struct push_back
{
  typedef T target;
  typedef _push2range_ tag;
};

// сделать Вторым параметром список целей, пост условий
template< typename Target >
struct array
{
  typedef container< sequence_items< push_back< item<Target> > > > target;

  typedef _array_ tag;
};


template< typename TargetList>
struct array_list
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef TargetList target_list;
  typedef _array_list_ tag;
};


struct string_helper
{
  typedef _string_helper_ tag;
};

//template<typename TargetList = empty_list>
struct string_content
{
  typedef type_list<string_helper> target_list;
  typedef _string_content_ tag;
  // Костыль - должн быть exception (типа invalid_string)
  typedef parse_field alt_target; // TODO: 
};


template<typename ProvalList = optional>
struct string
{
  typedef container< string_content > target;
  typedef _string_ tag;
};

template<typename Target, typename ProvalList = optional>
struct string_ex
{
  typedef container< Target > target;
  typedef _string_ tag;
};

template<typename TString, typename ProvalList = optional>
struct const_string
{
  // чета типа
  // typedef tstring_content<Target> target;
  typedef _string_ tag;
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
