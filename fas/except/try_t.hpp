//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_TRY_T_HPP
#define FAS_EXCEPT_TRY_T_HPP

#include <utility>

namespace fas{

template<typename Tg, typename T>
inline bool try_t( T& t)
{
  typedef Tg _except_;
  return !t.get_aspect().template get<_except_>();
}

}

#endif
