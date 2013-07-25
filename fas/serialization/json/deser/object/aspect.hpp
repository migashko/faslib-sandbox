#ifndef FAS_SERIALIZATION_JSON_DESER_OBJECT_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_OBJECT_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/deser/object/ad_object.hpp>
#include <fas/serialization/json/deser/object/ad_field_list_smart.hpp>
#include <fas/serialization/json/deser/object/ad_field_key.hpp>
#include <fas/serialization/json/deser/object/ad_field_value.hpp>
#include <fas/serialization/json/deser/object/ad_field.hpp>
#include <fas/serialization/json/deser/object/tags.hpp>
#include <fas/serialization/json/tags.hpp>

namespace fas{ namespace json{ namespace deser{ namespace object{

struct aspect:
  ::fas::aspect< type_list_n<
    // alias< _name_, _jstring_ >,
    //advice<_field_key_, ad_field_key>,
    //advice<_field_value_, ad_field_value>,
    advice<_field_, ad_field>,
    advice<_field_list_smart_, ad_field_list_smart >,
    advice<_object_, ad_object>
  >::type >
{};

}}}}

#endif
