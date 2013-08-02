#include "types.hpp"
#include <cstdio>

void sprintf_serialize(request*, bool){}
void sprintf_serialize(response*, bool){}
void sprintf_deserialize(request* r, bool)
{
  //"{\"oid\":123456789,\"offset\":1000,\"limit\":1000}"
  sscanf(request::json(), "{\"oid\":%d,\"offset\":%d,\"limit\":%d}", &r->oid, &r->offset, &r->limit);
}
void sprintf_deserialize(response*, bool){}


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
