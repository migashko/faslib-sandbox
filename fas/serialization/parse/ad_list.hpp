#ifndef FAS_SERIALIZATION_PARSER_AD_LIST_HPP
#define FAS_SERIALIZATION_PARSER_AD_LIST_HPP

#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{ namespace parse{

template<typename TgEntity, typename TgSeparator, typename TgEnd>
struct ad_list
{
  typedef TgEntity    _entity_;
  typedef TgSeparator _separator_;
  typedef TgEnd       _end_;
  
  template<typename T, typename R>
  bool peek( T&, R )
  {
    return true;
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
      return rr;

    for (;;)
    {
      rr = t.get_aspect().template get<_entity_>()(t, rr);
      if ( !try_<_except_>(t) )
        break;

      if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
        break;

      rr = t.get_aspect().template get<_separator_>()(t, rr);

      if ( !try_<_except_>(t) )
        break;
    }
    return rr;
  }
};

}}}

#endif
