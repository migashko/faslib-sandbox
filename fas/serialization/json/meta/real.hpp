#ifndef FAS_SERIALIZATION_JSON_META_REAL_HPP
#define FAS_SERIALIZATION_JSON_META_REAL_HPP

#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>

#include <fas/serialization/json/meta/metalist.hpp>

namespace fas{ namespace json{

template<typename ProvalList = empty_list>
struct real
{
  typedef typename normalize<ProvalList>::type proval_list;
  //typedef _real_ tag;
};

}}

#endif
