//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_RANGE_MRANGE_HPP
#define FAS_RANGE_MRANGE_HPP

#include <fas/range/moke_range.hpp>
#include <fas/range/typerange.hpp>

namespace fas{

template<typename IC>
inline moke_range<typename typerange<IC>::range::iterator > mrange(const IC&)
{
  return moke_range<typename typerange<IC>::range::iterator >();
}

}

#endif
