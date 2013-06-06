#ifndef FAS_SERIALIZATION_JSON_META_ACC_HPP
#define FAS_SERIALIZATION_JSON_META_ACC_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace json{

template<typename Accessor, typename TargetList>
struct acc: Accessor
{
  typedef typename normalize<TargetList>::type targets;
  typedef _access_ tag;
};

}}

#endif
