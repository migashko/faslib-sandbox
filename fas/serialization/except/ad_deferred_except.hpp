//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_AD_DEFERRED_EXCEPT_HPP
#define FAS_SERIALIZATION_EXCEPT_AD_DEFERRED_EXCEPT_HPP

#include <fas/except/ad_except.hpp>
#include <fas/serialization/except/serialization_error.hpp>

namespace fas{ namespace serialization{

struct ad_deferred_except:
  ::fas::ad_deferred_except<serialization_error>
{
};

}}

#endif
