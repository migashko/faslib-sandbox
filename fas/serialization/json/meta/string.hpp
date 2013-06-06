#ifndef FAS_SERIALIZATION_JSON_META_STRING_HPP
#define FAS_SERIALIZATION_JSON_META_STRING_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

// template<typename J = empty_list>
struct string
{
  typedef empty_list targets;
  typedef _string_ tag;
};

}}

#endif
