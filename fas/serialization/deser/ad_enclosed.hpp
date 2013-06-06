//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_ENCLOSED_HPP
#define FAS_SERIALIZATION_DESER_AD_ENCLOSED_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/range/mrange.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgParseLeft, typename TgTarget, typename TgParseRight>
struct ad_enclosed
{
  typedef TgParseLeft  _left_;
  typedef TgTarget     _target_;
  typedef TgParseRight _right_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    if ( !t.get_aspect().template get<_left_>().peek(t, r) )
    {
      t.get_aspect().template get<_status_>() = false;
      return r;
    }
    
    R orig = r;
    r = t.get_aspect().template get<_left_>()(t, std::make_pair(r, mrange(r)) ).first;
    
    if ( !try_<_except_>(t) )
      return r;

    r = t.get_aspect().template get<_target_>()(t, J(), v, r);
    
    if ( !try_<_except_>(t) )
      return r;
      
    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    r = t.get_aspect().template get<_right_>()(t, std::make_pair(r, mrange(r)) ).first;

    return r;
  }
};

}}}

#endif
