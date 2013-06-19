//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_OBJECT_FIELD_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_OBJECT_FIELD_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_sequence.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace json{ namespace parse{

/*
struct ad_object_separator:
  ::fas::serialization::parse::ad_variant< type_list_n<
    _comma_,
    _empty_
  >::type >
{};
*/

struct ad_object_field:
  ::fas::serialization::parse::ad_sequence< type_list_n<
                _space_,
      _string_, _space_,
      _colon_,  _space_,
      _value_,  _space_,
      _sequence_separator_
  >::type >
{};


}}}

#endif
