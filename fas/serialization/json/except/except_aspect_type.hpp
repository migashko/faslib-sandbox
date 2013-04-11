#ifndef FAS_SERIALIZATION_JSON_EXCEPT_EXCEPT_ASPECT_TYPE_HPP
#define FAS_SERIALIZATION_JSON_EXCEPT_EXCEPT_ASPECT_TYPE_HPP

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/json/except/ad_except.hpp>

namespace fas{ namespace json{

typedef aspect< type_list_n<
  advice<_except_, ad_except>
>::type > except_aspect_type;


}}

#endif
