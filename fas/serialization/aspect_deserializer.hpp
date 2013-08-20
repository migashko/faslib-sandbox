//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_ASPECT_DESERIALIZER_HPP
#define FAS_SERIALIZATION_ASPECT_DESERIALIZER_HPP

#include <fas/aop/aspect.hpp>
#include <fas/aop/advice.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/serialization/tags.hpp>
#include <fas/serialization/ad_deser.hpp>
#include <fas/serialization/except/tags.hpp>

namespace fas{ namespace serialization{ 

  /*
typedef ::fas::aspect< type_list_n<
  value_advice<_status_, bool >,
  group<_clear_, _except_>,
  advice<_deser_, ad_deser>
>::type > aspect_deserializer;

*/

}}

#endif
