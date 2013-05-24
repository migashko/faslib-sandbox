//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_ITEM_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_ITEM_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/parse/ad_sequence.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace json{ namespace parse{

struct ad_array_item:
  ::fas::serialization::common::parse::ad_sequence<
    type_list_n<
      _space_,
      _value_,
      _space_
    >::type,
    _except_
  >
{};

}}}

#endif
