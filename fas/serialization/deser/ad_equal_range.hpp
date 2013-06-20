//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_EQUAL_RANGE_HPP
#define FAS_SERIALIZATION_DESER_AD_EQUAL_RANGE_HPP

#include <fas/except/throw_.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/range/distance.hpp>
#include <fas/range/srange.hpp>

namespace fas{ namespace serialization{ namespace deser{

// Переименовать
struct ad_equal_range
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V , R r)
  {
    return _equal_range(t, srange( J()() ), r );
  }
private:
  template<typename T, typename RL, typename RR>
  RR _equal_range(T& t, RL rl, RR rr)
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
    // Дошли до конца
    return rr;
  }
};

}}}

#endif
