#ifndef FAS_SERIALIZATION_JSON_META_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_META_INTEGER_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/optional.hpp>

namespace fas{ namespace json{

template<typename Target = optional>
struct integer
{
  typedef Target target;
  typedef _integer_ tag;
};

}}

#endif
