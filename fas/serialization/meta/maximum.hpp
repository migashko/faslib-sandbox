#ifndef FAS_SERIALIZATION_JSON_META_MAXIMUM_HPP
#define FAS_SERIALIZATION_JSON_META_MAXIMUM_HPP

//#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>

//#include <fas/serialization/json/meta/metalist.hpp>

namespace fas{ namespace json{

template<typename N>
struct maximum
{
  typedef void precondition;
  typedef void postcondition;
  
  template<typename V>
  bool operator() (const V& v) const
  {
    return v >= N::value;
  }
};


}}

#endif
