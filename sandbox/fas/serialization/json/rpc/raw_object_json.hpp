#ifndef FAS_SERIALIZATION_JSON_RPC_RAW_OBJECT_JSON_HPP
#define FAS_SERIALIZATION_JSON_RPC_RAW_OBJECT_JSON_HPP

#include <fas/serialization/json/rpc/raw_object.hpp>
#include <fas/serialization/json/rpc/names.hpp>

#include <fas/serialization/json/meta.hpp>

#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace json{ namespace rpc{

typedef object<
  type_list_n<
    field< n_jsonrpc,attr< raw_object, raw_object::version_type, &raw_object::version, string  > >,
    field< n_method, attr< raw_object, raw_object::method_type, &raw_object::method, string  > >,
    field< n_params, attr< raw_object, raw_object::raw_type,    &raw_object::params, raw     > >,
    field< n_id,     attr< raw_object, int,                     &raw_object::id,     integer > >,
    field< n_result, attr< raw_object, raw_object::raw_type,    &raw_object::result, raw     > >,
    field< n_error,  attr< raw_object, raw_object::raw_type,    &raw_object::error,  raw     > >
  >::type
> raw_object_json_type;

typedef readonly< raw_object_json_type > raw_object_json;

}}}

#endif