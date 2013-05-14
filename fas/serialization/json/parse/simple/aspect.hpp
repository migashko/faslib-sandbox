//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_SIMPLE_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_SIMPLE_ASPECT_HPP

#include <fas/serialization/json/parse/simple/ad_number.hpp>
#include <fas/serialization/json/parse/simple/ad_null.hpp>
#include <fas/serialization/json/parse/simple/ad_boolean.hpp>
#include <fas/serialization/json/parse/simple/ad_true.hpp>
#include <fas/serialization/json/parse/simple/ad_false.hpp>
#include <fas/serialization/json/parse/simple/tags.hpp>

namespace fas{ namespace json{ namespace parse{ namespace simple{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _null_, ad_null>,
    advice< _number_, ad_number>,
    advice< _true_, ad_true>,
    advice< _false_, ad_false>,
    advice< _boolean_, ad_boolean>
  >::type > 
{};

}}}}

#endif
