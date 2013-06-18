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

namespace fas{ namespace serialization{ namespace deser{

template<typename T>
struct parser{};

template<typename TgList, bool Variant = false>
struct ad_entity
{
  typedef typename ::fas::normalize<TgList>::type tag_list;

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

};

/*
template<typename TgList, bool Var>
template<typename T, typename J, typename V, typename R, typename TgHead>
R ad_entity<TgList, Var>::__(T& t, J, V&, R r, type2type<parser<TgHead> > )
{
    r =  t.get_aspect().template get<TgHead>()(t, std::make_pair(r, mrange(r))).first;
    return r;
}*/




}}}

#endif