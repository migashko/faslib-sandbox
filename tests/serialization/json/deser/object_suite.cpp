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

namespace object1_json
{
  
using namespace ::fas::json;
  
FAS_NAME(requred1)
FAS_NAME(requred2)
FAS_NAME(optional1)
FAS_NAME(optional2)

typedef object< ::fas::type_list_n<
  attr< 
    name<n_requred1>, 
    acc< fas::member<object1, int, &object1::requred1>, integer>
  >,
  attr< 
    name<n_requred2>, 
    acc< fas::member<object1, std::string, &object1::requred2>, string>
  >
>::type > object1_json;

}

UNIT(object1_unit, "")
{
  using namespace fas::testing;
  aj::deserializer<> deser;

  object1 value ;
  char json2[]="{   \"member4\"  /* */ :  null, /*  */  \"requred2\"  /* */ :  /**/ \"~Ё你 привет мир\"/* */  /**/,  /*  */  \"requred1\"  /* */ :  /**/ 4321 /**/  /**/ }";
  try{
    deser( object1_json::object1_json(), value, fas::srange(json2) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json2) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.requred1 <<  std::endl << value.requred2 << std::endl;
  t << equal<expect>(value.requred1, 4321);
  t << equal<expect>(value.requred2, "~Ё你 привет мир");
  t << nothing();
}



BEGIN_SUITE(object_suite, "")
  ADD_UNIT(object1_unit)
END_SUITE(object_suite)
