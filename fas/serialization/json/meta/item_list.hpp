#ifndef FAS_SERIALIZATION_JSON_META_ITEM_LIST_HPP
#define FAS_SERIALIZATION_JSON_META_ITEM_LIST_HPP

#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{

template< typename TargetList>
struct item_list
{
  typedef TargetList target_list;
  typedef _item_list_ tag;
};

}}

#endif
