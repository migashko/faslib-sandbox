//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_FOUR_HEX_DIGITS
#define FAS_SERIALIZATION_JSON_PARSE_AD_FOUR_HEX_DIGITS

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_four_hex_digits.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_four_hex_digits:
  ::fas::serialization::common::parse::ad_four_hex_digits<_except_>
{};

}}}

#endif