//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_ARRAY_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_ARRAY_ASPECT_HPP

#include <fas/serialization/json/parse/array/ad_left_bracket.hpp>
#include <fas/serialization/json/parse/array/ad_right_bracket.hpp>
#include <fas/serialization/json/parse/array/ad_array_item.hpp>
#include <fas/serialization/json/parse/array/ad_item_list.hpp>
#include <fas/serialization/json/parse/array/ad_array.hpp>
#include <fas/serialization/json/parse/array/ad_array_content.hpp>
#include <fas/serialization/json/parse/array/tags.hpp>

namespace fas{ namespace json{ namespace parse{ namespace array{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _left_bracket_, ad_left_bracket>,
    advice< _array_item_, ad_array_item>,
    advice< _array_content_, ad_array_content>,
    advice< _item_list_, ad_item_list>,
    advice< _right_bracket_, ad_right_bracket>,
    advice< _array_, ad_array>
  >::type > 
{};

}}}}

#endif
