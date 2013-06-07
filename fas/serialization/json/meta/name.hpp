#ifndef FAS_SERIALIZATION_JSON_META_NAME_HPP
#define FAS_SERIALIZATION_JSON_META_NAME_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace json{

template<typename Name>
struct name: Name
{
  // typedef empty_list targets;
  typedef _name_ tag;
};

}}

#endif
