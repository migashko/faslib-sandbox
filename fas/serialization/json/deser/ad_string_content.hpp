#ifndef FAS_SERIALIZATION_JSON_DESER_AD_STRING_CONTENT_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_STRING_CONTENT_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/json/meta/object.hpp>  // TODO del
#include <fas/type_list/type_list.hpp>

namespace fas{ namespace json{ namespace deser{

struct ad_string_content
{
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef ::fas::serialization::_sequence_each_ tag;
    t.get_aspect().template get<tag>()(t, meta(), v);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef ::fas::serialization::_sequence_each_ tag;
    return t.get_aspect().template get<tag>()(t,  meta(), v, r);
  }
  
private:
  
  struct meta
  {
    struct helper
    {
      typedef ::fas::serialization::_entity_piece_ tag; // сделать алиас на _string_helper_
      typedef type_list_n<
        parse_copy_if< ::fas::json::parse::_utf8_letter_>
      >::type entity_list;
    };
    
    typedef type_list<helper> target_list;

    // Костыль - должн быть exception (типа invalid_string)
    typedef ignore_field alt_target; // TODO:
  
    typedef ::fas::json::parse::_quote_ stop_tag;
  };
};

}}}

#endif
