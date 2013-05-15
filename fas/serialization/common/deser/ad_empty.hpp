//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_EMPTY_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_EMPTY_HPP

namespace fas{ namespace serialization{ namespace common{ namespace deser{

struct ad_empty
{
  template<typename T, typename J, typename R>
  bool peek( T&, R )
  {
    return true;
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T&, J, V& , R r)
  {
    return r;
  }
};

}}}}

#endif
