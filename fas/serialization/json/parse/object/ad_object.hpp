//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_OBJECT_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_entity.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace json{ namespace parse{

struct ad_object:
  ::fas::serialization::parse::ad_entity< type_list_n<
      _left_brace_,
      _object_content_,
      _right_brace_
  >::type >
{};

}}}

#endif
