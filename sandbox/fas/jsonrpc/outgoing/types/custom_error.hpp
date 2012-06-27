#ifndef FAS_JSONRPC_OUTGOING_TYPES_CUSTOM_ERROR_HPP
#define FAS_JSONRPC_OUTGOING_TYPES_CUSTOM_ERROR_HPP

#include <fas/jsonrpc/outgoing/json/error_code_json.hpp>
#include <fas/jsonrpc/error_code.hpp>

#include <string>

namespace fas{ namespace jsonrpc{ 

// for serialize only 
struct custom_error
{
  int code;
  std::string message;

  custom_error()
    : code(0)
  {
  }

  custom_error(error_code::type code)
    : code(code)
  {
    _init( code, error_code_json::target_list() );
  }
  
  custom_error(int code, const std::string& message )
    : code(code)
    , message(message)
  {
  }
  
private:

  template< typename T >
  void _init( int code, T )
  {
    _init(code, type_list< typename T::left_type, typename T::right_type >() );
  }

  template< typename L, typename R >
  void _init( int code, type_list<L, R> )
  {
    if ( L::value == code )
      message = typename L::target()();
    else
      _init( code, R() );
  }
   
  void _init( int code, empty_list )
  {
    this->code = code;
    message = "Unknown error.";
  }

};


}}

#endif
