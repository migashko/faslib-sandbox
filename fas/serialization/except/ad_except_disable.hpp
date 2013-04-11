//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_AD_EXCEPT_DISABLE_HPP
#define FAS_SERIALIZATION_EXCEPT_AD_EXCEPT_DISABLE_HPP

#include <fas/except/ad_except_disable.hpp>

namespace fas{ namespace serialization{

struct ad_except:
  ::fas::ad_except_disable
{
};

}}

#endif
