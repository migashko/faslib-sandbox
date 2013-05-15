//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_RIGHT_BRACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_RIGHT_BRACE_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_tstring.hpp>
#include <fas/typemanip/tchars.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_right_brace:
  ::fas::serialization::common::parse::ad_tstring< 
    tchars<'}'>,
    _except_
  >
{};

}}}

#endif