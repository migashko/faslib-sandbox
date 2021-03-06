#include <fas/range.hpp>
#include <fas/xtime.hpp>
#include <fas/serialization/json/serializer.hpp>
#include <fas/serialization/json/meta.hpp>

#include "benchmark.hpp"
  
#define MAX_BUF 1024
#include <iostream>

namespace aj = ::fas::json;

buffer_type buffer;


typedef aj::array<
  fas::type_list_n<
    aj::attr< Person2, int, &Person2::id, aj::integer >,
    aj::attr< Person2, Person2::name_type, &Person2::name, aj::string >,
    aj::attr< Person2, Person2::email_type, &Person2::email, aj::string >
  >::type
> array_json;

int main()
{
  Person2 t;
  t.id = 100;
  t.set_name("My Name");
  t.set_email("email@example.com");

  if ( !buffer )
    std::cout << "NO BUFFER" << std::endl;
  //fas::range_traits<buffer_type>::range r = fas::range( buffer );
  aj::serializer<> s;
  fas::nanospan start = fas::process_nanotime();
  //std::cout << buffer << std::endl;
  char * ptr = buffer;
  for (size_t i = 0; i < TOTAL_OP; ++i)
  {
    s( array_json(), t, ptr );
  }
  fas::nanospan finish = fas::process_nanotime();
  std::cout << finish - start << std::endl;
  std::cout << buffer << std::endl;
  //std::cout << benchmark(sl) /** static_cast<long>( sl.size() )*/ << std::endl;
  return 0;
}
