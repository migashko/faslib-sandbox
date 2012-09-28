//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#include <fas/serialization/except.hpp>
#include <fas/testing.hpp>
#include <fas/range.hpp>

namespace as = ::fas::serialization;


UNIT(expected_of_unit, "")
{
  using namespace ::fas::testing;

  as::expected_of e('x', 10);
  t << equal<expect>(e.tail_of(), 10) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "expected of 'x'") << FAS_TESTING_FILE_LINE;

  e = as::expected_of("xxx", -1);
  t << equal<expect>(e.tail_of(), -1) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "expected of 'xxx'") << FAS_TESTING_FILE_LINE;
}

UNIT(invalid_string_unit, "")
{
  using namespace ::fas::testing;
  as::invalid_string e;
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "invalid string") << FAS_TESTING_FILE_LINE;

   e = as::invalid_string(42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "invalid string") << FAS_TESTING_FILE_LINE;

}

UNIT(parse_error_unit, "")
{
  using namespace ::fas::testing;
  as::parse_error e(42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "parse error") << FAS_TESTING_FILE_LINE;

  e = as::parse_error("xxx", 42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;

  e = as::parse_error("xxx");
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;
}

UNIT(syntax_error_unit, "")
{
  using namespace ::fas::testing;
  as::syntax_error e(42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "syntax error") << FAS_TESTING_FILE_LINE;

  e = as::syntax_error("xxx", 42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;

  e = as::syntax_error("xxx");
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;
}


UNIT(invalid_number_unit, "")
{
  using namespace ::fas::testing;
  as::invalid_number e;
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "invalid number") << FAS_TESTING_FILE_LINE;

   e = as::invalid_number(42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "invalid number") << FAS_TESTING_FILE_LINE;

}

UNIT(out_of_range_unit, "")
{
  using namespace ::fas::testing;
  using namespace ::fas::testing;
  as::out_of_range e(42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "out of range") << FAS_TESTING_FILE_LINE;

  e = as::out_of_range("xxx", 42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << e.what() << FAS_TESTING_FILE_LINE;

  e = as::out_of_range("xxx");
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;
}

UNIT(serialization_error_unit, "")
{
  using namespace ::fas::testing;
  as::serialization_error e = as::serialization_error("xxx", 42);
  t << equal<expect>(e.tail_of(), 42) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;

  e = as::serialization_error("xxx");
  t << equal<expect>(e.tail_of(), 0) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>(e.what(), "xxx") << FAS_TESTING_FILE_LINE;
}


UNIT(unexpected_end_fragment_unit, "")
{
  using namespace ::fas::testing;
  t << nothing();
}




BEGIN_SUITE(except_suite, "")
  ADD_UNIT(expected_of_unit)
  ADD_UNIT(invalid_string_unit)
  ADD_UNIT(parse_error_unit)
  ADD_UNIT(syntax_error_unit)
  ADD_UNIT(invalid_number_unit)
  ADD_UNIT(out_of_range_unit)
  ADD_UNIT(serialization_error_unit)
  ADD_UNIT(unexpected_end_fragment_unit)
END_SUITE(except_suite)

BEGIN_TEST
  RUN_SUITE(except_suite)
END_TEST
