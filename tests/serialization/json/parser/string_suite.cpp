#include <fas/testing.hpp>

#include <fas/serialization/json/parse/ad_utf8_letter.hpp>
#include <fas/serialization/json/parse/ad_four_hex_digits.hpp>

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/json/except/ad_except.hpp>

#include <fas/range.hpp>
#include <fas/range/mrange.hpp>
#include <set>

namespace aj = ::fas::json;

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

template<bool Valid, typename T>
void hex_subunit(T& t, const char* h, int line)
{
  using namespace fas::testing;
  try
  {

    aj::parse::ad_four_hex_digits hex4;
    std::string out;
    t << is_true<assert>(hex4.peek(t, h)) << FAS_TESTING_FILE_LINE << "," <<line;
    const char* ptr = hex4( t, h, fas::orange(out)).first;
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


BEGIN_SUITE(string_suite, "")
  ADD_UNIT(ad_utf8_letter_unit)
  ADD_UNIT(ad_four_hex_digits_unit)
  ADD_ADVICE( aj::_except_, aj::ad_except )
END_SUITE(string_suite)
