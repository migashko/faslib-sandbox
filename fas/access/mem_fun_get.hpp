//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ACCESS_MEMBER_FUN_GET_HPP
#define FAS_ACCESS_MEMBER_FUN_GET_HPP

namespace fas{

template<typename V, typename VT, VT (V::* mg)(void) const>
struct mem_fun_get
{
  VT operator()(const V& v) const
  {
    return (v.*mg)();
  }
};

}

#endif
