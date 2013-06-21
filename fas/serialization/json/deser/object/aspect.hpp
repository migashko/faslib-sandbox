#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/deser/object/tags.hpp>
#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{ namespace deser{ namespace object{

struct aspect:
  ::fas::aspect< type_list_n<
  >::type >
{};

}}}}

#endif
