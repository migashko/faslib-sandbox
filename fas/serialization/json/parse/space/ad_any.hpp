//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ANY_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ANY_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_any_character.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_any:
  ::fas::serialization::common::parse::ad_any_character< ::fas::serialization::_except_>
{};

}}}

#endif
