//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PARSE_AD_ANY_CHARACTER_HPP
#define FAS_SERIALIZATION_PARSE_AD_ANY_CHARACTER_HPP

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/except/throw_.hpp>

namespace fas{ namespace serialization{ namespace parse{

struct ad_any_character
{ 
  template<typename T, typename R>
  bool peek( T&, R )
  {
    return true;
  }

  template<typename T, typename RR>
  RR operator() (T& t, RR rr)
  {
    if ( !rr.second )
      return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

    if ( !rr.first )
      return throw_<_except_>( t, unexpected_end_fragment(), rr );

    *(rr.second++) = *(rr.first++);
    return rr;
  }
};

}}}

#endif
