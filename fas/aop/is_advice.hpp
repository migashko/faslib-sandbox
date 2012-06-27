//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_AOP_IS_ADVICE_HPP
#define FAS_AOP_IS_ADVICE_HPP

#include <fas/aop/metalist.hpp>

#include <fas/aop/advice.hpp>
#include <fas/aop/type_advice.hpp>
#include <fas/aop/value_advice.hpp>
#include <fas/aop/stub.hpp>

#include <fas/typemanip/is_has_metatype.hpp>
#include <fas/integral/bool_.hpp>

namespace fas{

template<typename T>
struct is_advice
{
  enum { value = is_has_metatype<T, metalist::advice>::value };
  typedef bool_< value > type;
};

template<typename Tg, typename T>
struct is_advice< advice<Tg, T> >
{
  enum { value = 1};
  typedef true_ type;
};

template<typename Tg, typename T>
struct is_advice< type_advice<Tg, T> >
{
  enum { value = 1};
  typedef true_ type;
};

template<typename Tg, typename T>
struct is_advice< value_advice<Tg, T> >
{
  enum { value = 1};
  typedef true_ type;
};

template<typename Tg, typename R>
struct is_advice< stub<Tg, R> >
{
  enum { value = 1};
  typedef true_ type;
};

}

#endif
