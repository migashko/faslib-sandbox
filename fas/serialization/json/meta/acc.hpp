#ifndef FAS_SERIALIZATION_JSON_META_ACC_HPP
#define FAS_SERIALIZATION_JSON_META_ACC_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace json{

template<typename Accessor, typename Target>
struct acc: Accessor
{
  typedef Target target;
  typedef _access_ tag;
  /*
  typedef typename Accessor::value_type value_type;

  template<typename V>
  reference_wrapper<value_type> operator()(reference_wrapper<V> v) const
  {
    return ref(Accessor::operator()(v.get()));
  }

  template<typename V>
  reference_wrapper<const value_type> operator()(reference_wrapper<const V> v) const
  {
    return cref(Accessor::operator()(v.get()));
  }
  */
 
};

}}

#endif
