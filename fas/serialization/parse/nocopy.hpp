//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_NOCOPY_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_NOCOPY_HPP

#include <fas/range/mrange.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename Base>
struct nocopy: Base
{
  template<typename T, typename RR>
  RR operator() (T& t, RR rr)
  {
    return RR(
      Base::operator()( t, std::make_pair(rr.first, ::fas::mrange(rr.first))).first,
      rr.second
    );
  }
};

}}}}

#endif
