#ifndef FAS_SERIALIZATION_JSON_DESER_AD_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_INTEGER_HPP

#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/common/deser/ad_integer.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_integer:
  ::fas::serialization::common::deser::ad_integer< parse::_number_ >
{};

}}}

#endif
