#ifndef FAS_SERIALIZATION_JSON_META_OPTIONAL_HPP
#define FAS_SERIALIZATION_JSON_META_OPTIONAL_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{
  

struct optional
{
  typedef _optional_ tag;
};

}}

#endif
