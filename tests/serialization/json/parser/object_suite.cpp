#include <fas/testing.hpp>

#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/except/ad_except.hpp>

#include <fas/range.hpp>
#include <fas/range/mrange.hpp>

namespace aj = ::fas::json;

UNIT(ad_object_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_object as;
  typedef char chs_type[100];
  chs_type chs="{ \"field\":12234 }";
  std::string result;
  as(t, std::make_pair( fas::srange(chs), fas::orange(result) ) );
  t << equal<expect, std::string>(result, chs) << "[" << result <<"]" << chs<< FAS_TESTING_FILE_LINE;

  
  chs_type chs2="{ \"field\":12234, /*field2*/ \"field2\":[{},{}] }";
  result.clear();
  as(t, std::make_pair( fas::srange(chs2), fas::orange(result) ) );
  t << equal<expect, std::string>(result, chs2) << "[" << result <<"]" << chs<< FAS_TESTING_FILE_LINE;

}

BEGIN_SUITE(object_suite, "")
  ADD_UNIT(ad_object_unit)
  ADD_ADVICE( aj::_except_, fas::ad_except )
  ADD_ASPECT( aj::parse::aspect)
END_SUITE(object_suite)
