#include "types.hpp"
#include <cstdio>
#include <iostream>
#include <algorithm>

void sprintf_serialize(request*, bool){}
void sprintf_serialize(response*, bool){}
void sprintf_deserialize(request* r, bool)
{
  //"{\"oid\":123456789,\"offset\":1000,\"limit\":1000}"
  sscanf(request::json(), "{\"oid\":%d,\"offset\":%d,\"limit\":%d}", &r->oid, &r->offset, &r->limit);
}
void sprintf_deserialize(response* r, bool)
{
  const char *ch = response::json();
  char name[256]="\0";
  char description[256]="\0";
  r->data.clear();
  sscanf(ch, "{\"secret\":\"%7s\",\"name\":\"%19s\",\"description\":\"%33s\", \"data\":[", r->secret, name, description);
  ch = strchr( ch, '[') + 1;
  point p;
  for (int i=0; i < 100; ++i)
  {
    //std::cout << ch << std::endl;
    sscanf(ch, "{\"x\":%d,\"y\":%d}", &p.x, &p.y);
    ch = strchr( ch, '}') + 2;
    r->data.push_back(p);
  }
  //abort();
  /*
  char name[256]="\0";
  char description[256]="\0";
  std::string s = response::json();
  std::replace( s.begin(), s.end(), ' ', '-'); 
  r->data.clear();
  int pos = sscanf(s.c_str(), "{\"secret\":\"%7s\",\"name\":\"%19s\",\"description\":\"%33s\", \"data\":[", r->secret, name, description);
  point p;
  for (int i=0; i < 100; ++i)
  {
    std::cout << pos << " " << s.c_str() + pos << std::endl;
    pos += sscanf(s.c_str() + pos, "{\"x\":%d,\"y\":%d}", &p.x, &p.y);
    std::cout << pos << " " << p.x << " " << p.y << std::endl;
    r->data.push_back(p);
  }
  */
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
