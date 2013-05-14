//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_NUMBER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_NUMBER_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_json_number.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_number:
  ::fas::serialization::common::parse::ad_json_number<_except_>
{};

}}}

#endif
