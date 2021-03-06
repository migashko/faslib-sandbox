#ifndef FAS_SERIALIZATION_JSON_META_STRING_HPP
#define FAS_SERIALIZATION_JSON_META_STRING_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>
#include <fas/typemanip/empty_type.hpp>

#include <fas/serialization/json/meta/optional.hpp>

namespace fas{ namespace json{

template<typename ProvalList = empty_list>
struct string
{
  typedef container< string_content > target;
  typedef typename normalize<ProvalList>::type proval_list;
  typedef _string_ tag;
};

}}

#endif
