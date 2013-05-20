//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_TSTRING_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_TSTRING_HPP

#include <fas/range/distance.hpp>
#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TString, typename TgExcept>
struct ad_tstring_strong
{
  typedef TgExcept _except_;
  typedef TString tstring;
  typedef string_range< typename TString::value_type > tstring_range;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    return this->compare(t, tstring_range( tstring()() ), r );
  }
private:
  template<typename T, typename RL, typename RR>
  RR compare(T& t, RL rl, RR rr)
  {
    RR res = rr;
    for ( ; rl && rr; ++rl, ++rr )
    {
      if ( !rr )
        return throw_<_except_>( t, unexpected_end_fragment(), rr );
      
      if ( *rl != *rr )
        return throw_<_except_>( t, expected_of(tstring()(),  distance(rr.first) ), rr );
      
    }
    // Дошли до конца
    return rr;
  }
};

}}}}

#endif
