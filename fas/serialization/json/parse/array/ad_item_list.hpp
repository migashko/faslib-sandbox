//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ITEM_LIST_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ITEM_LIST_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_list.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_item_list:
  ::fas::serialization::parse::ad_list<
    _array_item_,
    /*_comma_,*/
    _right_bracket_
  >
{};

}}}

#endif
