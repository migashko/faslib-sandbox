#include <fas/testing.hpp>

#include <fas/serialization/json/parse/aspect.hpp>
#include <fas/serialization/json/parse/ad_utf8_letter.hpp>
#include <fas/serialization/json/parse/ad_four_hex_digits.hpp>
#include <fas/serialization/json/parse/ad_quote.hpp>
#include <fas/serialization/json/parse/ad_control_character.hpp>
#include <fas/serialization/json/parse/ad_string_content.hpp>

#include <fas/serialization/json/except.hpp>

/*#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/json/except/ad_except.hpp>
*/
#include <fas/except/ad_except.hpp>

#include <fas/range.hpp>
#include <fas/range/mrange.hpp>
#include <set>
#include <algorithm>

namespace aj = ::fas::json;

///
/// utf8 letter
///

UNIT(ad_utf8_letter_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_utf8_letter utf8;
  char a1[]="~Ё你";
  std::string out;
  const char* ptr = a1;
  ptr = utf8(t, ptr, fas::orange(out) ).first;
  t << equal<assert>( std::string(ptr-1, ptr) , std::string(a1, a1+1) ) << FAS_TESTING_FILE_LINE;
  ptr = utf8(t, ptr, fas::orange(out) ).first;
  t << equal<assert>( std::string(ptr-2, ptr) , std::string(a1+1, a1+3) )  << FAS_TESTING_FILE_LINE;
  ptr = utf8(t, ptr, fas::orange(out) ).first;
  t << equal<assert>( std::string(ptr-3, ptr) , std::string(a1+3, a1+6) ) << FAS_TESTING_FILE_LINE;
  t << equal<assert>(out, a1) << FAS_TESTING_FILE_LINE;

  out.clear();
  unsigned int i2 = 0x808080F0;
  ptr = reinterpret_cast<const char*>(&i2);
  ptr = utf8(t, ptr, fas::orange(out) ).first;
  t << equal<assert>(out, std::string( reinterpret_cast<const char*>(&i2), reinterpret_cast<const char*>(&i2) + 4) );


  bool except = false;
  try
  {
    out.clear();
    i2 = 0xC08080F0;
    ptr = reinterpret_cast<const char*>(&i2);
    ptr = utf8(t, ptr, fas::orange(out) ).first;
    t << equal<assert>(out, std::string( reinterpret_cast<const char*>(&i2), reinterpret_cast<const char*>(&i2) + 4) );
  }
  catch( const aj::parse_error& )
  {
    except = true;
  }

  t << is_true<assert>(except) << FAS_TESTING_FILE_LINE;
  /*0x808080F0*/
}

///
/// four hex digits
///

template<bool Valid, typename T>
void hex_subunit(T& t, const char* h, int line)
{
  using namespace fas::testing;
  try
  {

    aj::parse::ad_four_hex_digits hex4;
    std::string out;
    t << is_true<assert>(hex4.peek(t, h)) << FAS_TESTING_FILE_LINE << "," <<line;
    const char* ptr = hex4( t, std::make_pair( h, fas::orange(out) ) ).first;
    t << equal<assert, const char*>(ptr, h+4) << FAS_TESTING_FILE_LINE << "," <<line;
    t << equal<assert, std::string>(out, h) << FAS_TESTING_FILE_LINE << "," <<line;

    if ( !Valid )
      t << fail("") << FAS_TESTING_FILE_LINE << "," <<line;;
  }
  catch( const aj::parse_error& e)
  {
    if ( Valid )
    {
      t << fail("") << FAS_TESTING_FILE_LINE << "," <<line;;
      throw e;
    }
  }
}

UNIT(ad_four_hex_digits_unit, "")
{
  using namespace fas::testing;
  hex_subunit<true>(t, "0000", __LINE__);
  hex_subunit<true>(t, "FFFF", __LINE__);
  hex_subunit<true>(t, "aBcD", __LINE__);
  hex_subunit<true>(t, "eF43", __LINE__);

  hex_subunit<false>(t, "0", __LINE__);
  hex_subunit<false>(t, "00", __LINE__);
  hex_subunit<false>(t, "000", __LINE__);
  hex_subunit<false>(t, "000-", __LINE__);

  hex_subunit<false>(t, "f", __LINE__);
  hex_subunit<false>(t, "ff", __LINE__);
  hex_subunit<false>(t, "fff", __LINE__);
  hex_subunit<false>(t, "fffg", __LINE__);
}

///
/// quote
///

UNIT(ad_quote_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_quote adq;

  const char* chq="\"";
  const char* chf="'";
  t << is_true<expect>(adq.peek(t, chq) );
  t << is_false<expect>(adq.peek(t, chf) );

  char out[25]={0};
  adq(t, std::make_pair( chq, fas::orange(out)) );
  t << equal<expect, std::string>(out, "\"") << FAS_TESTING_FILE_LINE;

  bool flag = false;
  try{ adq(t, std::make_pair( chf, fas::orange(out)) ); } catch(const aj::expected_of& ) { flag=true;}
  t << is_true<assert>(flag) << FAS_TESTING_FILE_LINE;
}

UNIT(ad_control_charaster_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_control_character acc;

  typedef char chs_type[10];
  chs_type chs="\"\\/bfnrtu";
  std::srand(time(0));
  std::random_shuffle(chs, chs + sizeof(chs)-1   );
  std::string result;
  typedef fas::typerange<chs_type>::range irange;
  typedef fas::typerange<std::string>::orange orange;
  typedef std::pair< irange, orange> pair_range;

  pair_range pr( fas::range(chs, chs + sizeof(chs)-1 ), fas::orange(result));

  while (pr.first)
    pr = acc(t, pr);

  t << equal<expect, std::string>(result, chs) << "[" << result <<"]"<< FAS_TESTING_FILE_LINE;
}

UNIT(ad_string_content_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_string_content asc;
  typedef char chs_type[100];
  chs_type chs="~Ё你\\ueF43\\b\\\"\"";
  std::string result;
  asc(t, std::make_pair( fas::srange(chs), fas::orange(result) ) );
  chs[std::strlen(chs)-1]='\0';
  t << equal<expect, std::string>(result, chs) << "[" << result <<"]"<< FAS_TESTING_FILE_LINE;
}

UNIT(ad_string_unit, "")
{
  using namespace fas::testing;
  aj::parse::ad_string as;
  typedef char chs_type[100];
  chs_type chs="\"~Ё你\\ueF43\\b\\\"\"";
  std::string result;
  as(t, std::make_pair( fas::srange(chs), fas::orange(result) ) );
  t << equal<expect, std::string>(result, chs) << "[" << result <<"]" << chs<< FAS_TESTING_FILE_LINE;
}

BEGIN_SUITE(string_suite, "")
  ADD_UNIT(ad_utf8_letter_unit)
  ADD_UNIT(ad_four_hex_digits_unit)
  ADD_UNIT(ad_quote_unit)
  ADD_UNIT(ad_control_charaster_unit)
  ADD_UNIT(ad_string_content_unit)
  ADD_UNIT(ad_string_unit)
  ADD_ADVICE( aj::_except_, fas::ad_except )
  ADD_ASPECT( aj::parse::aspect)
  /*
  ADD_ADVICE( aj::parse::_quote_, aj::parse::ad_quote )
  ADD_ADVICE( aj::parse::_control_character_, aj::parse::ad_control_character )
  */
END_SUITE(string_suite)
