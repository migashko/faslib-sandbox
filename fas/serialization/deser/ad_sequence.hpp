#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP

#include <fas/range/orange.hpp>
#include <fas/range/typerange.hpp>
#include <fas/typemanip/reference_wrapper.hpp>
#include <fas/serialization/deser/utility.hpp>
namespace fas{ namespace serialization{ namespace deser{

template<typename Target, typename TgParseEnd>
struct ad_sequence1
{
  typedef Target          _target_;
  // typedef TgParseElement  _element_;
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target_list target_list;
    typedef typename J::alt_target alt_target;

    std::cout << std::endl;
    for (;;)
    {
      
      r = _(t, v, r, target_list(), alt_target());
      
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;

      /*
      r = t.get_aspect().template get<_target_>()(t, J(), v, r);

      if ( !t.get_aspect().template get<_status_>() )
        return r;

      if ( !try_<_except_>(t) )
        return r;
      */
    }
    return r;
  }
  
private:
  template<typename T, typename V, typename R, typename L, typename Alt>
  R _(T& t, V& v, R r, L, Alt)
  {
    std::cout << "1 " << &*r << std::endl;
    typedef typename head<L>::type target;
    //typedef typename target::tag _tag_; 
    typedef typename tail<L>::type target_list;
    
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;
   
    r = t.get_aspect().template get<_target_>()(t, target(), v, r);
    
    if ( !try_<_except_>(t) )
      return r;

    std::cout << "1.1 " << &*r << std::endl;
    if ( t.get_aspect().template get<_status_>() )
      return _(t, v, r, target_list(), empty_type() );
    std::cout << "1.2 " << &*r << std::endl;
    
    t.get_aspect().template get<_status_>() = true;
    return _(t, v, r, target_list(), Alt() );
  }

  template<typename T, typename V, typename R, typename L>
  R _(T& t, V& v, R r, L, empty_type)
  {
    std::cout << "2" << &*r<< std::endl;
    typedef typename head<L>::type target;
    //typedef typename target::tag _tag_; 
    typedef typename tail<L>::type target_list;

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    r = t.get_aspect().template get<_target_>()(t, target(), v, r);
    
    if ( !try_<_except_>(t) )
      return r;

    t.get_aspect().template get<_status_>() = true;
    
    return _(t, v, r, target_list(), empty_type() );
  }

  template<typename T, typename V, typename R>
  R _(T& , V& , R r, empty_list, empty_type)
  {
    std::cout << "3" << &*r << std::endl;
    return r;
  }

  template<typename T, typename V, typename R, typename Alt>
  R _(T& t, V& v, R r, empty_list, Alt)
  {
    std::cout << "4" << std::endl;
    typedef Alt target;
    typedef typename target::tag _tag_;
    
    return t.get_aspect().template get<_tag_>()(t, target(), v, r);
  }

};

template<typename Target, typename TgParseEnd>
struct ad_sequence1_orig
{
  typedef Target          _target_;
  // typedef TgParseElement  _element_;
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    for (;;)
    {
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;

      r = t.get_aspect().template get<_target_>()(t, J(), v, r);

      if ( !t.get_aspect().template get<_status_>() )
        return r;

      if ( !try_<_except_>(t) )
        return r;
    }
  }
  
private:
  
};
  
}}}

#endif
