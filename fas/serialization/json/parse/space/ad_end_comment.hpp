//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_END_COMMENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_END_COMMENT_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_tstring.hpp>
#include <fas/functional/tstring.hpp>

namespace fas{ namespace json{ namespace parse{

FAS_STRING(end_comment, "*/")

struct ad_end_comment:
  ::fas::serialization::parse::ad_tstring<end_comment>
{};

}}}

#endif
