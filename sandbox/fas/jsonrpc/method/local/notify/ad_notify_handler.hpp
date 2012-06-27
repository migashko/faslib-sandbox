#ifndef FAS_JSONRPC_METHOD_AD_NOTIFY_HANDLER_HPP
#define FAS_JSONRPC_METHOD_AD_NOTIFY_HANDLER_HPP

#include <fas/jsonrpc/method/tags.hpp>
//#include <fas/jsonrpc/method/error/tags.hpp>

namespace fas{ namespace jsonrpc{ namespace local{

struct ad_notify_handler
{
  template<typename T, typename M, typename V>
  void operator()(T& t, M& method, const V& v)
  {
    try
    {
      method.get_aspect().template get<_notify_>()(t, method, v);
      t.get_aspect().template get<_empty_send_>()( t );
    }
    catch(const std::exception& e)
    {
      method.get_aspect().template get<_notify_except_>()(t, method, v, e);
    }
    catch(...)
    {
      method.get_aspect().template get<_notify_except_>()(t, method, v);
    }
  }
};

}}}

#endif
