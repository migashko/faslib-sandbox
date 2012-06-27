//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_AOP_ALIAS_HPP
#define FAS_AOP_ALIAS_HPP

#include <fas/aop/metalist.hpp>

namespace fas{

template<typename Tg, typename TTg>
struct alias
{
  typedef metalist::alias metatype;
  typedef Tg tag;
  typedef TTg target;
};

}

#endif
