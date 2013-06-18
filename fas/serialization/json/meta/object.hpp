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
struct item_list
{
  //typedef typename normalize<TargetList>::type target_list;
  typedef Target target;
  typedef _item_list_ tag;
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
  typename typerange<V>::orange& operator()(V& v) const
  {
    static void* _data = 0;
    typedef typename typerange<V>::orange type;
    static type tmp = orange(v, Clear);
    _data = reinterpret_cast<void*>(&tmp);
    return *reinterpret_cast<type*>(_data);
  }

  template<typename V>
  typename typerange<V>::range& operator()(const V& v) const
  {
    return range(v);
  }
private:
  // mutable void* _data;
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
  typedef item_list< Target > target;

  typedef _array_ tag;
};


}}

#endif
