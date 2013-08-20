#include "types.hpp"
#include <fas/typemanip.hpp>
#include <fas/range.hpp>
#include <fas/serialization/json/meta.hpp>
#include <fas/serialization/json/deserializer.hpp>
#include <iostream>
namespace aj = ::fas::json;

FAS_NAME(oid)
FAS_NAME(offset)
FAS_NAME(limit)

FAS_NAME(secret)
FAS_NAME(name)
FAS_NAME(description)
FAS_NAME(data)
FAS_NAME(x)
FAS_NAME(y)

typedef aj::object< fas::type_list_n<

  aj::mem_field< n_oid, request, int, &request::oid, aj::integer<> >,
  aj::mem_field< n_offset, request, int, &request::offset, aj::integer<> >,
  aj::mem_field< n_limit, request, int, &request::limit, aj::integer<> >
  
>::type> request_json;

typedef aj::object< fas::type_list_n<
  aj::mem_field< n_x, point, int, &point::x, aj::integer<> >,
  aj::mem_field< n_y, point, int, &point::y, aj::integer<> >
>::type> point_json;


typedef aj::object< fas::type_list_n<
  aj::mem_field< n_secret,       response, response::secret_type, &response::secret,      aj::string<> >,
  aj::mem_field< n_name,         response, std::string,           &response::name,        aj::string<> >,
  aj::mem_field< n_description,  response, std::string,           &response::description, aj::string<> >,
  aj::mem_field< n_data,         response, response::data_type,   &response::data,        aj::array<point_json> >
>::type> response_json;


void fasjson_serialize(request*, bool){}
void fasjson_serialize(response*, bool){}
int gint = 0;
void fasjson_deserialize(request* r, bool)
{
  //aj::deserializer<>()(request_json(), *r, fas::srange( request::json() ) );
  aj::deserializer<>()(request_json(), *r, request::json() );
  
  //aj::deserializer<>()(request_json(), *r, fas::range( request::json(), request::json() + strlen(request::json())));
  // aj::deserializer<> d;
  // d.get_aspect().get<fas::serialization::_status_>()=true;
  //d.get_aspect().get<aj::_object_>()(d, request_json(), *r, fas::srange( request::json() ));
  //std::cout << r->offset << std::endl;
  //static const char ch[]="12345 ";
  //aj::deserializer<> d;
  //d.get_aspect().get<aj::_integer_>()(d, aj::integer<>(), gint, ch );
  //int x = 0;
  
  //aj::deserializer<>().get_aspect().get<aj::_integer_>().toto(  gint, ch );
  //fas::serialization::deser::ad_integer().toto(  gint, ch );
}
void fasjson_deserialize(response* r, bool)
{
  //aj::deserializer<>()(response_json(), *r, fas::srange( response::json() ) ); 
  aj::deserializer<>()(response_json(), *r,  response::json()  );
  /*std::cout << r->description << std::endl;
  std::cout << r->data.size() << std::endl;
  std::cout << r->data[0].x << std::endl;*/
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
