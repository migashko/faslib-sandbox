//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_STRING_CONTENT_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_string_content: 
  ::fas::serialization::parse::ad_sequence< 
    _string_element_,
    _quote_
  >
{};

}}}

#endif
