#include <fas/testing.hpp>
#include <fas/serialization/json/parser.hpp>
#include <fas/serialization/json/options.hpp>
#include <fas/range.hpp>

namespace aj = ::fas::json;

UNIT(parser1_unit, "")
{
  using namespace fas::testing;

  const char *str="{  /* \"aaa\":false */  }";
  
  aj::parser< aj::all_space_copy > p;
  
  p( str );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;
  
  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  std::string result;
  p(str, fas::orange(result) );
  t << equal<expect, std::string>(result, str) << result << std::endl << FAS_TESTING_FILE_LINE;

  char strarr[40]="\0";
  p(str, fas::range(strarr) );
  t << equal<expect, std::string>(strarr, str) << strarr << std::endl << FAS_TESTING_FILE_LINE;

  p.exception();
  
  aj::parser<> p2;
  p2( str );
  t << is_true<expect>( p2 ) << FAS_TESTING_FILE_LINE;

  result.clear();
  p2(str, fas::orange(result) );
  t << equal<expect, std::string>(result, "{}") << result << std::endl << FAS_TESTING_FILE_LINE;
  p2.exception();
}

UNIT(parser2_unit, "")
{
  using namespace fas::testing;

  const char *str="[  /* \"aaa\":false */  ]";

  aj::parser< aj::all_space_copy > p;

  p( str );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  std::string result;
  p(str, fas::orange(result) );
  t << equal<expect, std::string>(result, str) << result << std::endl << FAS_TESTING_FILE_LINE;

  char strarr[40]="\0";
  p(str, fas::range(strarr) );
  t << equal<expect, std::string>(strarr, str) << strarr << std::endl << FAS_TESTING_FILE_LINE;


  aj::parser<> p2;
  p2( str );
  t << is_true<expect>( p2 ) << FAS_TESTING_FILE_LINE;

  result.clear();
  p2(str, fas::orange(result) );
  t << equal<expect, std::string>(result, "[]") << result << std::endl << FAS_TESTING_FILE_LINE;
}


BEGIN_SUITE(parser_suite, "")
  ADD_UNIT(parser1_unit)
  ADD_UNIT(parser2_unit)
END_SUITE(parser_suite)
