//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_ASPECT_HPP

#include <fas/serialization/json/parse/ad_number.hpp>
#include <fas/serialization/json/parse/ad_utf8_letter.hpp>
#include <fas/serialization/json/parse/ad_four_hex_digits.hpp>
#include <fas/serialization/json/parse/ad_quote.hpp>
#include <fas/serialization/json/parse/ad_control_character.hpp>
#include <fas/serialization/json/parse/ad_string_content.hpp>
#include <fas/serialization/json/parse/ad_string.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

typedef fas::aspect< type_list_n<
      advice< _number_, ad_number>,
      advice< _utf8_letter_, ad_utf8_letter>,
      advice< _four_hex_digits_, ad_four_hex_digits>,
      advice< _quote_, ad_quote>,
      advice< _control_character_, ad_control_character>,
      advice< _string_content_, ad_string_content>,
      advice< _string_, ad_string>
>::type > aspect;


}}}

#endif
