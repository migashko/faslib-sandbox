//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_WHITE_SPACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_WHITE_SPACE_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/parse/ad_charset.hpp>
#include <fas/typemanip/tstring.hpp>
#include <fas/serialization/parse/nocopy.hpp>

namespace fas{ namespace json{ namespace parse{

FAS_STRING(white_space, " \t\r\n\b")

struct ad_white_space_cp:
  ::fas::serialization::common::parse::ad_charset< 
    white_space, 
    _except_
  >
{};

typedef ::fas::serialization::common::parse::nocopy<ad_white_space_cp> ad_white_space;


}}}

#endif
