#ifndef FAS_JSONRPC_INBOUND_ERROR_AD_PARSE_ERROR_HPP
#define FAS_JSONRPC_INBOUND_ERROR_AD_PARSE_ERROR_HPP

#include <fas/jsonrpc/outgoing/tags.hpp>
#include <fas/jsonrpc/error_code.hpp>

namespace fas{ namespace jsonrpc{ 

struct ad_parse_error
{
  template<typename T>
  void operator() (T& t, int id)
  {
    t.get_aspect().template get<_send_common_error_>()( t, error_code::parse_error, id );
  }

  template<typename T>
  void operator() (T& t)
  {
    t.get_aspect().template get<_send_common_error_>()( t, error_code::parse_error );
  }
};

}}

#endif
