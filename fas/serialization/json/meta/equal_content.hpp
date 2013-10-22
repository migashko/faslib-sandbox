#ifndef FAS_SERIALIZATION_JSON_META_EQUAL_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_META_EQUAL_CONTENT_HPP

#include <fas/serialization/json/tags.hpp>


namespace fas{ namespace json{

template<typename TString>
struct equal_content
  : TString
{
  typedef _equal_content_ tag; 
};

}}

#endif
