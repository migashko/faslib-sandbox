#ifndef FAS_SERIALIZATION_DESER_AD_BRUTE_LIST_T_HPP
#define FAS_SERIALIZATION_DESER_AD_BRUTE_LIST_T_HPP

#include <fas/except/try_.hpp>

#include <fas/type_list/empty_list.hpp>
#include <fas/type_list/type_list.hpp>

#include <iostream>
namespace fas{ namespace serialization{ namespace deser{

/** для массивов и прочих штук
 * @tparam TgParseSep separator parser tag
 * @tparam TgParseElement list item parser tag
 * @tparam TgParseEnd end list parser tag
 */
template<typename TgParseSep, typename TgParseItem, typename TgParseEnd>
struct ad_brute_list
{
  typedef TgParseSep  _separator_;
  typedef TgParseItem _parse_item_;
  typedef TgParseEnd  _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    for (;;)
    {
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;
      
      int count = 0;
      // Десериализуем список (_status_ == false) ни один 
      r = _(t, v, r, target_list(), count );
     
      if ( !try_<_except_>(t) )
        return r;

      if ( count == 0 )
      {
        r = t.get_aspect().template get< _parse_item_ >()(t, std::make_pair(r, mrange(r))).first;
        if ( t.get_aspect().template get<_separator_>().peek(t, r) )
          r = t.get_aspect().template get<_separator_>()(t, std::make_pair(r, mrange(r))).first;
      }
    }
  }
private:
  
  template<typename T, typename V, typename R>
  R _(T& , V& , R r, empty_list, int& )
  {
    return r;
  }

  template<typename T, typename V, typename R, typename L>
  R _(T& t, V& v, R r, L, int& count )
  {
    typedef typename head<L>::type target;
    typedef typename target::tag tag;
    typedef typename tail<L>::type target_list;

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    t.get_aspect().template get<_status_>() = true;
    R income = r;
    r = t.get_aspect().template get<tag>()(t, target(), v, r);

    if ( !try_<_except_>(t) )
        return r;

    if ( true == t.get_aspect().template get<_status_>() )
    {
      ++count;
      if ( t.get_aspect().template get<_separator_>().peek(t, r) )
        r = t.get_aspect().template get<_separator_>()(t, std::make_pair(r, mrange(r))).first;
      else if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;
    }
    else
      r = income;

    return _(t, v, r, target_list(), count );
  }
};
  
}}}

#endif
