//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_ESCAPES_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_ESCAPES_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_escapes: 
  ::fas::serialization::parse::ad_entity< type_list_n<
    _backslash_,
    _control_character_
  >::type>
{};

}}}

#endif
