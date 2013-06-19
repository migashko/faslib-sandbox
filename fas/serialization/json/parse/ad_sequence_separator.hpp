//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_SEQUENCE_SEPARATOR_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_SEQUENCE_SEPARATOR_HPP

#include <fas/serialization/parse/ad_variant.hpp>
#include <fas/serialization/json/parse/tags.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_sequence_separator:
  ::fas::serialization::parse::ad_variant< type_list_n<
    _comma_,
    _empty_
  >::type >
{};

}}}

#endif
