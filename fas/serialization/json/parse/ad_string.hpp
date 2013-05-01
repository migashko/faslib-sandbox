//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_STRING_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_STRING_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/common/parse/ad_enclosed_entity.hpp>

namespace fas{ namespace json{ namespace parse{

typedef ::fas::serialization::common::parse::ad_enclosed_entity< _quote_, _string_content_, _quote_, _except_> ad_string;

}}}

#endif