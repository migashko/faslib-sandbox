#ifndef FAS_SERIALIZATION_JSON_DESER_AD_NAME_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_NAME_HPP


#include <fas/serialization/deser/ad_sequence.hpp>
#include <fas/serialization/proval/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_name:
  fas::serialization::deser::ad_sequence< type_list_n<
    fas::serialization::deser::parser< ::fas::json::parse::_quote_>,
    ::fas::json::deser::_equal_range_,
    fas::serialization::deser::parser< ::fas::json::parse::_quote_>
  >::type >
{};


}}}

#endif
