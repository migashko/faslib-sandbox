//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_END_FRAGMENT_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_END_FRAGMENT_HPP

#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/expected_of.hpp>
#include <fas/serialization/except/out_of_range.hpp>

#include <fas/except/throw_.hpp>

#include <fas/range/distance.hpp>
#include <fas/range/string_range.hpp>
//#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgExcept>
struct ad_end_fragment
{
  typedef TgExcept _except_;
  
  template<typename T, typename R>
  bool peek( T&, R r)
  {
    std::cout << "ad_end_fragment::peek" << std::endl;
    return !r;
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    std::cout << "ad_end_fragment::()" << std::endl;
    if ( !rr.first )
      return throw_<_except_>( t, unexpected_end_fragment(), rr );

    return throw_<_except_>( t, expected_of("end fragment",  distance(rr.first) ), rr);
  }
};

}}}}

#endif

