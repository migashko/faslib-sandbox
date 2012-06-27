#ifndef FAS_JSONRPC_METHOD_REQUEST_AD_PARSE_REQUEST_HPP
#define FAS_JSONRPC_METHOD_REQUEST_AD_PARSE_REQUEST_HPP

#include <fas/jsonrpc/inbound/tags.hpp>
#include <fas/jsonrpc/method/local/request/tags.hpp>

namespace fas{ namespace jsonrpc{ namespace local{

template<typename V, typename J>
struct ad_parse_request : V
{
  typedef V super;
  typedef V request_value;
  typedef J request_json;
  
  template<typename T, typename M, typename R>
  void operator()(T& t, M& method, R r, int id)
  {
    typedef typename T::aspect::template advice_cast<_deserializer_>::type deserializer;
    typename request_value::value_type value = super::operator()(t);

    std::cout << "ad_parse_request" << std::endl;
    
    register bool valid_id = !method.get_aspect().template get<_id_>().has(id);
    

    if ( valid_id )
      method.get_aspect().template get<_id_>().push(id);
    
    deserializer ds;
    ds( request_json(), value, r );
    
    if ( !ds )
    {
      std::cout << "!id" << std::endl;
      if ( valid_id )
        method.get_aspect().template get<_id_>().pop(id);
      
      t.get_aspect().template get<_invalid_request_>()(t, id);
    }
    else if ( !valid_id)
    {
      std::cout << "!valid_id" << std::endl;
      method.get_aspect().template get<_invalid_request_id_>()(t, method, value, id);
    }
    else 
      method.get_aspect().template get<_request_handler_>()(t, method, value, id); 
  }
};


}}}

#endif
