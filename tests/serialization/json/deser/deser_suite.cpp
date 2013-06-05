#include <fas/testing.hpp>
#include <fas/serialization/json/deserializer.hpp>

#include <fas/serialization/json/meta.hpp>
#include <fas/serialization/meta.hpp>
#include <fas/type_list/type_list_n.hpp>
#include <fas/typemanip/has_typename.hpp>
 
namespace aj = ::fas::json;
namespace as = ::fas::serialization;

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  int value = -1;
  char json[]="12345";
  aj::deserializer<> deser;
  deser(aj::integer< as::maximum< fas::int_<12345> > >(), value, fas::srange(json) );
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

UNIT(deser3_unit, "")
{
  using namespace fas::testing;

  int value = -1;
  char json[]="\"name\":12345/* */  /**/";
  aj::deserializer<> deser;
  try{
  deser( aj::attr< aj::name<n_name>, aj::integer<> >(), value, fas::srange(json) );
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

BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
  ADD_UNIT(deser2_unit)
  ADD_UNIT(deser3_unit)
END_SUITE(deser_suite)
