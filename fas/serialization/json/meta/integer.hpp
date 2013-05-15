#ifndef FAS_SERIALIZATION_JSON_META_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_META_INTEGER_HPP

//#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/json/meta/empty.hpp>

//#include <fas/serialization/json/meta/metalist.hpp>

namespace fas{ namespace json{

template<typename J = empty>
struct integer
{
  typedef J target;
  //typedef metalist::number metatype;
  //typedef ser::_integer_ serializer_tag;
  typedef deser::_integer_ deserializer_tag;
};

}}

#endif
