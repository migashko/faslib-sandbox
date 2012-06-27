//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_RANGE_RANGE_HPP
#define FAS_RANGE_RANGE_HPP

#include <fas/range/typerange.hpp>


namespace fas{

template<typename I>
inline typename typerange<I>::range range(I beg, I end)
{
  return typerange<I>::make_range(beg, end);
}

template<typename IC>
inline typename typerange<const IC>::range range(const IC& cnt)
{
  return typerange<const IC>::make_range(cnt);
}


template<typename IC>
inline typename typerange<IC>::range range(IC& cnt)
{
  return typerange<IC>::make_range(cnt);
}

}

#endif
