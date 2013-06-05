//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_STRING_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_STRING_ASPECT_HPP

#include <fas/serialization/parse/ad_utf8_letter.hpp>
// #include <fas/serialization/json/parse/string/ad_quote.hpp>
#include <fas/serialization/json/parse/string/ad_control_character.hpp>
#include <fas/serialization/json/parse/string/ad_string_content.hpp>
#include <fas/serialization/json/parse/string/ad_string.hpp>
#include <fas/serialization/json/parse/string/tags.hpp>

#include <fas/serialization/parse/ad_four_hex_digits.hpp>
#include <fas/serialization/parse/ad_tstring.hpp>

#include <fas/typemanip/tchars.hpp>


namespace fas{ namespace json{ namespace parse{ namespace string{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _utf8_letter_, ::fas::serialization::parse::ad_utf8_letter >,
    advice< _four_hex_digits_, ::fas::serialization::parse::ad_four_hex_digits >,
    advice< _quote_, ::fas::serialization::parse::ad_tstring< tchars<'"'> > >,
    advice< _control_character_, ad_control_character>,
    advice< _string_content_, ad_string_content>,
    advice< _string_, ad_string>
  >::type > 
{};

}}}}

#endif
