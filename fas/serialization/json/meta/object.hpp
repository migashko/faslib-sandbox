#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace json{

template< typename TargetList>
struct object
{
  typedef typename normalize<TargetList>::type targets;
  typedef _object_ tag;
};

}}

#endif
