#include <fas/testing.hpp>

#include <fas/serialization/json/deser/ad_integer.hpp>
/*#include <fas/serialization/json/deser/ad_boolean.hpp>
#include <fas/serialization/json/deser/ad_real.hpp>
#include <fas/serialization/json/meta/integer.hpp>
#include <fas/serialization/json/meta/boolean.hpp>
#include <fas/serialization/json/meta/real.hpp>

#include <fas/serialization/json/parser/aspect.hpp>

#include <fas/range/range.hpp>
*/
#include <sstream>
#include <limits>

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif


namespace aj = ::fas::json;


UNIT(ad_number_unit, "")
{
}


BEGIN_SUITE(number_suite, "")
  ADD_UNIT(ad_number_unit)
END_SUITE(number_suite)
