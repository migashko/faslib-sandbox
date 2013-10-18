#ifndef FAS_SERIALIZATION_JSON_META_MEM_FIELD_HPP
#define FAS_SERIALIZATION_JSON_META_MEM_FIELD_HPP

//#include <fas/serialization/json/tags.hpp>
//#include <fas/type_list/normalize.hpp>
//#include <fas/typemanip/if_c.hpp>
//#include <fas/typemanip/member.hpp>
//#include <fas/type_list/is_type_list.hpp>
//#include <fas/type_list/empty_list.hpp>
//#include <fas/type_list/type_list_n.hpp>
//#include <fas/range.hpp>

//#include "sequence.hpp"

//#include <fas/serialization/json/parse/tags.hpp>

// ---
//#include <fas/serialization/meta/container.hpp>
//#include <fas/serialization/json/meta/acc.hpp>


//#include <fas/serialization/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>
#include <fas/serialization/json/meta/acc.hpp>
#include <fas/typemanip/member.hpp>


namespace fas{ namespace json{


template<typename TString, typename V, typename VT, VT V::* m, typename Value>
struct mem_field
  : field< name<TString>, acc< member<V, VT, m>, Value> >
{
};

}}

#endif
