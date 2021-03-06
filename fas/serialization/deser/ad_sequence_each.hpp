#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_EACH_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_EACH_HPP

#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/type_list/empty_list.hpp>

#include <fas/typemanip/empty_type.hpp>


namespace fas{ namespace serialization{ namespace deser{


struct ad_sequence_each
{
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
    typedef typename J::stop_tag stop_tag;

    for (;;)
    {
      r = _<stop_tag>(t, v, r, target_list(), alt_target());
      
      if ( t.get_aspect().template get<stop_tag>().peek(t, r) )
        return r;
    }
    return r;
  }
  
private:
  
  template<typename TgStop, typename T, typename V, typename R, typename L, typename Alt>
  R _(T& t, V& v, R r, L, Alt)
  {
    typedef typename head<L>::type target;
    typedef typename target::tag _tag_; 
    typedef typename tail<L>::type target_list;
    
    if ( t.get_aspect().template get<TgStop>().peek(t, r) )
      return r;
   
    r = t.get_aspect().template get<_tag_>()(t, target(), v, r);
    
    if ( !try_<_except_>(t) )
      return r;

    if ( t.get_aspect().template get<_status_>() )
      return _<TgStop>(t, v, r, target_list(), empty_type() );
    
    t.get_aspect().template get<_status_>() = true;
    
    return _<TgStop>(t, v, r, target_list(), Alt() );
  }

  template<typename TgStop, typename T, typename V, typename R, typename L>
  R _(T& t, V& v, R r, L, empty_type)
  {
    typedef typename head<L>::type target;
    typedef typename target::tag _tag_; 
    typedef typename tail<L>::type target_list;

    if ( t.get_aspect().template get<TgStop>().peek(t, r) )
      return r;

    r = t.get_aspect().template get<_tag_>()(t, target(), v, r);
    
    if ( !try_<_except_>(t) )
      return r;

    t.get_aspect().template get<_status_>() = true;
    
    return _<TgStop>(t, v, r, target_list(), empty_type() );
  }

  template<typename TgStop, typename T, typename V, typename R>
  R _(T& , V& , R r, empty_list, empty_type)
  {
    return r;
  }

  template<typename TgStop, typename T, typename V, typename R, typename Alt>
  R _(T& t, V& v, R r, empty_list, Alt)
  {
    typedef Alt target;
    typedef typename target::tag _tag_;
    return t.get_aspect().template get<_tag_>()(t, target(), v, r);
  }
};

}}}

#endif
