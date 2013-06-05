#ifndef FAS_SERIALIZATION_PARSER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_PARSER_AD_SEQUENCE_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>

namespace fas{ namespace serialization{ namespace parse{

template<typename TgList>
struct ad_sequence
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  
  template<typename T, typename R>
  bool peek( T& t, R r)
  {
    typedef typename ::fas::head<tag_list>::type _first_;
    return t.get_aspect().template get<_first_>().peek(t, r);
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return _(t, rr, tag_list() );
  }
  
private:

  template<typename T, typename RR, typename TagList>
  RR _(T& t, RR rr, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
    rr = t.get_aspect().template get<_head_>()(t, rr);

    if ( !try_<_except_>(t) )
      return rr;

    return _(t, rr, typename ::fas::tail<TagList>::type() );

  }

  template<typename T, typename RR>
  RR _(T&, RR rr, ::fas::empty_list)
  {
    return rr;
  }
};

}}}

#endif
