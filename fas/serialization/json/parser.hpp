#ifndef FAS_SERIALIZATION_JSON_PARSER_HPP
#define FAS_SERIALIZATION_JSON_PARSER_HPP

#include <fas/serialization/json/except/aspect.hpp>
#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/serialization/json/parse/space/aspect_cp.hpp>
#include <fas/serialization/parser.hpp>
#include <fas/aop/aspect_merge.hpp>

namespace fas{ namespace json{

typedef parse::space::aspect_space_cp space_cp;
typedef parse::space::aspect_white_space_cp white_space_cp;
typedef parse::space::aspect_comment_cp comment_cp;

template<
  typename A1 = empty_type,
  typename A2 = empty_type,
  typename A3 = empty_type,
  typename A4 = empty_type,
  typename A5 = empty_type
>
class parser:
  public ::fas::serialization::parser<
    typename aspect_merge<A1,A2,A3,A4,A5>::type,
    parse::aspect,
    except::aspect
  >
{
  
};

}}

#endif
