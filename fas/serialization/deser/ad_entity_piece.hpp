//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_ENTITY_PIECE_HPP
#define FAS_SERIALIZATION_DESER_AD_ENTITY_PIECE_HPP

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

struct ad_entity_piece
{  
  template<typename T, typename J, typename V>
  void operator()(T& , J, V& )
  {
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

}}}

#endif
