#ifndef FAS_SERIALIZATION_JSON_META_BASE_HPP
#define FAS_SERIALIZATION_JSON_META_BASE_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

template<typename Obj>
struct base
  : Obj::target::target_list
{
};

}}

#endif
