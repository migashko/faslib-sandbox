#ifndef FAS_SERIALIZATION_JSON_DESER_AD_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_OBJECT_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>  // TODO del

namespace fas{ namespace json{ namespace deser{

struct ad_object
{
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef ::fas::serialization::_entity_ tag;
    typedef meta_< typename J::target > meta;
    t.get_aspect().template get<tag>()(t, meta(), v);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef ::fas::serialization::_entity_ tag;
    typedef meta_< typename J::target > meta;
    return t.get_aspect().template get<tag>()(t,  meta(), v, r);
  }
  
private:
  
  template< typename Target >
  struct meta_
  {
    typedef Target target;
    typedef typename type_list_n<
      parse_skip_if< ::fas::json::parse::_left_brace_>,
      target,  
      parse_skip< ::fas::json::parse::_right_brace_>
    >::type entity_list;    
  };
};

}}}

#endif
