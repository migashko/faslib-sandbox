//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_ASPECT_HPP

#include <fas/serialization/json/parse/ad_value.hpp>
#include <fas/serialization/json/parse/ad_comma.hpp>
#include <fas/serialization/json/parse/ad_sequence_separator.hpp>
#include <fas/serialization/parse/ad_tstring.hpp>
#include <fas/functional/tchars.hpp>
#include <fas/serialization/parse/ad_parse.hpp>

#include <fas/serialization/json/parse/space/aspect.hpp>
#include <fas/serialization/json/parse/string/aspect.hpp>
#include <fas/serialization/json/parse/object/aspect.hpp>
#include <fas/serialization/json/parse/array/aspect.hpp>
#include <fas/serialization/json/parse/simple/aspect.hpp>

#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace json{ namespace parse{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _comma_, ad_comma >,
    advice< _value_, ad_value>,
    advice< _sequence_separator_, ad_sequence_separator>,
    advice< ::fas::serialization::_parse_, ::fas::serialization::parse::ad_parse<_value_> >,
    space::aspect,
    simple::aspect,
    string::aspect,
    object::aspect,
    array::aspect
  >::type > 
{};

}}}

#endif
