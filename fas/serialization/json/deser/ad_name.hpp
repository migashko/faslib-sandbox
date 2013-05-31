#ifndef FAS_SERIALIZATION_JSON_DESER_AD_NAME_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_NAME_HPP


#include <fas/serialization/deser/ad_sequence.hpp>
#include <fas/serialization/proval/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_name:
  fas::serialization::deser::ad_sequence< type_list_n<
    ::fas::json::deser::_quote_,
    ::fas::json::deser::_equal_range_,
    ::fas::json::deser::_quote_
  >::type>
{};


}}}

#endif
