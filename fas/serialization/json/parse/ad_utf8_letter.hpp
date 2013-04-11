#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_UTF8_LETTER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_UTF8_LETTER_HPP

#include <fas/serialization/json/except/try_throw.hpp>
#include <fas/serialization/json/except/unexpected_end_fragment.hpp>
#include <fas/serialization/json/except/parse_error.hpp>
#include <fas/serialization/json/except/out_of_range.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace json{ namespace parse{

namespace impl {
#include <fas/serialization/aux/parse/ad_utf8_letter.cls>
}

typedef impl::ad_utf8_letter ad_utf8_letter;

}}}

#endif
