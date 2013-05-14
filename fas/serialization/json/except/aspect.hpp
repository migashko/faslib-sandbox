//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_EXCEPT_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_EXCEPT_ASPECT_HPP

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/aop/alias.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/except/ad_except.hpp>

namespace fas{ namespace json{ namespace except{

typedef ::fas::aspect< type_list_n<
  advice<_except_, ad_except>,
  alias< ::fas::serialization::_except_, _except_>,
  group< ::fas::serialization::_clear_, _except_>
>::type > aspect;

}}}

#endif
