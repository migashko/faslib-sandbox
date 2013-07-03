#ifndef FAS_SERIALIZATION_JSON_META_NAME_HPP
#define FAS_SERIALIZATION_JSON_META_NAME_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/optional.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace json{

template<typename Name>
struct name: Name
{
  typedef optional target;
  typedef _name_ tag;
};

template<typename S>
struct jstring: S
{
  typedef optional target;
  typedef _jstring_ tag;
};

template<typename S>
struct tstring: S
{
  typedef optional target;
  typedef _tstring_ tag;
};

}}

#endif
