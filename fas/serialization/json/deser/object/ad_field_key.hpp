#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_KEY_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_AD_FIELD_KEY_HPP

#include <fas/serialization/deser/ad_target_n.hpp>
#include <fas/integral/int_.hpp>

namespace fas{ namespace json{ namespace deser{

using ::fas::serialization::deser::ad_target_n;

struct ad_field_key: 
  ad_target_n<int_<0> >
{};

}}}

#endif