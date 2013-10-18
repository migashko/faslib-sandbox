#include <fas/testing.hpp>
#include <fas/serialization/json/deserializer.hpp>

#include <fas/serialization/json/meta.hpp>
#include <fas/serialization/meta.hpp>
#include <fas/type_list.hpp>
#include <fas/typemanip.hpp>
 
namespace aj = ::fas::json;
namespace as = ::fas::serialization;


struct object1
{
  int requred1;
  std::string requred2;
  int optional1;
  std::string optional2;
  object1()
    : requred1(1)
    , requred2("2")
    , optional1(-1)
    , optional2("-2")
  {}
};

struct object2
{
  int requred3;
  std::string optional3;
};

struct object3: object1,  object2 
{
  std::vector<object2> vect1;
};

using namespace ::fas::json;
  
FAS_NAME(requred1)
FAS_NAME(requred2)
FAS_NAME(requred3)
FAS_NAME(optional1)
FAS_NAME(optional2)
FAS_NAME(optional3)
FAS_NAME(vect1)

typedef object< ::fas::type_list_n<
  aj::field< 
    aj::name<n_requred1>, 
    aj::acc< fas::member<object1, int, &object1::requred1>, aj::integer<> >
  >,
  aj::field< 
    aj::name<n_requred2>, 
    aj::acc< fas::member<object1, std::string, &object1::requred2>, aj::string<> >
  >,
  aj::field< 
    aj::name<n_optional1>, 
    aj::acc< fas::member<object1, int, &object1::optional1>, aj::integer<> >
  >,
  aj::field< 
    aj::name<n_optional2>, 
    aj::acc< fas::member<object1, std::string, &object1::optional2>, aj::string<> >
  >
>::type > object1_json;


const char json1[]="{\"optional1\":11, \"requred2\":\"~Ё你 привет мир\",\"requred1\":4321, \"optional2\":\"\",}";
const char json2[]="{\"requred3\":123, \"optional3\":\"~Ё你 привет мир\"}";
const char json3[]="{"
                      "\"optional1\":11, \"requred2\":\"~Ё你 привет мир\",\"requred1\":4321, \"optional2\":\"\","
                      "\"requred3\":123, \"optional3\":\"~Ё你 привет мир\","
                      "\"vect1\":[{\"requred3\":123, \"optional3\":\"~Ё你 привет мир\"}]"
                   "}";

UNIT(object1_unit, "")
{
  using namespace fas::testing;
  aj::deserializer<> deser;

  object1 value ;
  try{
    deser( object1_json(), value, fas::srange(json1) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json1) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.requred1 <<  std::endl << value.requred2 << std::endl;
  t << equal<expect>(value.requred1, 4321) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.requred2, "~Ё你 привет мир") << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional1, 11) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional2, "") << FAS_TESTING_FILE_LINE;
  t << nothing();
}

typedef aj::object< fas::type_list_n<
  aj::mem_field<n_requred3, object2, int, &object2::requred3, aj::integer<> >, 
  aj::mem_field<n_optional3, object2, std::string, &object2::optional3, aj::string<> >
>::type > object2_json;

UNIT(object2_unit, "")
{
  using namespace fas::testing;
  aj::deserializer<> deser;

  object2 value ;
  try{
    deser( object2_json(), value, fas::srange(json2) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json2) ) << std::endl;
    abort();
    throw e;
  }
  
  std::cout << std::endl << value.requred3 <<  std::endl << value.optional3 << std::endl;
  t << equal<expect>(value.requred3, 123) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional3, "~Ё你 привет мир") << FAS_TESTING_FILE_LINE;
  t << nothing();
}

typedef aj::object< fas::type_list_n<
  aj::base<object1_json>, 
  aj::base<object2_json>, 
  aj::mem_field<n_vect1, object3, std::vector<object2>, &object3::vect1, aj::array<object2_json> >
>::type > object3_json;

UNIT(object3_unit, "")
{
  using namespace fas::testing;
  aj::deserializer<> deser;

  object3 value ;
  try{
    deser( object3_json(), value, fas::srange(json3) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json3) ) << std::endl;
    abort();
    throw e;
  }
  
  t << equal<expect>(value.requred1, 4321) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.requred2, "~Ё你 привет мир") << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional1, 11) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional2, "") << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.requred3, 123) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.optional3, "~Ё你 привет мир") << FAS_TESTING_FILE_LINE;
  t << equal<assert,  size_t>(value.vect1.size(), 1) << std::endl <<  value.vect1.size() <<  std::endl << FAS_TESTING_FILE_LINE;
  t << stop;
  t << equal<expect>(value.vect1[0].requred3, 123) << FAS_TESTING_FILE_LINE;
  t << equal<expect>(value.vect1[0].optional3, "~Ё你 привет мир") << FAS_TESTING_FILE_LINE;  
  t << nothing();
}


BEGIN_SUITE(object_suite, "")
  ADD_UNIT(object1_unit)
  ADD_UNIT(object2_unit)
  ADD_UNIT(object3_unit)
END_SUITE(object_suite)
