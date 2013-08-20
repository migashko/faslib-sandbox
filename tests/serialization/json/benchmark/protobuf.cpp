#include "types.hpp"
#include "request.pb.h"
#include <iostream>
static char request_buffer[1000];
static size_t request_buffer_size = 1000;

static char response_buffer[10000];
static size_t response_buffer_size = 10000;

void protobuf_init()
{
  benchmark::request r;
  r.set_oid(1234567);
  r.set_offset(1000);
  r.set_limit(1000);
  /*request_buffer_size = */r.SerializeToArray(request_buffer, 1000);
  std::cout << "1->" << request_buffer_size << std::endl;
  
  benchmark::response rs;
  rs.set_secret("XYZ1234");
  rs.set_name("просто-имя");
  rs.set_description("простой-description-中國-\r\n");
  
  /*benchmark::response p;
  rs.data.push_back(p);
  */
  for (int i=0; i < 100; ++i)
  {
    if ( benchmark::point* p = rs.add_data())
    {
      std::cout << size_t(p) << std::endl;
      p->set_x(12345);
      p->set_y(67890);
    }
    else
      abort();
  }
  /*response_buffer_size = */rs.SerializeToArray(response_buffer, 10000);
  std::cout << "->" << response_buffer_size << std::endl;
}

void protobuf_serialize(request*, bool){}
void protobuf_serialize(response*, bool){}
void protobuf_deserialize(request*, bool)
{
  benchmark::request r;
  r.ParseFromArray(request_buffer, request_buffer_size);
  
}
void protobuf_deserialize(response* r, bool)
{
  benchmark::response rs;
  rs.ParseFromArray(response_buffer, response_buffer_size);
  r->name = rs.name();
  r->description = rs.description();
  size_t s = rs.data().size();
  r->data.clear();
  r->data.resize(s);
  for (int i=0; i < 100; ++i)
  {
    //std::cout << s << " " <<  i << std::endl;
    r->data[i].x = rs.data().Get(i).x();
    r->data[i].y = rs.data().Get(i).y();
  }
  
}


/*
void empty_serialize(const request&, char*, size_t )
{
}

void empty_serialize(const request&, std::string& )
{
}

void empty_serialize(const response&, char*, size_t )
{
}

void empty_serialize(const response&, std::string& )
{
}

void empty_deserialize(const char*, size_t, request&)
{
}

void empty_deserialize( const std::string&, request& )
{
}

void empty_deserialize(const char*, size_t, response&)
{
}

void empty_deserialize( const std::string&, response& )
{
}
*/
