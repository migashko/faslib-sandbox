//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_COMMA_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_COMMA_HPP

#include <fas/serialization/parse/ad_tstring.hpp>
#include <fas/functional/tchars.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_comma:
  ::fas::serialization::parse::ad_tstring< tchars<','> >
{};

}}}

#endif
