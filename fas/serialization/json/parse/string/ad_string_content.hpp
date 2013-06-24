//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/parse/ad_json_string_content.hpp>

namespace fas{ namespace json{ namespace parse{

/*
struct ad_string_content:
  ::fas::serialization::parse::ad_json_string_content<
    _utf8_letter_,
    _control_character_,
    _four_hex_digits_,
    _quote_
  >
{};
*/

struct ad_escapes: 
  ::fas::serialization::parse::ad_entity< type_list_n<
    _backslash_,
    _control_character_
  >::type>
{};

struct ad_uhex: 
  ::fas::serialization::parse::ad_entity< type_list_n<
    _backslash_u_,
    _four_hex_digits_
  >::type>
{};


struct ad_string_element:
  ::fas::serialization::parse::ad_variant< type_list_n<
    _uhex_,
    _escapes_,
    _utf8_letter_
  >::type >
{};

struct ad_string_content: 
  ::fas::serialization::parse::ad_sequence< 
    _string_element_,
    _quote_
  >
{};

}}}

#endif
