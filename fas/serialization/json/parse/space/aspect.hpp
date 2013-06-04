//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_SPACE_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_SPACE_ASPECT_HPP

#include <fas/serialization/json/parse/space/ad_space.hpp>
#include <fas/serialization/json/parse/space/ad_comment.hpp>
#include <fas/serialization/json/parse/space/ad_white_space.hpp>
#include <fas/serialization/json/parse/space/ad_comment_content.hpp>
#include <fas/serialization/json/parse/space/ad_begin_comment.hpp>
#include <fas/serialization/json/parse/space/ad_end_comment.hpp>
#include <fas/serialization/json/parse/space/ad_end_space.hpp>
#include <fas/serialization/json/parse/space/ad_space_variant.hpp>
#include <fas/serialization/json/parse/space/ad_any.hpp>
#include <fas/serialization/json/parse/space/ad_empty.hpp>

#include <fas/serialization/parse/ad_end_fragment.hpp>

#include <fas/serialization/json/parse/space/tags.hpp>

namespace fas{ namespace json{ namespace parse{ namespace space{

struct aspect:
  ::fas::aspect< type_list_n<
      advice< _space_, ad_space>,
      advice< _comment_, ad_comment>,
      advice< _white_space_, ad_white_space>,
      advice< _comment_content_, ad_comment_content>,
      advice< _begin_comment_, ad_begin_comment>,
      advice< _end_comment_, ad_end_comment>,
      advice< _end_space_, ad_end_space>,
      advice< _space_variant_, ad_space_variant>,
      advice< _any_, ad_any>,
      advice< _empty_, ad_empty>,
      advice< _not_space_, ad_not_space>,
      advice< _end_fragment_, ::fas::serialization::common::parse::ad_end_fragment< ::fas::serialization::_except_> >
  >::type > 
{};

}}}}

#endif
