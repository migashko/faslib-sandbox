//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_ELEMENT_HPP
#define FAS_SERIALIZATION_DESER_AD_ELEMENT_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/range/mrange.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace deser{

  /*
template<typename TgParseSep, typename TgTarget, typename TgEnd>
struct ad_element
{
  typedef TgParseSep    _separator_;
  typedef TgTarget      _target_;
  typedef TgParseEnd    _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;
    r = t.get_aspect().template get<_target_>()(t, J(), v, r);

    if ( !try_<_except_>(t) )
      return r;

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    return t.get_aspect().template get<_separator_>()(t, std::make_pair(r, mrange(r))).first;
  }
};
*/

}}}

#endif
