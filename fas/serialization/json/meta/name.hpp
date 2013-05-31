#ifndef FAS_SERIALIZATION_JSON_META_NAME_HPP
#define FAS_SERIALIZATION_JSON_META_NAME_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

template<typename Name>
struct name: Name
{
  typedef _name_ tag;
};

}}

#endif
