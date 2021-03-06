#include <fas/range.hpp>
#include <fas/xtime.hpp>

#include "benchmark.hpp"
#include <sstream>
#include <iostream>

#include "jsoncpp/json/json.h"

int main()
{
  Person pp;
  Json::Value person;
  Json::Reader reader;

  std::string str = "{\"id\":100,\"name\":\"Name\",\"email\":\"email@example.com\"}";
  fas::nanospan start = fas::process_nanotime();

  for (size_t i = 0; i < TOTAL_OP / 10; ++i)
  {
    reader.parse( str, person, false );
    pp.id = person["id"].asInt();
    pp.name = person["name"].asString();
    pp.email = person["email"].asString();

  }
  fas::nanospan finish = fas::process_nanotime();
  std::cout << ( finish - start ) * 10 ;
  std::clog << std::endl << person["id"] << std::endl
                         << person["name"] << std::endl
                         << person["email"] << std::endl;
  return 0;
}
