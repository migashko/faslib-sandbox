#ifndef FAS_JSONRPC_METHOD_REQUEST_AD_REQUEST_HANDLER_HPP
#define FAS_JSONRPC_METHOD_REQUEST_AD_REQUEST_HANDLER_HPP

#include <fas/jsonrpc/method/local/request/tags.hpp>

namespace fas{ namespace jsonrpc{ namespace local{

struct ad_request_handler
{
  template<typename T, typename M, typename V>
  void operator()(T& t, M& method, const V& v, int id)
  {
    try
    {
      method.get_aspect().template get<_request_>()(t, method, v, id);
    }
    catch(const std::exception& e)
    {
      method.get_aspect().template get<_request_except_>()(t, method, v, e, id);
    }
    catch(...)
    {
      method.get_aspect().template get<_request_except_>()(t, method, v, id);
    }
  }
};


}}}

#endif
