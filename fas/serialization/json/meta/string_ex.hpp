#ifndef FAS_SERIALIZATION_JSON_META_STRING_EX_HPP
#define FAS_SERIALIZATION_JSON_META_STRING_EX_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>
#include <fas/typemanip/empty_type.hpp>

#include <fas/serialization/json/meta/optional.hpp>

namespace fas{ namespace json{

template<typename Target, typename ProvalList = empty_list>
struct string_ex
{
  typedef typename normalize<ProvalList>::type proval_list;
  typedef Target target;
  typedef _string_ tag;
};

}}

#endif
