#include <string>

struct request
{
  int oid;
  int offset;
  int limit;
  
  static request init()
  {
    request r;
    r.oid = 123456789;
    r.offset = 1000;
    r.limit = 1000;
    return r;
  }

  static const char* json()
  {
    return "{\"oid\":123456789,\"offset\":1000,\"limit\":1000}";
  }

};

typedef long response;
