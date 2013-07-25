#ifndef FAS_SERIALIZATION_JSON_META_ACC_HPP
#define FAS_SERIALIZATION_JSON_META_ACC_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace json{

template<typename Accessor, typename Target>
struct acc: Accessor
{
  typedef Target target;
  typedef _access_ tag;
};

}}

#endif
