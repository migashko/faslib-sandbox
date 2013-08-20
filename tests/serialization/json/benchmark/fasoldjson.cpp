#include "types.hpp"
#include "fasold/fas/misc/json.hpp"
#include "fasold/fas/pattern/type_list.hpp"
#include <iostream>
namespace aj = ::fas::json;
namespace ap = ::fas::pattern;

#define FAS_NAME(X) struct n_##X { const char* operator()() const{ return #X;} };

FAS_NAME(oid)
FAS_NAME(offset)
FAS_NAME(limit)

FAS_NAME(secret)
FAS_NAME(name)
FAS_NAME(description)
FAS_NAME(data)
FAS_NAME(x)
FAS_NAME(y)

typedef aj::object< 
  request,
  ap::type_list_n<
  aj::member< n_oid, request, int, &request::oid>,
  aj::member< n_offset, request, int, &request::offset>,
  aj::member< n_limit, request, int, &request::limit >
>::type> request_json;

typedef aj::object<
  point, 
  ap::type_list_n<
    aj::member< n_x, point, int, &point::x >,
    aj::member< n_y, point, int, &point::y >
>::type> point_json;


typedef aj::object< 
  response,
  ap::type_list_n<
    aj::member< n_secret,       response, response::secret_type, &response::secret >,
    aj::member< n_name,         response, std::string,           &response::name >,
    aj::member< n_description,  response, std::string,           &response::description >,
    aj::member< n_data,         response, response::data_type,   &response::data,        
      aj::array< std::vector<point_json> > >
>::type> response_json;


void fasoldjson_serialize(request*, bool){}
void fasoldjson_serialize(response*, bool){}
int gint1 = 0;
void fasoldjson_deserialize(request* r, bool)
{
  request_json::serializer()( *r, request::json(), request::json() + strlen(request::json()) );
  //static const char ch[]="12345";
  //aj::value<int>::serializer()(gint1, ch, ch + strlen(ch) );

  //aj::deserializer<>()(request_json(), *r, fas::srange( request::json() ) );
}
void fasoldjson_deserialize(response* r, bool)
{
  response_json::serializer()( *r, response::json(), response::json() + strlen(response::json()) );
  //aj::deserializer<>()(response_json(), *r, fas::srange( response::json() ) );  
  //std::cout << r->description << std::endl;
  //std::cout << r->data.size() << std::endl;
  //std::cout << r->data[0].x << std::endl;
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
