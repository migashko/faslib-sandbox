#ifndef FAS_SERIALIZATION_COMMON_PARSER_AD_VARIANT_HPP
#define FAS_SERIALIZATION_COMMON_PARSER_AD_VARIANT_HPP

#include <fas/except/throw_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/serialization/except/parse_error.hpp>


namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgList, typename TgExcept>
struct ad_variant
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  typedef TgExcept _except_;
  
  template<typename T, typename R>
  bool peek( T& t, R r)
  {
    return _peek( t, r, tag_list() );
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return _parse(t, rr, tag_list() );
  }
  
private:

  template<typename T, typename R, typename TagList>
  bool _peek(T& t, R r, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
   
    if ( t.get_aspect().template get<_head_>().peek(t, r) )
      return true;

    return _peek(t, r, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename R>
  bool _peek(T&, R, ::fas::empty_list)
  {
    return false;
  }

  template<typename T, typename RR, typename TagList>
  RR _parse(T& t, RR rr, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;

    if ( t.get_aspect().template get<_head_>().peek(t, rr.first) )
      return t.get_aspect().template get<_head_>()( t, rr);

    return _parse(t, rr, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename RR>
  RR _parse(T& t, RR rr, ::fas::empty_list)
  {
    return throw_<_except_>( t, parse_error( distance(rr.first) ), rr );
  }
  
};

}}}}

#endif
