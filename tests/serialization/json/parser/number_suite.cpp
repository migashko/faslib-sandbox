#include <fas/testing.hpp>
#include <fas/serialization/json/parse/ad_number.hpp>


namespace aj = ::fas::json;

UNIT(ad_number_unit, "")
{
  using namespace ::fas::testing;
  t << nothing();
}


BEGIN_SUITE(number_suite, "")
  ADD_UNIT(ad_number_unit)
END_SUITE(number_suite)
