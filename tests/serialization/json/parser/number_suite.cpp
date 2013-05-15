#include <fas/testing.hpp>
#include <fas/serialization/json/parse/simple/ad_number.hpp>
#include <fas/except/ad_except.hpp>
#include <fas/range.hpp>
#include <string>
namespace aj = ::fas::json;

UNIT(ad_number_unit, "")
{
  using namespace ::fas::testing;
  char ch1[]="-123";
  char ch2[]="0";
  char ch3[]="-12.001E+123";
  char ch4[]="9999";
  
  std::string str;  
  aj::parse::ad_number an;
  
  an(t, std::make_pair(fas::range(ch1), fas::orange(str)));
  t << equal<expect>(str, ch1) << FAS_TESTING_FILE_LINE;
  
  str.clear();
  an(t, std::make_pair(fas::range(ch2), fas::orange(str)));
  t << equal<expect>(str, ch2) << FAS_TESTING_FILE_LINE;

  str.clear();
  an(t, std::make_pair(fas::range(ch3), fas::orange(str)));
  t << equal<expect>(str, ch3) << FAS_TESTING_FILE_LINE;

  str.clear();
  an(t, std::make_pair(fas::range(ch4), fas::orange(str)));
  t << equal<expect>(str, ch4) << FAS_TESTING_FILE_LINE;
}

#include <fas/serialization/json/except.hpp>

UNIT(ad_bad_number_unit, "")
{
  using namespace ::fas::testing;
  
  char ch1[]="+-1";
  char ch2[]="eER";
  char ch3[]="-12.001E";
  char ch4[]="123.";
  
  bool flag = false;
  std::string str;  
  aj::parse::ad_number an;

  try{ an(t, std::make_pair(fas::range(ch1), fas::orange(str))); } 
  catch( const aj::parse_error& ) { flag =true; }
  t << is_true<expect>(flag) << FAS_TESTING_FILE_LINE;

  flag=false;
  str.clear();
  try{ an(t, std::make_pair(fas::range(ch2), fas::orange(str))); } 
  catch( const aj::parse_error& ) { flag =true; }
  t << is_true<expect>(flag) << FAS_TESTING_FILE_LINE;

  flag=false;
  str.clear();
  try{ an(t, std::make_pair(fas::range(ch3), fas::orange(str))); } 
  catch( const aj::parse_error& ) { flag =true; }
  t << is_true<expect>(flag) << FAS_TESTING_FILE_LINE;

  flag=false;
  str.clear();
  try{ an(t, std::make_pair(fas::range(ch4), fas::orange(str))); } 
  catch( const aj::parse_error& ) { flag =true; }
  t << is_true<expect>(flag) << FAS_TESTING_FILE_LINE;

  t << nothing();
}


BEGIN_SUITE(number_suite, "")
  ADD_UNIT(ad_number_unit)
  ADD_UNIT(ad_bad_number_unit)
  ADD_ADVICE( aj::_except_, fas::ad_except<> )
END_SUITE(number_suite)
