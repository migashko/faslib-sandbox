//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_OBJECT_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_PARSE_OBJECT_ASPECT_HPP

/*
#include <fas/serialization/json/parse/object/ad_left_brace.hpp>
#include <fas/serialization/json/parse/object/ad_right_brace.hpp>
#include <fas/serialization/json/parse/object/ad_colon.hpp>
*/
#include <fas/serialization/json/parse/object/ad_object_field.hpp>
#include <fas/serialization/json/parse/object/ad_field_list.hpp>
#include <fas/serialization/json/parse/object/ad_object.hpp>
#include <fas/serialization/json/parse/object/ad_object_content.hpp>

#include <fas/serialization/json/parse/object/tags.hpp>

#include <fas/serialization/parse/ad_tstring.hpp>
#include <fas/typemanip/tchars.hpp>


namespace fas{ namespace json{ namespace parse{ namespace object{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< _colon_, ::fas::serialization::parse::ad_tstring< tchars<':'> > >,
    advice< _left_brace_, ::fas::serialization::parse::ad_tstring< tchars<'{'> > >,
    advice< _right_brace_, ::fas::serialization::parse::ad_tstring< tchars<'}'> > >,
    advice< _object_field_, ad_object_field>,
    advice< _field_list_, ad_field_list>,
    advice< _object_, ad_object>,
    advice< _object_content_, ad_object_content>
  >::type > 
{};

}}}}

#endif
