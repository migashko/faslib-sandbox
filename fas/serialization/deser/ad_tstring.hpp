//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_TSTRING_HPP
#define FAS_SERIALIZATION_DESER_AD_TSTRING_HPP

#include <fas/serialization/tags.hpp>
#include <fas/range/srange.hpp>

namespace fas{ namespace serialization{ namespace deser{

// Переименовать
struct ad_tstring
{
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    typedef typename J::target target;
    typedef typename target::tag tag;
    t.get_aspect().template get<tag>()(t, target(), v);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& , R r)
  {
    return _(t, srange( J()() ), r );
  }
private:
  template<typename T, typename RL, typename RR>
  RR _(T& t, RL rl, RR rr)
  {
    RR res = rr;
    for ( ; rl && rr; ++rl, ++rr )
    {
      if ( *rl != *rr )
      {
        t.get_aspect().template get<_status_>() = false;
        return res;
      }
    }
    return rr;
  }
};

}}}

#endif
