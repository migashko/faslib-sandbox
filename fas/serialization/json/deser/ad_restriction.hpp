#ifndef FAS_SERIALIZATION_JSON_DESER_AD_RESTRICTION_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_RESTRICTION_HPP

#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/common/deser/ad_restriction.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_restriction:
  ::fas::serialization::common::deser::ad_restriction< _except_ >
{};

}}}

#endif
