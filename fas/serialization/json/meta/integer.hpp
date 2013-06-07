#ifndef FAS_SERIALIZATION_JSON_META_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_META_INTEGER_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

//template<typename J = empty_list>
struct integer
{
  typedef _integer_ tag;
};

}}

#endif
