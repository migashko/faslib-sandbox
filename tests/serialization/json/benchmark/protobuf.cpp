#include "types.hpp"
#include "request.pb.h"

static char request_buffer[1000];
static size_t request_buffer_size = 0;

void protobuf_init()
{
  benchmark::request r;
  r.set_oid(1234567);
  r.set_offset(1000);
  r.set_limit(1000);
  request_buffer_size = r.SerializeToArray(request_buffer, 1000);
}

void protobuf_serialize(request*, bool){}
void protobuf_serialize(response*, bool){}
void protobuf_deserialize(request*, bool)
{
  benchmark::request r;
  r.ParseFromArray(request_buffer, request_buffer_size);
  
}
void protobuf_deserialize(response*, bool){}


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
