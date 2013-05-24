//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_EMPTY_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_EMPTY_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/parse/ad_empty.hpp>
#include <fas/typemanip/tchars.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_empty:
  ::fas::serialization::common::parse::ad_empty
{};

}}}

#endif
