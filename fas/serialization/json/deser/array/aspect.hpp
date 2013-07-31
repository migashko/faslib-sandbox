#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/deser/array/tags.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/array/ad_item.hpp>
#include <fas/serialization/json/deser/array/ad_process_item.hpp>
#include <fas/serialization/json/deser/array/ad_process_sequence_items.hpp>
#include <fas/serialization/json/deser/array/ad_sequence_items.hpp>
#include <fas/serialization/json/deser/array/ad_array.hpp>


namespace fas{ namespace json{ namespace deser{ namespace array{

struct aspect:
  ::fas::aspect< type_list_n<
    alias<_item_,  ::fas::serialization::_entity_>,
    alias<_array_, ::fas::serialization::_entity_>,
    alias<_sequence_items_, ::fas::serialization::_sequence_each_>
    //advice< _item_, ad_item >,
//    advice< _process_item_, ad_process_item>,
//    advice< _process_sequence_items_, ad_process_sequence_items>,
//    advice< _sequence_items_, ad_sequence_items >,
//    advice< _sequence_items_, ad_process_sequence_items >,
    //advice< _array_, ad_array >
  >::type >
{};

}}}}

#endif
