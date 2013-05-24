#include <fas/testing.hpp>
#include <fas/serialization/json/deserializer.hpp>

namespace aj = ::fas::json;  

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  aj::deserializer<> deser;
  t << nothing();
}

BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
END_SUITE(deser_suite)
