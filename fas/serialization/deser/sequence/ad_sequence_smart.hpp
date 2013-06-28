#ifndef FAS_SERIALIZATION_DESER_AD_SMART_HPP
#define FAS_SERIALIZATION_DESER_AD_SMART_HPP

#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/type_list/erase_c.hpp>
#include <fas/type_list/type_at_c.hpp>
#include <fas/type_list/length.hpp>
#include <fas/integral/int_.hpp>

#include <fas/type_list/empty_list.hpp>
#include <fas/serialization/deser/sequence/sequence.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgAlt, typename TgParseEnd>
struct ad_sequence<sequence::smart, TgAlt, TgParseEnd>
{
  typedef TgAlt           _alt_;
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    typedef typename J::proval_list proval_list;
    // static_check equal length target_list and proval_list
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;
    t.get_aspect().template get<_status_>() = true;
    return _( t, v, r, target_list(), proval_list(), int_<length<target_list>::value>() );
  }

private:

  template<typename T, typename V, typename R>
  R _(T& t, V& , R r, empty_list, empty_list, int_<0> )
  {
    while ( r && !t.get_aspect().template get<_end_>().peek(t, r) )
      r = t.get_aspect().template get< _alt_ >()(t, std::make_pair(r, mrange(r))).first;
    return r;
  }

  template<typename T, typename V, typename R, typename L, typename PL>
  R _(T& t, V& v, R r, L, PL, int_<0> )
  {
    // здесь альтенатива, по умочанию парсинг
    r = t.get_aspect().template get< _alt_ >()(t, std::make_pair(r, mrange(r))).first;
    
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    return _(t, v, r, L(), int_<length<L>::value>());
  }


  template<typename T, typename V, typename R, typename L, typename PL,  int N >
  R _(T& t, V& v, R r, L, PL, int_<N> )
  {
    enum { position = length<L>::value - N };
    typedef typename type_at_c<position, L>::type target;
    typedef typename target::tag _tag_

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    R income = r;

    r = t.get_aspect().template get<_tag_>()(t, target(), v, r);

    if ( !try_<_except_>(t) )
      return r;

    if ( false == t.get_aspect().template get<_status_>() )
    {
      t.get_aspect().template get<_status_>() = true;
      return _(t, v, income, L(), PL(),  int_<N-1>() );
    }

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    typedef typename erase_c<position, L>::type  target_list;
    typedef typename erase_c<position, PL>::type proval_list;
    typedef typename type_at_c<position, PL>::type proval;
    typedef typename proval::tag _proval_tag_;
    r = t.get_aspect().template get<_proval_tag_>()(t, proval(), v, r);
    return _(t, v, r, target_list(), proval_list(), int_<length<target_list>::value>() );
  }
};

}}}

#endif
