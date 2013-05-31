//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_COMPARE_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_COMPARE_HPP

#include <fas/except/throw_.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgStatus, typename TgExcept>
struct ad_compare
{
  typedef TgExcept _except_;
  typedef TgStatus _status_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    return this->compare(t, range( J()() ), r );
  }
private:
  template<typename T, typename RL, typename RR>
  RR compare(T& t, RL rl, RR rr)
  {
    RR res = rr;
    for ( ; rl && rr; ++rl, ++rr )
      if ( *rl != *rr )
      {
        t.get_aspect().template get<_status_>() = false;
        return res;
      }
    // Дошли до конца
    return rr;
  }
};

}}}}

#endif
