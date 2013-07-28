//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_ENTITY_HPP
#define FAS_SERIALIZATION_DESER_AD_ENTITY_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/typemanip/type2type.hpp>
#include <fas/range/mrange.hpp>
#include <fas/integral/bool_.hpp>

#include <utility>
#include "utility.hpp"

namespace fas{ namespace serialization{ namespace deser{

struct ad_entity3
{  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    /*
    typedef typename J::entity_list entity_list;
    _(t, J(), v, entity_list() );
    */
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::entity_list entity_list;

    R orig = r;
    
    r =  _(t, J(), v, r, entity_list() );

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    return r;
  }
  
private:
  
  template<typename T, typename J, typename V, typename R, typename L>
  R _(T& t, J, V& v, R r, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    //typedef typename head_item::target target;
    typedef typename head_item::tag _tag_;
    
    r = t.get_aspect().template get<_tag_>()( t, head_item(), v, r);
    /*
    r = entity_(t, J(), v, r, head_item());
    */

    if ( !try_<_except_>(t) )
      return r;

    if ( !t.get_aspect().template get<_status_>() )
      return r;
    
    return _(t, J(), v, r, tail_list());
  }

  template<typename T, typename J, typename V, typename R>
  R _(T&, J, V&, R r, empty_list)
  {
    return r;
  }
  
// proval

/*
  template<typename T, typename J, typename V, typename L>
  void _(T& t, J, V& v, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    // typedef typename head_item::target target;
    // typedef typename target::tag _tag_;
    typedef typename head_item::tag _tag_;

    
    t.get_aspect().template get<_tag_>()( t, head_item(), v);
    //entity_(t, J(), v, head_item());

    if ( !try_<_except_>(t) )
      return;
    
    _(t, J(), v, tail_list());
  }

  template<typename T, typename J, typename V>
  void _(T&, J, V&, empty_list)
  {
    
  }
  */
};

struct ad_entity3_variant
{  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::entity_list entity_list;

    R orig = r;
    
    //t.get_aspect().template get<_status_>() = false;
    
    r =  _(t, J(), v, r, entity_list() );

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    return r;
  }
  
private:
  
  template<typename T, typename J, typename V, typename R, typename L>
  R _(T& t, J, V& v, R r, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    typedef typename head_item::tag _tag_;
    
    t.get_aspect().template get<_status_>() = true;
    
    r = t.get_aspect().template get<_tag_>()( t, head_item(), v, r);

    if ( !try_<_except_>(t) )
      return r;

    if ( t.get_aspect().template get<_status_>() )
      return r;
    
    return _(t, J(), v, r, tail_list());
  }

  template<typename T, typename J, typename V, typename R>
  R _(T&, J, V&, R r, empty_list)
  {
    return r;
  }  
};

template<typename TgList>
struct ad_entity2
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    _(t, J(), v, tag_list() );
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;
    
    r =  _(t, J(), v, r, tag_list() );

    if ( !t.get_aspect().template get<_status_>() )
      return orig;
    

    return r;
  }
  
private:
  
  template<typename T, typename J, typename V, typename R, typename L>
  R _(T& t, J, V& v, R r, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    r = entity_(t, J(), v, r, head_item());

    if ( !try_<_except_>(t) )
      return r;

    if ( !t.get_aspect().template get<_status_>() )
      return r;
    
    return _(t, J(), v, r, tail_list());
  }

  template<typename T, typename J, typename V, typename R>
  R _(T&, J, V&, R r, empty_list)
  {
    return r;
  }
  
// proval

  template<typename T, typename J, typename V, typename L>
  void _(T& t, J, V& v, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    entity_(t, J(), v, head_item());

    if ( !try_<_except_>(t) )
      return;
    
    _(t, J(), v, tail_list());
  }

  template<typename T, typename J, typename V>
  void _(T&, J, V&, empty_list)
  {
    
  }
};

template<typename TgList>
struct ad_entity_variant
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    //_(t, J(), v, tag_list() );
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;
    
    r =  _(t, J(), v, r, tag_list() );

    //if ( !try_<_except_>(t) )
    //  return orig;
    
    if ( !t.get_aspect().template get<_status_>() )
      return orig;
    

    return r;
  }
  
private:
  
  template<typename T, typename J, typename V, typename R, typename L>
  R _(T& t, J, V& v, R r, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    t.get_aspect().template get<_status_>() = true;
    
    r = entity_(t, J(), v, r, head_item());

    if ( !try_<_except_>(t) )
      return r;

    if ( t.get_aspect().template get<_status_>() )
      return r;
    
    return _(t, J(), v, r, tail_list());
  }

  template<typename T, typename J, typename V, typename R>
  R _(T&, J, V&, R r, empty_list)
  {
    return r;
  }
  
// proval

  /*
  template<typename T, typename J, typename V, typename L>
  void _(T& t, J, V& v, L)
  {
    typedef typename head<L>::type head_item;
    typedef typename tail<L>::type tail_list;
    
    entity_(t, J(), v, head_item());

    if ( !try_<_except_>(t) )
      return;
    
    _(t, J(), v, tail_list());
  }

  template<typename T, typename J, typename V>
  void _(T&, J, V&, empty_list)
  {
    
  }
  */
};

/*
template<typename TgList, bool Variant = false>
struct ad_entity_old
{
  
  typedef typename ::fas::normalize<TgList>::type tag_list;

  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    _(t, J(), v, TgList() );
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;
    r =  _(t, J(), v, r, tag_list() );

    if ( !try_<_except_>(t) )
      return orig;

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    return r;
  }

private:

  template<typename T, typename J, typename V, typename R, typename TagList>
  R _(T& t, J, V& v, R r, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
    r =  __(t, J(), v, r, type2type<_head_>(), bool_<Variant>() );

    if ( !try_<_except_>(t) )
      return r;

    if ( !t.get_aspect().template get<_status_>() )
      return r;

    return _(t, J(), v, r, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename J, typename V, typename R>
  R _(T&, J, V& , R r, empty_list)
  {
    return r;
  }

  template<typename T, typename J, typename V, typename R, typename TgHead>
  R __(T& t, J, V& v, R r, type2type<TgHead>, bool_<false> )
  {
    return t.get_aspect().template get<TgHead>()(t, J(), v, r);
  }

  template<typename T, typename J, typename V, typename R, typename TgHead>
  R __(T& t, J, V& v, R r, type2type<TgHead>, bool_<true> )
  {
    R orig = r;
    r = t.get_aspect().template get<TgHead>()(t, J(), v, r);
    if ( t.get_aspect().template get<_status_>() )
      return r;
    t.get_aspect().template get<_status_>() = true;
    return orig;
  }

  template<typename T, typename J, typename V, typename R, typename TgHead>
  R __(T& t, J, V&, R r, type2type<parser<TgHead> >, bool_<false> )
  {
   return t.get_aspect().template get<TgHead>()(t, std::make_pair(r, mrange(r))).first;
  }

  template<typename T, typename J, typename V, typename R, typename TgHead>
  R __(T& t, J, V&, R r, type2type<parser<TgHead> >, bool_<true> )
  {
    if ( !t.get_aspect().template get<TgHead>().peek(t, r) )
      return r;
    return t.get_aspect().template get<TgHead>()(t, std::make_pair(r, mrange(r))).first;
  }
  
// proval 

  template<typename T, typename J, typename V, typename L>
  void _(T& t, J, V& v, L)
  {
    __(t, J(), v,  type2type< typename head<L>::type> () );
    _(t, J(), v, typename tail<L>::type() );
  }

  template<typename T, typename J, typename V>
  void _(T& , J, V& , empty_list)
  {
  }

  template<typename T, typename J, typename V, typename Tg>
  void __(T&, J, V&, type2type<parser<Tg> >)
  {
  }

  template<typename T, typename J, typename V, typename Tg>
  void __(T& t, J, V& v, type2type<Tg >)
  {
    t.get_aspect().template get< Tg >()(t, J(), v);
  }

};
*/

}}}

#endif
