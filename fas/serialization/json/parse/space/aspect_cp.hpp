//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_SPACE_ASPECT_CP_HPP
#define FAS_SERIALIZATION_JSON_PARSE_SPACE_ASPECT_CP_HPP

#include <fas/serialization/json/parse/space/ad_space.hpp>
#include <fas/serialization/json/parse/space/ad_comment.hpp>
#include <fas/serialization/json/parse/space/ad_white_space.hpp>
#include <fas/serialization/json/parse/space/tags.hpp>

namespace fas{ namespace json{ namespace parse{ namespace space{

typedef
  ::fas::aspect< type_list_n<
      advice< _white_space_, ad_white_space_cp>
  >::type >
aspect_white_space_cp;

typedef
  ::fas::aspect< type_list_n<
      advice< _comment_, ad_comment_cp>
  >::type >
aspect_comment_cp;
  
typedef
  ::fas::aspect< type_list_n<
      advice< _space_, ad_space_cp>,
      advice< _white_space_, ad_white_space_cp>,
      advice< _comment_, ad_comment_cp>
  >::type > 
aspect_space_cp;


}}}}

#endif
