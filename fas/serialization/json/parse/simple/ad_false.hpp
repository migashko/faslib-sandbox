//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_FALSE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_FALSE_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_tstring.hpp>
#include <fas/typemanip/tstring.hpp>

namespace fas{ namespace json{ namespace parse{

FAS_STRING(false_, "false")

struct ad_false:
  ::fas::serialization::common::parse::ad_tstring< 
    false_, 
    _except_
  >
{};

}}}

#endif