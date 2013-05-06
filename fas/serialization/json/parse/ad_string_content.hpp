//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/common/parse/ad_json_string_content.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_string_content:
  ::fas::serialization::common::parse::ad_json_string_content<
    _utf8_letter_,
    _control_character_,
    _four_hex_digits_,
    _quote_,
    _except_
  >
{};

}}}

#endif
