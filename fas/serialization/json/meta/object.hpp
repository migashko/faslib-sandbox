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
#include <fas/serialization/json/meta/field_list.hpp>
#include <fas/serialization/json/meta/element.hpp>
#include <fas/serialization/json/meta/parse.hpp>
#include <fas/serialization/json/meta/ignore.hpp>
#include <fas/serialization/json/meta/string_content.hpp>
#include <fas/serialization/json/meta/string.hpp>
#include <fas/serialization/json/meta/string_ex.hpp>
#include <fas/serialization/json/meta/equal_content.hpp>
#include <fas/serialization/json/meta/equal_string.hpp>
#include <fas/serialization/json/meta/base.hpp>
#include <fas/serialization/json/meta/item.hpp>
#include <fas/serialization/json/meta/item_sequence.hpp>



#include <fas/serialization/tags.hpp>
#include <fas/serialization/deser/tags.hpp>

// ---

namespace fas{ namespace json{




template< typename FieldList = empty_list, typename Alt = ignore_field >
struct object
{
  typedef field_list<FieldList,  Alt> target;
  /*
  typedef typename if_c< 
    is_type_list<TargetList>::value, 
    
    field_list<TargetList,  Alt>, 
    TargetList 
  >::type target;*/
  
  typedef _object_ tag;

};

template< typename Target>
struct object_ex
{
  typedef Target target;
  
  typedef _object_ tag;

};


// сделать Вторым параметром список целей, пост условий
template< typename Target, typename Alt = ignore_item >
struct array
{
  //typedef container< item_sequence_ex< element< item< Target > > > > target;
  typedef container< item_sequence< Target, Alt > > target;

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
