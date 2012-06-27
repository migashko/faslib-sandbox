//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2007, 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_STATIC_CHECK_STATIC_CHECK_HPP
#define FAS_STATIC_CHECK_STATIC_CHECK_HPP

namespace fas{

template<int>
struct static_check;

template<>
struct static_check<true>
{
  enum { value = 1 };
};


}

#endif
