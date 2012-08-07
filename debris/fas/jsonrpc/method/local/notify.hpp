#ifndef FAS_JSONRPC_METHOD_LOCAL_NOTIFY_HPP
#define FAS_JSONRPC_METHOD_LOCAL_NOTIFY_HPP

#include <fas/jsonrpc/method/local/notify/ad_parse_notify.hpp>
#include <fas/jsonrpc/method/local/notify/ad_notify_handler.hpp>
#include <fas/jsonrpc/method/local/notify/ad_notify_except.hpp>
#include <fas/jsonrpc/method/local/notify/tags.hpp>
#include <fas/jsonrpc/holder.hpp>

#include <fas/serialization/json/meta/null.hpp>

#include <fas/aop/advice.hpp>
#include <fas/aop/aspect.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace jsonrpc{ namespace local{

template<
  typename H,
  typename V = empty_type,
  typename J = ::fas::json::null,
  template< typename > class W = holder
>
struct notify: ::fas::aspect<  
  typename type_list_n<
    advice<_notify_, H >,
    advice< _parse_notify_,   ad_parse_notify< W<V>, J > >,
    advice< _notify_handler_, ad_notify_handler >,
    advice< _notify_except_,  ad_notify_except >
  >::type >
{};

  
}}}

#endif
