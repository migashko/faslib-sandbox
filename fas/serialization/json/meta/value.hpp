#ifndef FAS_SERIALIZATION_JSON_META_VALUE_HPP
#define FAS_SERIALIZATION_JSON_META_VALUE_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace json{

template< typename TargetList>
struct value
{
  typedef typename normalize<TargetList>::type targets;
  typedef _value_ tag;
};

}}

#endif
