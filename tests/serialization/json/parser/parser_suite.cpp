#include <fas/testing.hpp>
#include <fas/serialization/json/parser.hpp>
#include <fas/serialization/json/options.hpp>
#include <fas/range.hpp>

namespace aj = ::fas::json;

struct parser_all_space_copy: aj::parser< aj::all_space_copy > {};
struct parser_orig: aj::parser<> {};

UNIT(parser1_unit, "")
{
  using namespace fas::testing;


  const char *str="{  /* \"aaa\":false */  }";
  
  parser_all_space_copy p;
  
  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  
  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  std::string result;
  p( fas::srange(str), fas::orange(result) );
  t << equal<expect, std::string>(result, str) << result << std::endl << FAS_TESTING_FILE_LINE;

  char strarr[40]="\0";
  p( fas::srange(str), fas::range(strarr) );
  t << equal<expect, std::string>(strarr, str) << strarr << std::endl << FAS_TESTING_FILE_LINE;

  p.exception();
  
  parser_orig p2;
  p2( fas::srange(str) );
  t << is_true<expect>( p2 ) << FAS_TESTING_FILE_LINE;

  result.clear();
  p2( fas::srange(str), fas::orange(result) );
  t << equal<expect, std::string>(result, "{}") << result << std::endl << FAS_TESTING_FILE_LINE;
  p2.exception();
  
  t << nothing();
}


UNIT(parser2_unit, "")
{
  using namespace fas::testing;

  //const char *str="[  \"aaa\":false  ]";
  const char *str="[    ]";  
  parser_all_space_copy p;

  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  p( fas::srange(str) );
  t << is_true<expect>( p ) << FAS_TESTING_FILE_LINE;

  std::string result;
  p( fas::srange(str), fas::orange(result) );
  t << equal<expect, std::string>(result, str) << result << std::endl << FAS_TESTING_FILE_LINE;

  char strarr[40]="\0";
  p( fas::srange(str), fas::range(strarr) );
  t << equal<expect, std::string>(strarr, str) << strarr << std::endl << FAS_TESTING_FILE_LINE;

  parser_orig p2;
  p2( fas::srange(str) );
  t << is_true<expect>( p2 ) << FAS_TESTING_FILE_LINE;

  result.clear();
  p2( fas::srange(str), fas::orange(result) );
  t << equal<expect, std::string>(result, "[]") << result << std::endl << FAS_TESTING_FILE_LINE;

  t << nothing();
}


BEGIN_SUITE(parser_suite, "")
  ADD_UNIT(parser1_unit)
  ADD_UNIT(parser2_unit)
END_SUITE(parser_suite)
