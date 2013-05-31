#include <fas/testing.hpp>

//namespace aj = ::fas::json;

UNIT(except_aspect_unit, "")
{
  using namespace ::fas::testing;
  t << nothing();
}

BEGIN_SUITE(except_suite, "")
  ADD_UNIT(except_aspect_unit)
END_SUITE(except_suite)
