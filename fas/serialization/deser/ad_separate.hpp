//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_SEPARATE_HPP
#define FAS_SERIALIZATION_DESER_AD_SEPARATE_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/range/mrange.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgTargetLeft, typename TgParseSep, typename TgTargetRight>
struct ad_separate
{
  typedef TgTargetLeft  _left_;
  typedef TgParseSep    _parse_;
  typedef TgTargetRight _right_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;

    r = t.get_aspect().template get<_left_>()(t, J(), v, r);

    if ( !try_<_except_>(t) )
      return r;

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    r = t.get_aspect().template get<_parse_>()(t, std::make_pair(r, mrange(r))).first;

    if ( !try_<_except_>(t) )
      return r;

    r = t.get_aspect().template get<_right_>()(t, J(), v, r);

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    return r;

    
    /*
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
    */

    return r;
  }
};

}}}

#endif
