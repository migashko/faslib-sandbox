#ifndef FAS_SERIALIZATION_JSON_META_EQUAL_STRING_HPP
#define FAS_SERIALIZATION_JSON_META_EQUAL_STRING_HPP

#include <fas/serialization/json/meta/string_ex.hpp>
#include <fas/serialization/json/meta/equal_content.hpp>


namespace fas{ namespace json{

template<typename TString>
struct equal_string
  : string_ex< equal_content<TString> >
{
};

}}

#endif
