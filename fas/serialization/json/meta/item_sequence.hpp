#ifndef FAS_SERIALIZATION_JSON_META_ITEM_SEQUENCE_HPP
#define FAS_SERIALIZATION_JSON_META_ITEM_SEQUENCE_HPP

namespace fas{ namespace json{

template<typename Target, typename Alt = ignore_item>
struct item_sequence
{
  typedef type_list< element< item< Target > > > target_list;
  //typedef _sequence_items_ tag;
  typedef Alt alt_target;
  
  // TODO: alias на _sequence_items_
  // typedef ::fas::serialization::_sequence_each_ tag;
  typedef _sequence_items_ tag;
  typedef ::fas::json::parse::_right_bracket_ stop_tag;
};


template<typename TargetList, typename Alt = ignore_item>
struct item_sequence_ex
{
  typedef typename normalize<TargetList>::type target_list;
  //typedef _sequence_items_ tag;
  typedef Alt alt_target;
  
  // TODO: alias на _sequence_items_
  // typedef ::fas::serialization::_sequence_each_ tag;
  typedef _sequence_items_ tag;
  typedef ::fas::json::parse::_right_bracket_ stop_tag;
};



}}

#endif
