#ifndef FAS_SERIALIZATION_JSON_META_SEQUENCE_HPP
#define FAS_SERIALIZATION_JSON_META_SEQUENCE_HPP

#include <fas/typemanip/reference_wrapper.hpp>
#include <fas/range/typerange.hpp>
#include <fas/range/range.hpp>
#include <fas/range/orange.hpp>

namespace fas{ namespace json{

template< typename Target, typename Tg>
struct sequence
{
  typedef Target target;
  typedef Tg tag;

  
  template<typename V>
  typename typerange<V>::orange operator()( reference_wrapper<V> v ) const
  {
    return orange( v.get() );
  }
  

  /*
  template<typename V>
  typename typerange<V>::range operator()( reference_wrapper<const V> v ) const
  {
    return range(v.get());
  }
  */
};

}}

#endif
