#ifndef FAS_SERIALIZATION_JSON_META_STRING_HPP
#define FAS_SERIALIZATION_JSON_META_STRING_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/sequence.hpp>
#include <fas/typemanip/empty_type.hpp>


namespace fas{ namespace json{

struct string: sequence<empty_type, _string_>
{
  /*
  typedef empty_list targets;
  typedef _string_ tag;
  */
};

}}

#endif
