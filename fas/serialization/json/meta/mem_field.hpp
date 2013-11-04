#ifndef FAS_SERIALIZATION_JSON_META_MEM_FIELD_HPP
#define FAS_SERIALIZATION_JSON_META_MEM_FIELD_HPP

#include <fas/serialization/json/meta/name.hpp>
#include <fas/serialization/json/meta/acc.hpp>
#include <fas/functional/member.hpp>

namespace fas{ namespace json{

template<typename TString, typename V, typename VT, VT V::* m, typename Value>
struct mem_field
  : field< name<TString>, acc< member<V, VT, m>, Value> >
{
};

}}

#endif
