#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/typemanip/if_c.hpp>
#include <fas/typemanip/member.hpp>
#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/empty_list.hpp>
#include <fas/type_list/type_list_n.hpp>
#include <fas/range.hpp>

#include "sequence.hpp"

#include <fas/serialization/json/parse/tags.hpp>

// ---
#include <fas/serialization/meta/container.hpp>

namespace fas{ namespace json{

using ::fas::serialization::container;

}}

#include <fas/serialization/json/meta/acc.hpp>
#include <fas/serialization/json/meta/field.hpp>
#include <fas/serialization/json/meta/element.hpp>
#include <fas/serialization/json/meta/parse.hpp>
#include <fas/serialization/json/meta/ignore.hpp>
#include <fas/serialization/json/meta/string_content.hpp>
#include <fas/serialization/json/meta/string.hpp>
#include <fas/serialization/json/meta/string_ex.hpp>
#include <fas/serialization/json/meta/equal_content.hpp>
#include <fas/serialization/json/meta/equal_string.hpp>
#include <fas/serialization/json/meta/base.hpp>



#include <fas/serialization/tags.hpp>
#include <fas/serialization/deser/tags.hpp>

// ---

namespace fas{ namespace json{


template< typename TargetList, typename Alt = ignore_field>
struct field_list
{
  // TODO: list categories
  typedef typename normalize<TargetList>::type target_list;
  typedef _field_list_smart_ tag;
  typedef Alt alt_target; // TODO: 
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

};

/*
template<typename Obj>
struct base
  : Obj::target::target_list
{
};
*/

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
    parse_skip< ::fas::json::parse::_space_>,
    Target,  // Убрать target, вставить реальный Target
    parse_skip< ::fas::json::parse::_space_>,
    parse_skip< ::fas::json::parse::_sequence_separator_>
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
    parse_skip_if< ::fas::json::parse::_left_bracket_>,
    target,  
    parse_skip< ::fas::json::parse::_right_bracket_>
  >::type entity_list;

};


template< typename TargetList>
struct item_list
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef TargetList target_list;
  typedef _item_list_ tag;
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
