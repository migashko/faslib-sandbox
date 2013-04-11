#include <fas/testing.hpp>
#include <fas/serialization/json/deserializer.hpp>
#include <fas/serialization/json/meta.hpp>
#include <fas/range.hpp>

namespace aj = ::fas::json;

UNIT(except_aspect_unit, "")
{
  using namespace ::fas::testing;

  aj::deserializer<> deser;
  double a=0;

  deser( aj::integer(), a, fas::range("-123.123"));
  std::cout<< std::endl << a << std::endl;
  t << nothing();
}

BEGIN_SUITE(except_suite, "")
  ADD_UNIT(except_aspect_unit)
END_SUITE(except_suite)
