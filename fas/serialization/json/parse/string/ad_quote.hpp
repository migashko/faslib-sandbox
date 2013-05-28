//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_QUOTE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_QUOTE_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_tstring.hpp>
#include <fas/typemanip/tchars.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_quote:
  ::fas::serialization::common::parse::ad_tstring< 
    tchars<'"'>, 
    ::fas::serialization::_except_
  >
{};

}}}

#endif
