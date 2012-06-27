//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_AOP_IS_HAS_TAG_HPP
#define FAS_AOP_IS_HAS_TAG_HPP

#include <fas/aop/has_tag.hpp>
#include <fas/typemanip/is_has_typename.hpp>
#include <fas/integral/bool_.hpp>


namespace fas{

template<typename T, typename Tg>
struct is_has_tag
{
  enum { value = is_has_typename<T, Tg,  has_tag>::value };
  typedef bool_< value > type;
};

}

#endif
