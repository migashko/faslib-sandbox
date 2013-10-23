#ifndef FAS_SERIALIZATION_JSON_META_FIELD_LIST_HPP
#define FAS_SERIALIZATION_JSON_META_FIELD_LIST_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/meta/ignore.hpp>


namespace fas{ namespace json{

template< typename TargetList, typename Alt = ignore_field>
struct field_list
{
  // TODO: list categories
  typedef typename normalize<TargetList>::type target_list;
  typedef _field_list_ tag;
  typedef Alt alt_target; // TODO: 
  // typedef ::fas::json::parse::_right_brace_ stop_tag;
};

}}

#endif
