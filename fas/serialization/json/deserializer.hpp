#ifndef FAS_SERIALIZATION_JSON_DESERIALIZER_HPP
#define FAS_SERIALIZATION_JSON_DESERIALIZER_HPP

#include <fas/serialization/except/aspect.hpp>
#include <fas/serialization/proval/aspect.hpp>
#include <fas/serialization/json/deser/aspect.hpp>
#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/serialization/deserializer.hpp>

#include <fas/aop/aspect_merge.hpp>

namespace fas{ namespace json{

struct deserializer_aspect: aspect< type_list_n<
    deser::aspect,
    parse::aspect,
    ::fas::serialization::proval::aspect,
    ::fas::serialization::except::aspect
>::type > {};
  
template<
  typename A1 = empty_type/*,
  typename A2 = empty_type,
  typename A3 = empty_type,
  typename A4 = empty_type,
  typename A5 = empty_type
  */
>
class deserializer:
  public ::fas::serialization::deserializer<
    //TODO: допилить aspect_merge, чтоб не делал список из одного аспекта
    typename aspect_merge<A1,deserializer_aspect>::type
  >
{
  
};

}}

#endif
