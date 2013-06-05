//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_FIELD_LIST_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_FIELD_LIST_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_list.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_field_list:
  ::fas::serialization::parse::ad_list<
    _object_field_,
    _comma_,
    _right_brace_
  >
{};

}}}

#endif
