//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_COMMENT_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_COMMENT_CONTENT_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_list.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_comment_content:
  ::fas::serialization::common::parse::ad_list< 
    _any_,
    _empty_,
    _end_comment_,
    _except_
  >
{};

}}}

#endif
