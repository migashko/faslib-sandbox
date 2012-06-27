//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2007, 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_INTEGRAL_BOOL2TYPE_HPP
#define FAS_INTEGRAL_BOOL2TYPE_HPP

#include <fas/integral/integral2type.hpp>

namespace fas{

template<bool i>
struct bool2type: integral2type<bool, i> {  };

}

#endif
