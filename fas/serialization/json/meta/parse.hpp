#ifndef FAS_SERIALIZATION_JSON_META_PARSE_HPP
#define FAS_SERIALIZATION_JSON_META_PARSE_HPP

#include <fas/serialization/deser/tags.hpp>

namespace fas{ namespace json{

template<typename Tg>
struct parse_skip
{
  typedef Tg parser_tag;
  typedef ::fas::serialization::deser::_parse_skip_ tag;
};

template<typename Tg>
struct parse_skip_if
{
  typedef Tg parser_tag;
  typedef ::fas::serialization::deser::_parse_skip_if_ tag;
};

template<typename Tg>
struct parse_copy
{
  typedef Tg parser_tag;
  typedef ::fas::serialization::deser::_parse_copy_ tag;
};


template<typename Tg>
struct parse_copy_if
{
  typedef Tg parser_tag;
  typedef ::fas::serialization::deser::_parse_copy_if_ tag;
};

}}

#endif
