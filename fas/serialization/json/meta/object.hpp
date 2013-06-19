#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/typemanip/if_c.hpp>
#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/empty_list.hpp>
#include <fas/range.hpp>

namespace fas{ namespace json{

template< typename TargetList>
struct field_list
{
  typedef typename normalize<TargetList>::type target_list;
  typedef _field_list_ tag;
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
};

template< typename Target>
struct sequence_items
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef Target target;
  typedef _sequence_items_ tag;
};

template< typename TargetList>
struct array_list
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef TargetList target_list;
  typedef _array_list_ tag;
};


template< typename Target, bool Clear = true>
struct range
{
  typedef Target target;
  typedef _access_ tag;
  
  template<typename V>
  typename typerange<V>::orange operator()(reference_wrapper<V> v) const
  {
    return orange(v.get(), Clear);
  }

  template<typename V>
  typename typerange<V>::range operator()(reference_wrapper<const V> v) const
  {
    return range(v.get());
  }
};

template< typename Target >
struct array
{
  // typedef typename normalize<TargetList>::type targets;
  /*typedef typename if_c<
    is_type_list<TargetList>::value,
    field_list<TargetList>,
    TargetList
  >::type targets;
  */
  typedef sequence_items< Target > target;

  typedef _array_ tag;
};


}}

#endif
