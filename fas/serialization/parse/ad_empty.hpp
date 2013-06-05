//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PARSE_AD_EMPTY_HPP
#define FAS_SERIALIZATION_PARSE_AD_EMPTY_HPP

namespace fas{ namespace serialization{ namespace parse{

struct ad_empty
{
  template<typename T, typename R>
  bool peek( T&, R )
  {
    return true;
  }

  template<typename T, typename RR>
  RR operator() (T& , RR rr)
  {
    return rr;
  }
};

}}}

#endif
