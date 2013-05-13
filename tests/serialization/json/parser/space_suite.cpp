#include <fas/testing.hpp>

#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/serialization/json/except.hpp>


#include <fas/except/ad_except.hpp>

#include <fas/range.hpp>
#include <fas/range/mrange.hpp>

#include <string>
#include <utility>

namespace aj = ::fas::json;


UNIT(comment_unit, "")
{
  using namespace fas::testing;
  const char comment1[]="/*комментарий ~Ё你*/";
  
  std::string result;
  t.get_aspect().template get< aj::parse::_comment_ >()(t, std::make_pair( fas::srange(comment1), fas::orange(result) ) );
  t << equal<expect, std::string>(result, comment1) << FAS_TESTING_FILE_LINE;

  const char comment2[]="/*/**/{";
  result.clear();
  t.get_aspect().template get< aj::parse::_comment_ >()(t, std::make_pair( fas::srange(comment2), fas::orange(result) ) );
  t << equal<expect, std::string>(result, std::string(comment2, comment2+6)) << FAS_TESTING_FILE_LINE;

  const char comment3[]="/*** /";
  bool except = false;
  try
  {
    result.clear();
    t.get_aspect().template get< aj::parse::_comment_ >()(t, std::make_pair( fas::srange(comment3), fas::orange(result) ) );
  }
  catch( const aj::unexpected_end_fragment& )
  {
    except = true;
  }

  t << is_true<assert>(except) << FAS_TESTING_FILE_LINE;
}

UNIT(space_unit, "")
{
  using namespace fas::testing;
  const char comment1[]="      /* комментарий ~Ё你 */ {}";

  std::string result;
  t.get_aspect().template get< aj::parse::_space_ >()(t, std::make_pair( fas::srange(comment1), fas::orange(result) ) );
  t << equal<expect, std::string>(result, std::string(comment1, comment1 + strlen(comment1)-2)) << FAS_TESTING_FILE_LINE;
}


BEGIN_SUITE(space_suite, "")
  ADD_UNIT(comment_unit)
  ADD_UNIT(space_unit)
  
  ADD_ADVICE( aj::_except_, fas::ad_except )
  ADD_ASPECT( aj::parse::aspect)
END_SUITE(space_suite)
