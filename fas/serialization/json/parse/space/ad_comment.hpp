//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_COMMENT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_COMMENT_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_entity.hpp>
#include <fas/type_list/type_list_n.hpp>
#include <fas/serialization/parse/nocopy.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_comment_cp:
  ::fas::serialization::parse::ad_entity< type_list_n<
      _begin_comment_,
      _comment_content_,
      _end_comment_
    >::type>
{};

typedef ::fas::serialization::common::parse::nocopy<ad_comment_cp> ad_comment;


}}}

#endif
