//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_ASPECT_HPP
#define FAS_SERIALIZATION_EXCEPT_ASPECT_HPP

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/aop/group.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/except/exception.hpp>
#include <fas/serialization/tags.hpp>

#include <fas/except/ad_except.hpp>
#include <fas/except/ad_disabled_except.hpp>
#include <fas/except/ad_deferred_except.hpp>

namespace fas{ namespace serialization{ namespace except{

typedef ::fas::aspect< type_list_n<
  advice<_except_, ::fas::ad_except< exception > >,
  group< _clear_, _except_>
>::type > aspect;

typedef ::fas::aspect< type_list_n<
  advice<_except_, ::fas::ad_disabled_except< exception > >,
  group< _clear_, _except_>
>::type > aspect_disable;

typedef ::fas::aspect< type_list_n<
  advice<_except_, ::fas::ad_deferred_except< exception > >,
  group< _clear_, _except_>
>::type > aspect_deferred;


}}}

#endif
