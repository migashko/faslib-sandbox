#include <fas/testing.hpp>

#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/ser/ad_array.hpp>
#include <fas/serialization/json/ser/ad_null.hpp>
#include <fas/serialization/json/ser/ad_object.hpp>
#include <fas/serialization/json/ser/ad_attr.hpp>
#include <fas/serialization/json/ser/ad_primary_list.hpp>
#include <fas/serialization/json/ser/ad_brute_list.hpp>
#include <fas/serialization/json/ser/ad_brute_pair.hpp>

#include <fas/serialization/json/ser/ad_stub.hpp>
#include <fas/serialization/json/ser/ad_sequence.hpp>
#include <fas/serialization/json/ser/ad_string.hpp>
#include <fas/serialization/json/ser/ad_integer.hpp>
#include <fas/serialization/json/ser/ad_field.hpp>

#include <fas/serialization/json/except/ad_except.hpp>
#include <fas/serialization/json/except/tags.hpp>

#include <fas/serialization/json/ser/serialize_integer.hpp>
#include <fas/serialization/json/ser/serialize_array.hpp>

#include <fas/serialization/json/meta/integer.hpp>
#include <fas/serialization/json/meta/array.hpp>
#include <fas/serialization/json/meta/string.hpp>
#include <fas/serialization/json/meta/field.hpp>
#include <fas/serialization/json/meta/attr.hpp>
#include <fas/serialization/json/meta/field.hpp>
#include <fas/serialization/json/meta/fieldx.hpp>
#include <fas/serialization/json/meta/first.hpp>
#include <fas/serialization/json/meta/second.hpp>
#include <fas/serialization/json/meta/getset.hpp>
#include <fas/serialization/json/meta/object.hpp>
#include <fas/serialization/json/meta/brute_pair.hpp>

/*
#include "../../foo.hpp"
#include "../../bar.hpp"
#include "../../names.hpp"
*/
#include <fas/range/range.hpp>
#include <fas/range/orange.hpp>
#include <fas/typemanip/tstring.hpp>
#include <vector>
#include <map>
#include <string>
#include <cstring>

namespace aj = ::fas::json;
namespace ajs = ::fas::json::ser;

namespace test1 {
  
struct object1
{
  int field1;
  std::vector<std::string> field2;
  typedef char field3_type[2][30];
  field3_type field3;
};

struct object2: object1
{
  object1 field4;
  typedef object1 field5_type[1];
  object1 field5[1];
};


FAS_NAME(field1)
FAS_NAME(field2)
FAS_NAME(field3)
FAS_NAME(field4)
FAS_NAME(field5)

typedef aj::object< fas::type_list_n<
  aj::field< n_field1, aj::attr<object1, int, &object1::field1, aj::integer> >,
  aj::field< n_field2, aj::attr<object1, std::vector<std::string>, &object1::field2, aj::array< aj::string > >  >,
  aj::field< n_field3, aj::attr<object1, object1::field3_type, &object1::field3, aj::array<aj::string> > >
>::type > object1_json;
 
typedef aj::object< fas::type_list_n<
  object1_json::target,
  aj::field< n_field4, aj::attr<object2, object1, &object2::field4, object1_json> >,
  aj::field< n_field5, aj::attr<object2, object2::field5_type, &object2::field5, aj::array<object1_json> > >
>::type > object2_json;

}

UNIT(object1_unit, "")
{
  using namespace ::fas::testing;
  
  test1::object2 o2;
  
  o2.field1 = 1;
  o2.field2.push_back("field2.1");
  o2.field2.push_back("field2.2");
  std::strcpy(o2.field3[0], "fld3.1");
  std::cout << std::endl << o2.field3[0] << std::endl << std::endl ;
  std::strcpy(o2.field3[1], "fld3.2");
  
  
  o2.field4.field1 = 1;
  o2.field4.field2.push_back("field4.1");
  o2.field4.field2.push_back("field4.2");
  std::strcpy(o2.field4.field3[0], "fld4.1");
  std::strcpy(o2.field4.field3[1], "fld4.2");
  

  o2.field5[0].field1 = 1;
  o2.field5[0].field2.push_back("field5.2.1");
  o2.field5[0].field2.push_back("field5.2.2");
  std::strcpy(o2.field5[0].field3[0], "fld5.3.1");
  std::strcpy(o2.field5[0].field3[1], "fld5.3.2");

  std::string result;
  ajs::ad_object ado;
  ado(t, test1::object2_json(), o2, fas::orange(result) );
  t << equal<expect>(result, "{1,2,3}") << FAS_TESTING_FILE_LINE 
    << std::endl << result;
}

namespace test2 {
  
  typedef aj::object<
    aj::brute_list<
      fas::type_list_n<
        aj::array<
          aj::field<
            aj::fieldX<std::string, aj::first, aj::string>,
            aj::fieldX<std::string, aj::second, aj::string>
          >
        >
      >::type
    >
  > map_json;
}

UNIT(object2_unit, "")
{
  using namespace ::fas::testing;
  std::map<std::string, std::string> m;
  m["field1"]="value1";
  m["field2"]="value2";
  
  std::string result;
  ajs::ad_object ado;
  ado(t, test2::map_json(), m, fas::orange(result) );
  t << equal<expect>(result, "{1,2,3}") << FAS_TESTING_FILE_LINE 
    << std::endl << result;

}
/*
UNIT(ad_object_test1, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;

  std::string result;
  std::vector<int> value;
  value.push_back(1);
  value.push_back(2);
  value.push_back(3);

  ad_object ado;
  ado(t, object< sequence<integer> >(), value, orange(result) );
  t << equal<expect>(result, "{1,2,3}") << FAS_TESTING_FILE_LINE;
}
*/

/*
UNIT(ad_object_test2, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;

  foo f;
  ad_field adm;
  std::string result;

  typedef field< n_foo4,  attr<foo, std::vector<int>, &foo::foo4, array<integer> > > foo4_json;
  adm(t, foo4_json(), f, orange(result) );
  t << equal<expect>(result, "\"foo4\":[20,30,40]") << FAS_TESTING_FILE_LINE;
}
*/

/*

UNIT(ad_object_test3, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;

  typedef object<
    brute_pair<
    type_list_n<
      field< n_foo1, attr<foo, int, &foo::foo1, integer> >,
      field< n_foo2, attr<foo, std::string, &foo::foo2, string> >,
      field< n_foo3, attr<foo, foo::foo3type, &foo::foo3, string> >
    >::type
    ,
    type_list_n<
      field< n_foo5, attr<foo, foo::foo5type, &foo::foo5, array<integer> > >,
      field< n_foo4, attr<foo, std::vector<int>, &foo::foo4, array<integer> >  >,
      field< n_foo6, attr<foo, std::vector<std::string>, &foo::foo6, array<string> >  >
    >::type
    >
  > foo_json;

  foo f;
  ad_object ado;
  std::string result;
  ado(t, foo_json(), f, orange(result) );

  // t << message(result);
  // {"foo1":-1,"foo2":"test-foo2","foo3":"test-foo3","foo5":[0,1,2,3,4],"foo4":[20,30,40],"foo6":["test-foo6-1","test-foo6-2"]}
  // {"foo1":-1,"foo2":"test-foo2","foo3":"test-foo3""foo5":[0,1,2,3,4],"foo4":[20,30,40],"foo6":["test-foo6-1","test-foo6-2"]}
  t << equal<expect>(result,
                     "{\"foo1\":-1,\"foo2\":\"test-foo2\",\"foo3\":\"test-foo3\","
                     "\"foo5\":[0,1,2,3,4],\"foo4\":[20,30,40],\"foo6\":[\"test-foo6-1\",\"test-foo6-2\"]}"
                    ) << result <<  FAS_TESTING_FILE_LINE;
}
*/

/*
UNIT(ad_object_test4, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;
  
  typedef object<
      field< n_baz1, attr<bar::baz, int, &bar::baz::baz1, integer> >
  > baz_json;

  typedef object<
    type_list_n<
      field< n_bar1, attr<bar, bar::baz, &bar::bar1, baz_json> >
    >::type
  > bar_json;

  bar f;
  ad_object ado;
  std::string result;
  ado(t, bar_json(), f, orange(result) );
  //t << message(result);
  /// {"bar1":{"baz1":42}}
  t << equal<expect>(result, "{\"bar1\":{\"baz1\":42}}") << FAS_TESTING_FILE_LINE;
}
*/
/*
  typedef aj::object<
    aj::field< n_foo1, aj::attr<foo, int, &foo::foo1, aj::integer> >
  > foo_json;

  typedef aj::object<
      aj::field< n_baz1, aj::attr<bar::baz, int, &bar::baz::baz1, aj::integer> >
  > baz_json;*/

/*
  typedef
    fas::type_list_n<
      aj::field< n_bar1, aj::attr<bar, bar::baz, &bar::bar1, baz_json> >,
      aj::field< n_bar2, aj::attr<bar, foo, &bar::bar2, foo_json> >,
      aj::field< n_bar3, aj::attr<bar, std::vector<foo>, &bar::bar3, aj::array<foo_json> > >,
      aj::field< n_bar4, aj::attr<bar, bar::bar4type, &bar::bar4, aj::array<foo_json> > >,
      aj::field< n_bar5, aj::attr<bar, bar::foo_set, &bar::bar5, aj::array<foo_json> > >
    >::type bar_json_list;
  
  struct bar_json: aj::object<
    bar_json_list
    fas::type_list_n<
      aj::field< n_bar1, aj::attr<bar, bar::baz, &bar::bar1, baz_json> >,
      aj::field< n_bar2, aj::attr<bar, foo, &bar::bar2, foo_json> >,
      aj::field< n_bar3, aj::attr<bar, std::vector<foo>, &bar::bar3, aj::array<foo_json> > >,
      aj::field< n_bar4, aj::attr<bar, bar::bar4type, &bar::bar4, aj::array<foo_json> > >,
      aj::field< n_bar5, aj::attr<bar, bar::foo_set, &bar::bar5, aj::array<foo_json> > >
    >::type
    
  > {};
  */

/*
UNIT(ad_object_test5, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;




  bar f;
  ad_object ado;
  std::string result;
  ado(t, bar_json(), f, orange(result) );
  //t << message(result);
  /// {"bar1":{"baz1":42},"bar2":{"foo1":-1},"bar3":[{"foo1":-1}],"bar4":[{"foo1":-1},{"foo1":-1}],"bar5":[{"foo1":1},{"foo1":2}]}
  t << equal<expect>( result,
                      "{\"bar1\":{\"baz1\":42},\"bar2\":{\"foo1\":-1},\"bar3\":[{\"foo1\":-1}],"
                      "\"bar4\":[{\"foo1\":-1},{\"foo1\":-1}],\"bar5\":[{\"foo1\":1},{\"foo1\":2}]}"
                    ) << FAS_TESTING_FILE_LINE
    << std::endl << result;
}
*/

/*

struct f_pair_first
{
	template<typename V>
	const typename V::first_type& operator()(const V& v)
	{
		return v.first;
	}

        template<typename V>
        typename V::first_type& operator()(V& v)
        {
                return v.first;
        }

	template<typename V>
	void operator()(V& v, const typename V::first_type& value)
	{
		v.first = value;
	}
};

struct f_pair_second
{
	template<typename V>
	const typename V::second_type& operator()(const V& v)
	{
		return v.second;
	}

        template<typename V>
        typename V::second_type& operator()(V& v)
        {
                return v.second;
        }

	template<typename V>
	void operator()(V& v, const typename V::second_type& value)
	{
		v.second = value;
	}
};*/

/*
UNIT(ad_object_test6, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;

  typedef object<
    field< n_foo1, attr<foo, int, &foo::foo1, integer> >
  > foo_json;
*/
  /*
  typedef std::pair<std::string, foo> foo_pair;

  
  typedef object<
    brute_pair<
      field< n_key, attr< foo_pair, std::string, &foo_pair::first, string> >,
      field< n_value, attr< foo_pair, foo, &foo_pair::second, foo_json> >
    >
  > foo6_map_json;
  */
  
/*
  typedef object<
    brute_pair<
      field< n_key, aj::field< std::string, aj::first, string> >,
      field< n_value, aj::field< foo, aj::second, foo_json> >
    >
  > foo6_map_json;

  typedef object<
      field<
        aj::field< std::string, aj::first, string>,
        aj::field< foo, aj::second, foo_json>
      >
  > foo7_map_json;


  typedef object<
    type_list_n<
      field< n_bar6, attr<bar, bar::foo_map, &bar::bar6, array<foo6_map_json> > >,
      field< n_bar7, attr<bar, bar::foo_map, &bar::bar7, array<foo7_map_json> > >
    >::type
  > bar_json;

  bar f;
  ad_object ado;
  std::string result;
  ado(t, bar_json(), f, orange(result) );
  */
  /*
    {
       "bar6":[
          {"key":"bar6-1","value":{"foo1":-1}},
          {"key":"bar6-2","value":{"foo1":-1}}
       ],
       "bar7":[
          {"bar7-1":{"foo1":-1}},
          {"bar7-2":{"foo1":-1}}
       ]
    }
  */
  /*
  t << equal<expect>( result,
                      "{\"bar6\":[{\"key\":\"bar6-1\",\"value\":{\"foo1\":-1}},{\"key\":\"bar6-2\",\"value\":{\"foo1\":-1}}],"
                      "\"bar7\":[{\"bar7-1\":{\"foo1\":-1}},{\"bar7-2\":{\"foo1\":-1}}]}"
                    ) << FAS_TESTING_FILE_LINE;
}
*/

  /*
UNIT(ad_object_test7, "test ad_object advice")
{
  using namespace ::fas;
  using namespace ::fas::testing;
  using namespace ::fas::json;
  using namespace ::fas::json::ser;

  typedef object<
    field< n_foo1, attr<foo, int, &foo::foo1, integer> >
  > foo_json;
  */

  /*
  typedef std::pair<std::string, foo> foo_pair;


  typedef field<
    attr< foo_pair, std::string, &foo_pair::first, string>,
	    attr< foo_pair, foo, &foo_pair::second, foo_json>
  > foo_field_json;
  */

  /*
  typedef field<
    field< aj::first, string>,
    field< aj::second, foo_json>
  > foo_field_json;


  typedef object<
    type_list_n<
      attr<bar, bar::foo_map, &bar::bar6, sequence<foo_field_json> >,
      attr<bar, bar::foo_map, &bar::bar7, sequence<foo_field_json> >
    >::type
  > bar_json;

  bar f;
  ad_object ado;
  std::string result;
  ado(t, bar_json(), f, orange(result) );
  */
  //t << message(result);
  /** {
   *    "bar6-1":{"foo1":-1},
   *    "bar6-2":{"foo1":-1},
   *    "bar7-1":{"foo1":-1},
   *    "bar7-2":{"foo1":-1}
   * }
  */
  /*
  t << equal<expect>( result,
                      "{\"bar6-1\":{\"foo1\":-1},\"bar6-2\":{\"foo1\":-1},\"bar7-1\":{\"foo1\":-1},\"bar7-2\":{\"foo1\":-1}}"
                    ) << FAS_TESTING_FILE_LINE;
}
*/

BEGIN_SUITE(object_serializer_suite, "object serializer suite")
/*
  ADD_UNIT(ad_object_test1)
  ADD_UNIT(ad_object_test2)
  ADD_UNIT(ad_object_test3)
  ADD_UNIT(ad_object_test4)
  ADD_UNIT(ad_object_test5)
  ADD_UNIT(ad_object_test6)
  ADD_UNIT(ad_object_test7)
  */
  ADD_UNIT(object1_unit)
  ADD_UNIT(object2_unit)
  ADD_ADVICE( ::fas::json::ser::_string_, ::fas::json::ser::ad_string)
  ADD_ADVICE( ::fas::json::ser::_cstring_, ::fas::json::ser::ad_cstring)
  ADD_ADVICE( ::fas::json::ser::_integer_, ::fas::json::ser::ad_integer)
  ADD_ADVICE( ::fas::json::ser::_sequence_, ::fas::json::ser::ad_sequence)
  ADD_ADVICE( ::fas::json::ser::_array_, ::fas::json::ser::ad_array)
  ADD_ADVICE( ::fas::json::ser::_object_, ::fas::json::ser::ad_object)
  ADD_ADVICE( ::fas::json::ser::_field_, ::fas::json::ser::ad_field)
  //ADD_ADVICE( ::fas::json::ser::_field_list_, ::fas::json::ser::ad_field_list)
  ADD_ADVICE( ::fas::json::ser::_attr_, ::fas::json::ser::ad_attr)
  ADD_ADVICE( ::fas::json::ser::_prop_, ::fas::json::ser::ad_prop)
  ADD_ADVICE( ::fas::json::ser::_primary_list_, ::fas::json::ser::ad_primary_list)
  ADD_ADVICE( ::fas::json::ser::_brute_list_, ::fas::json::ser::ad_brute_list)
  ADD_ADVICE( ::fas::json::ser::_stub_, ::fas::json::ser::ad_stub)
  ADD_ADVICE( ::fas::json::ser::_brute_pair_, ::fas::json::ser::ad_brute_pair)
  ADD_ADVICE( ::fas::json::ser::_null_, ::fas::json::ser::ad_null)
  ADD_ADVICE( ::fas::json::_except_, ::fas::json::ad_except)
END_SUITE(object_serializer_suite)
