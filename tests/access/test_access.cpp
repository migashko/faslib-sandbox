//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#include <fas/access/member.hpp>
#include <fas/access/member_get.hpp>
#include <fas/access/member_set.hpp>

#include <fas/testing.hpp>
#include <string>
#include <cstring>

struct foo
{
  std::string foo1;
  int foo2;
  
  typedef char foo3_type[100];
  typedef char* foo4_type;
  
  char foo3[100];
  char* foo4;
  
  foo()
    : foo1("foo1")
    , foo2(2)
  {
    std::strcpy(foo3, "foo3");
    foo4 = new char[100];
    std::strcpy(foo4, "foo4");
  }
  
  ~foo()
  {
    delete[] foo4;
  }

  const std::string& get_foo1() const { return foo1;}
  void set_foo1(const std::string& value) { foo1 = value;}

  int get_foo2() const { return foo2;}
  void set_foo2(int value) { foo2 = value;}

  const char* get_foo3() const { return foo3;}
  void set_foo3(const char* value) { std::strcpy(foo3, value);}

  const char* get_foo4() const { return foo4;}
  void set_foo4(const char* value) { std::strcpy(foo4, value);}

  
};

UNIT(member_unit, "")
{
  using namespace ::fas::testing;
  foo f;
  typedef fas::member<foo, std::string, &foo::foo1> get_foo1;
  typedef fas::member<foo, int, &foo::foo2> get_foo2;
  typedef fas::member<foo, foo::foo3_type, &foo::foo3> get_foo3;
  typedef fas::member<foo, foo::foo4_type, &foo::foo4> get_foo4;

  t << equal<assert, std::string> ( get_foo1()(f), "foo1" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, int> ( get_foo2()(f), 2 ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo3()(f), "foo3" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo4()(f), "foo4" ) << FAS_TESTING_FILE_LINE;

  get_foo1()(f) = "foo1-test";
  get_foo2()(f) = 42;
  std::strcpy( get_foo3()(f), "foo3-test" );
  std::strcpy( get_foo4()(f), "foo4-test" );

  t << equal<assert, std::string> ( get_foo1()(f), "foo1-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, int> ( get_foo2()(f), 42 ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo3()(f), "foo3-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo4()(f), "foo4-test" ) << FAS_TESTING_FILE_LINE;
}

UNIT(member_get_set_unit, "")
{
  using namespace ::fas::testing;
  foo f;
  const foo& fc = f;
  typedef fas::member_get<foo, std::string, &foo::foo1> get_foo1;
  typedef fas::member_get<foo, int, &foo::foo2> get_foo2;
  typedef fas::member_get<foo, foo::foo3_type, &foo::foo3> get_foo3;
  typedef fas::member_get<foo, foo::foo4_type, &foo::foo4> get_foo4;

  typedef fas::member_set<foo, std::string, &foo::foo1> set_foo1;
  typedef fas::member_set<foo, int, &foo::foo2> set_foo2;
  typedef fas::member_set<foo, foo::foo3_type, &foo::foo3> set_foo3;
  typedef fas::member_set<foo, foo::foo4_type, &foo::foo4> set_foo4;

  t << equal<assert, std::string> ( get_foo1()(f), "foo1" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, int> ( get_foo2()(f), 2 ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo3()(f), "foo3" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo4()(f), "foo4" ) << FAS_TESTING_FILE_LINE;

  set_foo1()(f) = "foo1-test";
  set_foo2()(f) = 42;
  std::strcpy( set_foo3()(f), "foo3-test" );
  std::strcpy( set_foo4()(f), "foo4-test" );

  t << equal<assert, std::string> ( set_foo1()(f), "foo1-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, int> ( set_foo2()(f), 42 ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( set_foo3()(f), "foo3-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( set_foo4()(f), "foo4-test" ) << FAS_TESTING_FILE_LINE;

  t << equal<assert, std::string> ( get_foo1()(fc), "foo1-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, int> ( get_foo2()(fc), 42 ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo3()(fc), "foo3-test" ) << FAS_TESTING_FILE_LINE;
  t << equal<assert, std::string> ( get_foo4()(fc), "foo4-test" ) << FAS_TESTING_FILE_LINE;
}

BEGIN_SUITE(access_suite, "")
  ADD_UNIT(member_unit)
  ADD_UNIT(member_get_set_unit)
END_SUITE(access_suite)

BEGIN_TEST
RUN_SUITE(access_suite)
END_TEST


