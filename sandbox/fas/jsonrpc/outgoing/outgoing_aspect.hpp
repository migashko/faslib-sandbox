#ifndef FAS_JSONRPC_OUTGOING_OUTGOING_ASPECT_HPP
#define FAS_JSONRPC_OUTGOING_OUTGOING_ASPECT_HPP

#include <fas/jsonrpc/outgoing/tags.hpp>
#include <fas/jsonrpc/outgoing/ad_send.hpp>
#include <fas/jsonrpc/outgoing/ad_empty_send.hpp>
#include <fas/jsonrpc/outgoing/ad_send_error.hpp>
#include <fas/jsonrpc/outgoing/ad_send_custom_error.hpp>
#include <fas/jsonrpc/outgoing/ad_send_result.hpp>
#include <fas/jsonrpc/outgoing/ad_send_notify.hpp>
#include <fas/jsonrpc/outgoing/ad_send_request.hpp>
#include <fas/jsonrpc/outgoing/ad_send_failed.hpp>

#include <fas/jsonrpc/outgoing/types/serializer.hpp>

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/aop/value_advice.hpp>
#include <fas/aop/type_advice.hpp>
#include <fas/aop/value_advice.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace jsonrpc{

struct outgoing_buffer: std::vector<char> {};
  
struct outgoing_list
 : type_list_n<
    advice<_send_, ad_send>,
    advice<_empty_send_, ad_empty_send>,
    advice<_send_common_error_, ad_send_error>,
    advice<_send_custom_error_, ad_send_custom_error>,
    advice<_send_result_, ad_send_result>,
    advice<_send_notify_, ad_send_notify>,
    advice<_send_request_, ad_send_request>,
    advice<_send_failed_, ad_send_failed>,
    type_advice< _serializer_, outgoing_serializer >,
    value_advice< _buffer_, outgoing_buffer >,
    alias<_empty_output_, _output_>,
    stub< _output_>
  >::type
{};


struct outgoing_aspect: ::fas::aspect< outgoing_list > { };

}}

#endif
