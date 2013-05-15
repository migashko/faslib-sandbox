#include <fas/testing.hpp>
#include <fas/integral.hpp>
#include <fas/serialization/json/deserializer.hpp>
#include <fas/serialization/json/meta.hpp>

namespace aj = ::fas::json;

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  aj::deserializer<> deser;

  const char json[] = "12345";
  int result = -1;
  
  deser( aj::integer< aj::restriction< aj::max_value< fas::int_<12345> > > >(), result, fas::range(json) );

  t << equal<expect>(result, 12345) << FAS_TESTING_FILE_LINE;

  
  
  t << nothing();
}


BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
END_SUITE(deser_suite)
