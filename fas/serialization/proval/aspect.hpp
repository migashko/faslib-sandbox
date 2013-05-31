//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PROVAL_ASPECT_HPP
#define FAS_SERIALIZATION_PROVAL_ASPECT_HPP

namespace fas{ namespace serialization{ namespace proval{

typedef ::fas::aspect< fas::type_list_n<
  ::fas::advice<_value_check_, ad_value_check>,
  ::fas::advice<_process_value_, ad_process_value>,
  ::fas::advice<_proval_, ad_proval>
>::type > aspect_basic

}}}

#endif
