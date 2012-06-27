#ifndef FAS_SERIALIZATION_JSON_RPC_RAW_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_RPC_RAW_OBJECT_HPP

#include <vector>
#include <algorithm>

#include <fas/range/string_range.hpp>

namespace fas{ namespace json{ namespace rpc{
  
struct raw_object
{
  typedef std::vector<char> raw_type;
  typedef char method_type[128];
  typedef char version_type[8];

  int id;
  version_type version;
  method_type method;
  raw_type params;
  raw_type result;
  raw_type error;
  
  raw_object()
    : id(0)
  {
    std::fill_n(version, sizeof(version), 0);
    std::fill_n(method, sizeof(method), 0);
  }
  
  typedef string_range<const char*> name_range_type;
  name_range_type name_range() const { return name_range_type(method);}
  
  bool has_method() const { return method[0]!=0;}
  bool has_version() const { return version[0]!=0;}
  bool has_params() const { return !params.empty();}
  bool has_result() const { return !result.empty();}
  bool has_error() const { return !error.empty();}
  bool has_id() const { return id!=0;}
  
  bool is_request() const 
  { 
    return has_method() 
           && has_id() 
           && has_params() 
           && !has_result()
           && !has_error(); 
  }

  bool is_response() const 
  { 
    return !has_method() 
           && has_id() 
           && !has_params() 
           && has_result()
           && !has_error();
  }

  bool is_notify() const 
  { 
    return has_method() 
           && !has_id() 
           && has_params() 
           && !has_result()
           && !has_error(); 
  }

  bool is_error() const 
  { 
    return !has_method() 
           && !has_params() 
           && !has_result()
           && has_error(); 
  }
  
  bool is_valid() const
  {
    return is_request()
           || is_response()
           || is_notify()
           || is_error();
  }

};

  
}}}

#endif
