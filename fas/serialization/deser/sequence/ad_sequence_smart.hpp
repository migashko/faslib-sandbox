#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_SMART_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_SMART_HPP

#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/type_list/erase_c.hpp>
#include <fas/type_list/type_at_c.hpp>
#include <fas/type_list/length.hpp>
#include <fas/integral/int_.hpp>

#include <fas/type_list/empty_list.hpp>
#include <fas/serialization/deser/sequence/sequence.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgParseEnd>
struct ad_sequence<sequence::smart, TgParseEnd>
{
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V>
  void operator()(T& , J, V& )
  {
    // proval
  }


  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    typedef typename J::alt_target alt_target;
    // static_check equal length target_list and proval_list
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;
    t.get_aspect().template get<_status_>() = true;
    return _( t, v, r, target_list(), alt_target(), int_<length<target_list>::value>() );
  }

private:

  // Отработали все элементы
  template<typename T, typename V, typename R, typename TgAlt>
  R _(T& t, V& v, R r, empty_list, TgAlt, int_<0> )
  {
    while ( r && !t.get_aspect().template get<_end_>().peek(t, r) )
    {
      typedef typename TgAlt::tag alt_tag;
      r = t.get_aspect().template get< alt_tag >()(t, TgAlt(), v, r );
    }
    return r;
  }

  // Дошли до конца списка
  template<typename T, typename V, typename R, typename L, typename TgAlt>
  R _(T& t, V& v, R r, L, TgAlt, int_<0> )
  {
    // здесь альтенатива, по умочанию парсинг
    typedef typename TgAlt::tag alt_tag;
    r = t.get_aspect().template get< alt_tag >()(t, TgAlt(), v, r );
    
    // Если дошли до конца, отрабатываем необработанные элементы
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return _(t, v, L(), r);

    return _(t, v, r, L(), TgAlt(), int_<length<L>::value>());
  }


  template<typename T, typename V, typename R, typename L, typename TgAlt,  int N >
  R _(T& t, V& v, R r, L, TgAlt, int_<N> )
  {
    enum { position = length<L>::value - N };
    typedef typename type_at_c<position, L>::type target;
    typedef typename target::tag _tag_;

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    R income = r;

    r = t.get_aspect().template get<_tag_>()(t, target(), v, r);

    if ( !try_<_except_>(t) )
      return r;

    if ( false == t.get_aspect().template get<_status_>() )
    {
      t.get_aspect().template get<_status_>() = true;
      // Текущий не подошел, берем следующий
      return _(t, v, income, L(), TgAlt(), int_<N-1>() );
    }

    // Ок. удаляем текущий из списка, продолжаем с начала списка
    typedef typename erase_c<position, L>::type  target_list;
    
    return _(t, v, r, target_list(), TgAlt(), int_<length<target_list>::value>() );
  }
  
/// finalize
  template<typename T, typename V, typename L, typename R >
  R _(T& t, V& v, L, R r )
  {
    typedef typename head<L>::type target;
    typedef typename target::tag _tag_;
    t.get_aspect().template get<_tag_>()(t, target(), v);
    return _(t, v, typename tail<L>::type(), r);
  }
  
  template<typename T, typename V, typename R >
  R _(T& , V&, empty_list, R r )
  {
    return r;
  }

};

}}}

#endif
