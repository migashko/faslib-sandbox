//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ARRAY_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_entity.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace json{ namespace parse{

struct ad_array:
  ::fas::serialization::parse::ad_entity< type_list_n<
      _left_bracket_,
      _array_content_,
      _right_bracket_
  >::type >
{};

}}}

#endif
