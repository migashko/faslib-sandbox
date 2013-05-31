//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PROVAL_ASPECT_HPP
#define FAS_SERIALIZATION_PROVAL_ASPECT_HPP

#include <fas/serialization/proval/ad_value_check.hpp>
#include <fas/serialization/proval/ad_process_value.hpp>
#include <fas/serialization/proval/ad_proval.hpp>
#include <fas/serialization/proval/tags.hpp>

namespace fas{ namespace serialization{ namespace proval{

typedef aspect< type_list_n<
  advice<_value_check_, ad_value_check>,
  advice<_check_list_, ad_process_value>,
  advice<_proval_, ad_proval<_check_list_> >
>::type > aspect;

}}}

#endif
