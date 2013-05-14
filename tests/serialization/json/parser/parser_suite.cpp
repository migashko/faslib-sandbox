#include <fas/testing.hpp>
#include <fas/serialization/json/parser.hpp>
#include <fas/range.hpp>

namespace aj = ::fas::json;

UNIT(parser1_unit, "")
{
  using namespace fas::testing;

  const char *str="{  /* \"aaa\":false */  }";
  
  aj::parser<> p;
  
  p( str );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;
  
  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  std::string result;
  p(str, fas::orange(result) );
  t << equal<expect, std::string>(result, str) << result << std::endl << FAS_TESTING_FILE_LINE;

  char strarr[20]="\0";
  p(str, fas::range(strarr) );
  t << equal<expect, std::string>(strarr, str) << strarr << std::endl << FAS_TESTING_FILE_LINE;
  
  
  t << nothing();
}



BEGIN_SUITE(parser_suite, "")
  ADD_UNIT(parser1_unit)
END_SUITE(parser_suite)
