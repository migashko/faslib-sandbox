#ifndef FAS_SERIALIZATION_DESER_AD_PRIMARY_LIST_T_HPP
#define FAS_SERIALIZATION_DESER_AD_PRIMARY_LIST_T_HPP

#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/type_list/erase_c.hpp>
#include <fas/type_list/type_at_c.hpp>
#include <fas/type_list/length.hpp>
#include <fas/integral/int_.hpp>

#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace serialization{ namespace deser{

/**
 * @tparam TgParseSep separator parser tag
 * @tparam TgParseElement list item parser tag
 * @tparam TgParseEnd end list parser tag
 */
template<typename TgParseSep, typename TgParseItem, typename TgParseEnd>
struct ad_primary_list
{
  typedef TgParseSep  _separator_;
  typedef TgParseItem _parse_item_;
  typedef TgParseEnd  _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::targets target_list;
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;
    t.get_aspect().template get<_status_>() = true;
    return _( t, v, r, target_list(), int_<length<target_list>::value>() );
  }
  
private:
  
  template<typename T, typename V, typename R>
  R _(T& , V& , R r, empty_list, int_<0> )
  {
    return r;
  }

  template<typename T, typename V, typename R, typename L>
  R _(T& t, V& v, R r, L, int_<0> )
  {
    r = t.get_aspect().template get< _parse_item_ >()(t, std::make_pair(r, mrange(r))).first;

    if ( t.get_aspect().template get<_separator_>().peek(t, r) )
      r = t.get_aspect().template get<_separator_>()(t, std::make_pair(r, mrange(r))).first;
    else if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;
    
    return _(t, v, r, L(), int_<length<L>::value>());
  }


  template<typename T, typename V, typename R, typename L, int N >
  R _(T& t, V& v, R r, L, int_<N> )
  {
    enum { position = length<L>::value - N };
    typedef typename type_at_c<position, L>::type target;
    typedef typename target::tag tag;

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    R income = r;

    r = t.get_aspect().template get<tag>()(t, target(), v, r);

    if ( !try_<_except_>(t) )
      return r;
    
    if ( false == t.get_aspect().template get<_status_>() )
    {
      t.get_aspect().template get<_status_>() = true;
      return _(t, v, income, L(), int_<N-1>() );
    }

    if ( t.get_aspect().template get<_separator_>().peek(t, r) )
      r = t.get_aspect().template get<_separator_>()(t, std::make_pair(r, mrange(r))).first;
    else if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    typedef typename erase_c<position, L>::type target_list;
    return _(t, v, r, target_list(), int_<length<target_list>::value>() );
  }
};

}}}

#endif
