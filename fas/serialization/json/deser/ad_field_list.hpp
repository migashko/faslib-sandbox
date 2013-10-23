#ifndef FAS_SERIALIZATION_JSON_DESER_AD_FIELD_LIST_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_FIELD_LIST_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>  // TODO del

namespace fas{ namespace json{ namespace deser{

struct ad_field_list
{
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef ::fas::serialization::_sequence_smart_ tag;
    typedef meta_< typename J::target_list, typename J::alt_target > meta;
    t.get_aspect().template get<tag>()(t, meta(), v);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef ::fas::serialization::_sequence_smart_ tag;
    typedef meta_< typename J::target_list, typename J::alt_target > meta;
    return t.get_aspect().template get<tag>()(t,  meta(), v, r);
  }
  
private:
  
  template< typename TargetList,  typename Alt >
  struct meta_
  {
//    typedef ::fas::serialization::_sequence_smart_ tag;
    typedef TargetList target_list;
    typedef Alt alt_target;  
    typedef ::fas::json::parse::_right_brace_ stop_tag;

    /*
    typedef typename type_list_n<
      parse_skip< ::fas::json::parse::_space_>,
      Key,
      parse_skip< ::fas::json::parse::_space_>,
      parse_skip< ::fas::json::parse::_colon_>,
      parse_skip< ::fas::json::parse::_space_>,
      Value,
      parse_skip< ::fas::json::parse::_space_>,
      parse_skip< ::fas::json::parse::_sequence_separator_>
    >::type entity_list;
    */
  };
};

}}}

#endif
