#ifndef FAS_SERIALIZATION_JSON_META_ELEMENT_HPP
#define FAS_SERIALIZATION_JSON_META_ELEMENT_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

template<typename T>
struct element
{
  typedef T target;
  typedef _element_ tag;
};
}}

#endif
