//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ACCESS_MEMBER_FUN_SET_HPP
#define FAS_ACCESS_MEMBER_FUN_SET_HPP

#include <fas/typemanip/remove_cvrp.hpp>

namespace fas{

template<typename V, typename VT, void (V::* mg)(VT), typename VVT = typename remove_cvrp<VT>::type >
struct mem_fun_set
{
  mem_fun_set():_obj() {}

  VVT& operator()(V& v)
  {
    _obj = &v;
    return _value;
  }

  ~mem_fun_set()
  {
    if ( _obj )
      (_obj->*mg)(_value);
  }
private:
  V*  _obj;
  VVT _value;
};

}

#endif
