#include <fas/testing.hpp>
#include <fas/serialization/json/deserializer.hpp>

#include <fas/serialization/json/meta.hpp>
#include <fas/serialization/meta.hpp>
#include <fas/type_list.hpp>
#include <fas/typemanip.hpp>
 
namespace aj = ::fas::json;
namespace as = ::fas::serialization;

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  int value = -1;
  char json[]="12345";
  aj::deserializer<> deser;
  //deser(aj::integer< as::maximum< fas::int_<12345> > >(), value, fas::srange(json) );
  
  typedef aj::value< fas::type_list_n<
    aj::integer,
    as::maximum< fas::int_<12345> >
  >::type > integer_json;
  
  deser( integer_json(), value, fas::srange(json) );
  std::cout << value << std::endl;
  t << nothing();
}

FAS_NAME(name)
UNIT(deser2_unit, "")
{
  using namespace fas::testing;
  
  int value = -1;
  char json[]="\"name\"";
  aj::deserializer<> deser;
  deser( aj::name<n_name>(), value, fas::srange(json) );
  std::cout << value << std::endl;
  t << nothing();
}

UNIT(deser2_1_unit, "")
{
  using namespace fas::testing;

  std::string value;
  char json[]="\"name\"";
  aj::deserializer<> deser;
  deser( aj::string(), value, fas::srange(json) );
  std::cout << value << std::endl;
  t << nothing();
}

UNIT(deser3_unit, "")
{
  using namespace fas::testing;

  int value = -1;
  char json[]="\"name\":12345/* */  /**/";
  aj::deserializer<> deser;
  try{
  deser( aj::attr< aj::name<n_name>, aj::integer >(), value, fas::srange(json) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << value << std::endl;
  t << nothing();
}

UNIT(deser4_unit, "")
{
  using namespace fas::testing;

  std::string value;
  char json[]="\"name\":\"~Ё你 привет мир\"/* */  /**/";
  aj::deserializer<> deser;
  try{
  deser( aj::attr< aj::name<n_name>, aj::string >(), value, json );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << value << std::endl;
  t << nothing();
}

FAS_NAME(member1)
FAS_NAME(member2)
struct object
{
  int member1;
  std::string member2;
};

typedef aj::acc< ::fas::member<object, int, &object::member1>, aj::integer > acc_member1;
typedef aj::acc< ::fas::member<object, std::string, &object::member2>, aj::string > acc_member2;
typedef aj::attr< aj::name<n_member1>, aj::acc< ::fas::member<object, int,&object::member1>, aj::integer > > member1;
typedef aj::attr< aj::name<n_member2>, aj::acc< ::fas::member<object, std::string, &object::member2>, aj::string > > member2;

typedef aj::object< ::fas::type_list_n<
  member1,
  member2
>::type > object_json;


UNIT(deser5_unit, "")
{
  using namespace fas::testing;

  object value;
  char json[]="    /*  */  \"member2\"  /* */ :  /**/ \"~Ё你 привет мир\"/* */  /**/ ";
  aj::deserializer<> deser;
  try{
  deser( member2(), value, fas::srange(json) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.member2 << std::endl;

  value = object();
  //char json2[]=" {   /*  */  \"member2\"  /* */ :  /**/ \"~Ё你 привет мир\"/* */  /**/,  /*  */  \"member1\"  /* */ :  /**/ 4321* */  /**/ }";
  char json2[]="{   \"member4\"  /* */ :  null, /*  */  \"member2\"  /* */ :  /**/ \"~Ё你 привет мир\"/* */  /**/,  /*  */  \"member1\"  /* */ :  /**/ 4321 /**/  /**/ }";
  //char json2[]="{   /*  */  \"member1\"  /* */ :  /**/ 4321 /**/  /**/ ,  /*  */  \"member2\"  /* */ :  /**/ \"~Ё你 привет мир\"/* */  /**/ }";
  try{
  deser( object_json(), value, fas::srange(json2) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json2) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.member1 <<  std::endl << value.member2 << std::endl;
  t << nothing();
}

UNIT(deser6_unit, "")
{
  using namespace fas::testing;

  std::vector<std::string> value;
  char json[]="[\"value1\",\"value3\"]";
  aj::deserializer<> deser;
  try{
    deser( aj::array< aj::string >(), value, fas::srange(json) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.size(); 
  std::cout << std::endl << value[0] << std::endl << value[1] << std::endl;
  t << nothing();
}

typedef aj::array< aj::array_list< fas::type_list_n<
  aj::item< acc_member1 >,
  aj::item< acc_member2 >
>::type > > array2object;
UNIT(deser7_unit, "")
{
  using namespace fas::testing;

  object value;
  char json[]="[12345,\"value3\"]";
  aj::deserializer<> deser;
  try{
    deser( array2object(), value, fas::srange(json) );
  }
  catch(fas::serialization::exception& e)
  {
    std::cout << e.message( fas::srange(json) ) << std::endl;
    abort();
    throw e;
  }
  std::cout << std::endl << value.member1 <<  std::endl << value.member2 << std::endl;
  t << nothing();
}

BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
  ADD_UNIT(deser2_unit)
  ADD_UNIT(deser2_1_unit)
  ADD_UNIT(deser3_unit)
  ADD_UNIT(deser4_unit)
  ADD_UNIT(deser5_unit)
/*  ADD_UNIT(deser6_unit)
  ADD_UNIT(deser7_unit)*/
END_SUITE(deser_suite)
