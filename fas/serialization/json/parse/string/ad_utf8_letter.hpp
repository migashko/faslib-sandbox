//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_UTF8_LETTER_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_UTF8_LETTER_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_utf8_letter.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_utf8_letter:
  ::fas::serialization::common::parse::ad_utf8_letter<_except_>
{};


}}}

#endif