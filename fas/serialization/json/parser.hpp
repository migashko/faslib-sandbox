#ifndef FAS_SERIALIZATION_JSON_PARSER_HPP
#define FAS_SERIALIZATION_JSON_PARSER_HPP

#include <fas/serialization/except/aspect.hpp>
#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/serialization/parser.hpp>
#include <fas/aop/merge_aspect.hpp>

namespace fas{ namespace json{

template<
  typename A1 = empty_type, // TODO: оставить A 
  typename A2 = empty_type,
  typename A3 = empty_type,
  typename A4 = empty_type,
  typename A5 = empty_type
>
class parser:
  public ::fas::serialization::parser<
    typename merge_aspect<A1,A2,A3,A4,A5>::type,
    parse::aspect,
    ::fas::serialization::except::aspect
  >
{
  
};

}}

#endif
