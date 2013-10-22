#ifndef FAS_SERIALIZATION_JSON_DESER_AD_STRING_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_STRING_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>  // TODO del

namespace fas{ namespace json{ namespace deser{

struct ad_string
{
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef ::fas::serialization::_entity_ tag;
    typedef meta_< typename J::target, typename J::proval_list > meta;
    t.get_aspect().template get<tag>()(t, meta(), v);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef ::fas::serialization::_entity_ tag;
    typedef meta_< typename J::target, typename J::proval_list > meta;
    return t.get_aspect().template get<tag>()(t,  meta(), v, r);
  }
  
private:
  
  template< typename Target, typename ProvalList >
  struct meta_
  {
    //typedef container< string_content > target;
    typedef Target target;
    typedef ProvalList proval_list;
    
    typedef typename type_list_n<
      parse_skip_if< ::fas::json::parse::_quote_>,
      target,  
      parse_skip< ::fas::json::parse::_quote_>
    >::type entity_list;
  };
};

}}}

#endif
