//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PARSE_AD_END_FRAGMENT_HPP
#define FAS_SERIALIZATION_PARSE_AD_END_FRAGMENT_HPP

#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/expected_of.hpp>
#include <fas/serialization/tags.hpp>


#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace parse{

struct ad_end_fragment
{
  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return !r;
  }

  template<typename T, typename R>
  bool peek( T&, R* r)
  {
    return r==0 || *r=='\0';
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    if ( this->peek(t, rr.first) )
      return throw_<_except_>( t, unexpected_end_fragment(), rr );
    return throw_<_except_>( t, expected_of("end fragment",  distance(rr.first) ), rr);
  }
};

}}}

#endif

