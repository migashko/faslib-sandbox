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
#include <fas/serialization/json/parse/ad_empty.hpp>
#include <fas/serialization/json/parse/ad_value.hpp>

#include <fas/serialization/json/parse/ad_null.hpp>
#include <fas/serialization/json/parse/ad_boolean.hpp>
#include <fas/serialization/json/parse/ad_true.hpp>
#include <fas/serialization/json/parse/ad_false.hpp>

#include <fas/serialization/json/parse/ad_comma.hpp>
#include <fas/serialization/json/parse/ad_left_bracket.hpp>
#include <fas/serialization/json/parse/ad_right_bracket.hpp>
#include <fas/serialization/json/parse/ad_left_brace.hpp>
#include <fas/serialization/json/parse/ad_right_brace.hpp>
#include <fas/serialization/json/parse/ad_array_item.hpp>
#include <fas/serialization/json/parse/ad_item_list.hpp>
#include <fas/serialization/json/parse/ad_array.hpp>

#include <fas/serialization/json/parse/ad_object_field.hpp>
#include <fas/serialization/json/parse/ad_field_list.hpp>
#include <fas/serialization/json/parse/ad_object.hpp>

#include <fas/serialization/json/parse/ad_any.hpp>
#include <fas/serialization/json/parse/ad_comment.hpp>
#include <fas/serialization/json/parse/ad_comment_content.hpp>
#include <fas/serialization/json/parse/ad_begin_comment.hpp>
#include <fas/serialization/json/parse/ad_end_comment.hpp>
#include <fas/serialization/json/parse/ad_white_space.hpp>
#include <fas/serialization/json/parse/ad_end_space.hpp>
#include <fas/serialization/json/parse/ad_space_variant.hpp>
#include <fas/serialization/json/parse/ad_space.hpp>

#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

struct aspect:
  ::fas::aspect< type_list_n<
    // null
    advice< _null_, ad_null>,
    // number
    advice< _number_, ad_number>,
    // string
    advice< _utf8_letter_, ad_utf8_letter>,
    advice< _four_hex_digits_, ad_four_hex_digits>,
    advice< _quote_, ad_quote>,
    advice< _control_character_, ad_control_character>,
    advice< _string_content_, ad_string_content>,
    advice< _string_, ad_string>,
    
    advice< _comma_, ad_comma>,
    
    advice< _left_bracket_, ad_left_bracket>,
    advice< _array_item_, ad_array_item>,
    advice< _item_list_, ad_item_list>,
    advice< _right_bracket_, ad_right_bracket>,
    advice< _array_, ad_array>,
    
    advice< _left_brace_, ad_left_brace>,
    advice< _right_brace_, ad_right_brace>,
    advice< _object_field_, ad_object_field>,
    advice< _field_list_, ad_field_list>,
    advice< _object_, ad_object>,
    
    // boolean
    advice< _true_, ad_true>,
    advice< _false_, ad_false>,
    advice< _boolean_, ad_boolean>,
    // value
    advice< _value_, ad_value>,
    // comment
    type_list_n<
      advice< _any_, ad_any>,
      advice< _empty_, ad_empty>,
      advice< _comment_, ad_comment>,
      advice< _comment_content_, ad_comment_content>,
      advice< _begin_comment_, ad_begin_comment>,
      advice< _end_comment_, ad_end_comment>,
      advice< _white_space_, ad_white_space>,
      advice< _end_space_, ad_end_space>,
      advice< _space_variant_, ad_space_variant>,
      advice< _space_, ad_space>
    >::type
    
    
  >::type > 
{};

}}}

#endif
