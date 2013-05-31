#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/aop.hpp>
#include <fas/type_list.hpp>
#include <fas/integral/int_.hpp>
#include <fas/serialization/json/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/deser/tags.hpp>
#include <fas/serialization/deser/ad_integer.hpp>
#include <fas/serialization/json/deser/ad_integer.hpp>
#include <fas/serialization/json/deser/ad_name.hpp>
#include <fas/serialization/json/deser/ad_field.hpp>

#include <fas/serialization/deser/ad_deser.hpp>
#include <fas/serialization/deser/ad_peek_and_parse.hpp>
#include <fas/serialization/deser/ad_parse.hpp>
#include <fas/serialization/deser/ad_target_n.hpp>

#include <fas/serialization/deser/ad_equal_range.hpp>
#include <fas/serialization/json/parse/tags.hpp>


namespace fas{ namespace json{ namespace deser{

struct aspect:
  ::fas::aspect< type_list_n<
    advice< ::fas::json::_integer_, ::fas::json::deser::ad_integer >,
    advice< ::fas::json::_name_, ::fas::json::deser::ad_name >,
    advice< ::fas::json::_field_, ::fas::json::deser::ad_field >,
    alias< ::fas::json::_prop_, ::fas::json::_field_>,
    alias< ::fas::json::_attr_, ::fas::json::_field_>,
    advice< ::fas::json::deser::_integer_, ::fas::serialization::deser::ad_integer >,
    advice< ::fas::json::deser::_quote_, ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_quote_> >,
    advice< ::fas::json::deser::_space_, ::fas::serialization::deser::ad_parse< ::fas::json::parse::_space_> >,
    advice< ::fas::json::deser::_colon_, ::fas::serialization::deser::ad_peek_and_parse< ::fas::json::parse::_colon_> >,
    advice< ::fas::json::deser::_equal_range_, ::fas::serialization::deser::ad_equal_range>,
    advice< ::fas::json::deser::_field_name_, ::fas::serialization::deser::ad_target_n<int_<0> > >,
    advice< ::fas::json::deser::_field_value_, ::fas::serialization::deser::ad_target_n<int_<1> > >,
    // Перенести в serializer
    advice< ::fas::serialization::_deser_, ::fas::serialization::deser::ad_deser >,
    value_advice< ::fas::serialization::_status_, bool>
  >::type >
{};

}}}

#endif
