#ifndef FAS_SERIALIZATION_JSON_META_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_META_INTEGER_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace json{

template<typename ProvalList = empty_list>
struct integer
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef _integer_ tag;
};


}}

#endif
