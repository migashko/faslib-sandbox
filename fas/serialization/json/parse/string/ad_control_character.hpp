//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_CONTROL_CHARACTER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_CONTROL_CHARACTER_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_charset.hpp>
#include <fas/functional/tstring.hpp>

namespace fas{ namespace json{ namespace parse{


// FAS_STRING(control_character, "\"\\/bfnrtu")
FAS_STRING(control_character, "\"\\/bfnrt")

struct ad_control_character:
  ::fas::serialization::parse::ad_charset<
    control_character
  >
{};


}}}

#endif
