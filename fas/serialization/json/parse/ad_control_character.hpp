//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_CONTROL_CHARACTER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_CONTROL_CHARACTER_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_charset.hpp>
#include <fas/typemanip/tstring.hpp>

namespace fas{ namespace json{ namespace parse{

FAS_STRING(control_character, "\"\\/bfnrtu")

struct ad_control_character:
  ::fas::serialization::common::parse::ad_charset< 
    control_character, 
    _except_
  >
{};

}}}

#endif
