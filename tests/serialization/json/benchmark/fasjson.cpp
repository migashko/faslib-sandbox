#include "types.hpp"
#include <fas/typemanip.hpp>
#include <fas/range.hpp>
#include <fas/serialization/json/meta.hpp>
#include <fas/serialization/json/deserializer.hpp>

namespace aj = ::fas::json;

FAS_NAME(oid)
FAS_NAME(offset)
FAS_NAME(limit)

typedef aj::object< fas::type_list_n<
  aj::mem_field< n_oid, request, int, &request::oid, aj::integer<> >
>::type> request_json;

void fasjson_serialize(request*, bool){}
void fasjson_serialize(response*, bool){}
void fasjson_deserialize(request* r, bool)
{
  aj::deserializer<>()(request_json(), *r, fas::srange( request::json() ) );
}
void fasjson_deserialize(response*, bool){}


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
