#ifndef FAS_SERIALIZATION_JSON_META_FIELD_HPP
#define FAS_SERIALIZATION_JSON_META_FIELD_HPP

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
#include <fas/serialization/json/tags.hpp>


namespace fas{ namespace json{


template<typename Name, typename Value>
struct field
{
  typedef Name key;
  typedef Value value;
  
  //typedef typename type_list_n<Name, Value>::type target_list;
  
  typedef _field_ tag;
  
  /*
  typedef typename type_list_n<
    parse_skip< ::fas::json::parse::_space_>,
    Name,
    parse_skip< ::fas::json::parse::_space_>,
    parse_skip< ::fas::json::parse::_colon_>,
    parse_skip< ::fas::json::parse::_space_>,
    Value,
    parse_skip< ::fas::json::parse::_space_>,
    parse_skip< ::fas::json::parse::_sequence_separator_>
  >::type entity_list;
  */
};


}}

#endif
