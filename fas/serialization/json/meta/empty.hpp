#ifndef FAS_SERIALIZATION_JSON_META_EMPTY_HPP
#define FAS_SERIALIZATION_JSON_META_EMPTY_HPP

//#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>

//#include <fas/serialization/json/meta/metalist.hpp>

namespace fas{ namespace json{

struct empty
{
  //typedef metalist::number metatype;
  //typedef ser::_integer_ serializer_tag;
  typedef deser::_empty_ deserializer_tag;
};

}}

#endif
