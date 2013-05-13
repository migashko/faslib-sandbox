#include <fas/testing.hpp>
#include <fas/serialization/json/parser.hpp>
//namespace aj = ::fas::json;

UNIT(parser_unit, "")
{
  using namespace fas::testing;
  t << nothing();
}


BEGIN_SUITE(parser_suite, "")
  ADD_UNIT(parser_unit)
END_SUITE(parser_suite)
