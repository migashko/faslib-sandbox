#ifndef FAS_SERIALIZATION_JSON_META_ITEM_HPP
#define FAS_SERIALIZATION_JSON_META_ITEM_HPP

#include <fas/serialization/json/tags.hpp>


namespace fas{ namespace json{

template< typename Target>
struct item
{
  typedef Target target;
  typedef _item_ tag;
  
  /*
  typedef typename type_list_n<
    parse_skip< ::fas::json::parse::_space_>,
    Target,  // Убрать target, вставить реальный Target
    parse_skip< ::fas::json::parse::_space_>,
    parse_skip< ::fas::json::parse::_sequence_separator_>
  >::type entity_list;
  */
};

}}

#endif
