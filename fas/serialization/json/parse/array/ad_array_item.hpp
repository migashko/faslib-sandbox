//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_ITEM_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_ITEM_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_entity.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace json{ namespace parse{

  /*
struct ad_array_separator:
  ::fas::serialization::parse::ad_variant< type_list_n<
    _comma_,
    _empty_
  >::type >
{};
*/

struct ad_array_item:
  ::fas::serialization::parse::ad_entity< type_list_n<
      _space_,
      _value_,
      _space_,
      _sequence_separator_
  >::type >
{};

}}}

#endif
