#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_INTEGER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_INTEGER_HPP

#include <fas/range/moke_range.hpp>
#include <fas/range/distance.hpp>
#include <fas/serialization/json/except/out_of_range.hpp>
#include <fas/serialization/json/except/unexpected_end_fragment.hpp>
#include <fas/serialization/json/except/parse_error.hpp>
#include <fas/serialization/json/except/try_throw.hpp>
#include <utility>

namespace fas{ namespace json{ namespace parse{

#include <fas/serialization/aux/parse/ad_json_number.cls>

typedef ad_json_number ad_number;

}}}

#endif
