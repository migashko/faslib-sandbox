#ifndef FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_PROCESS_SEQUENCE_ITEMS_HPP
#define FAS_SERIALIZATION_JSON_DESER_ARRAY_AD_PROCESS_SEQUENCE_ITEMS_HPP

#include <fas/serialization/deser/ad_sequence.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/json/deser/array/tags.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::ad_sequence1;

struct ad_process_sequence_items:
  ad_sequence1<
    _process_item_,
    ::fas::json::parse::_right_bracket_
  >    
{};

}}}

#endif
