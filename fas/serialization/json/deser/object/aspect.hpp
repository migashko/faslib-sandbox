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

struct ad_name
{
  template<typename T, typename J, typename V>
  void operator()(T& /*t*/, J, V& /*v*/)
  {
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V&, R r)
  {
    return _(t, J()(), r);
  }
  
private:
  template<typename T, typename RN, typename R>
  R _(T& t, RN rn, R r)
  {
    using ::fas::serialization::_status_;
    t.get_aspect().template get<_status_>() = false;
    R orig = r;
    if ( *r != '"' )
      return orig;
    ++r;
    for (;r && rn && *r==*rn; ++r, ++rn);
    
    if ( !r || *r!='"' || ( rn && *rn!='\0') )
      return orig;
    ++r;
    t.get_aspect().template get<_status_>() = true;
    return r;
  }
};
  
struct aspect:
  ::fas::aspect< type_list_n<
    advice<_name_, ad_name>,
    // alias< _name_, _jstring_ >,
    //advice<_field_key_, ad_field_key>,
    //advice<_field_value_, ad_field_value>,
    //advice<_field_, ad_field>,
    alias<_field_,  ::fas::serialization::_entity_>,

    //advice<_field_list_smart_, ad_field_list_smart >,
    alias<_field_list_smart_, ::fas::serialization::_sequence_smart_ >,
    //advice<_object_, ad_object>
    alias<_object_, ::fas::serialization::_entity_>

  >::type >
{};

}}}}

#endif
