#ifndef FAS_SERIALIZATION_JSON_PARSE_ASPECT_TYPE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_ASPECT_TYPE_HPP

#include <fas/serialization/json/parse/ad_number.hpp>
#include <fas/serialization/json/parse/ad_utf8_letter.hpp>
#include <fas/serialization/json/parse/ad_four_hex_digits.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

typedef aspect< type_list_n<
      advice< _number_, ad_number>,
      advice< _utf8_letter_, ad_utf8_letter>,
      advice< _four_hex_digits_, ad_four_hex_digits>
>::type > aspect_type;


}}}

#endif
