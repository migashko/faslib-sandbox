#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_FOUR_HEX_DIGITS
#define FAS_SERIALIZATION_JSON_PARSE_AD_FOUR_HEX_DIGITS

#include <fas/serialization/json/except/try_throw.hpp>
#include <fas/serialization/json/except/unexpected_end_fragment.hpp>
#include <fas/serialization/json/except/parse_error.hpp>
#include <fas/serialization/json/except/out_of_range.hpp>
#include <fas/range/distance.hpp>
#include <utility>

namespace fas{ namespace json{ namespace parse{

namespace impl {
#include <fas/serialization/aux/parse/ad_four_hex_digits.cls>
}

typedef impl::ad_four_hex_digits ad_four_hex_digits;

}}}

#endif
