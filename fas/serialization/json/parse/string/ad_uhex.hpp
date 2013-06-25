//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_UHEX_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_UHEX_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/json/parse/tags.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_uhex: 
  ::fas::serialization::parse::ad_entity< type_list_n<
    _backslash_u_,
    _four_hex_digits_
  >::type>
{};



}}}

#endif
