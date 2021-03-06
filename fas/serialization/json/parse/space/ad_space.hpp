//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_SPACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_SPACE_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_sequence.hpp>
#include <fas/type_list/type_list_n.hpp>
#include <fas/serialization/parse/nocopy.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_space_cp:
  ::fas::serialization::parse::ad_sequence<
    _space_variant_,
    /*_empty_,*/
    _end_space_
  >
{
};

typedef ::fas::serialization::common::parse::nocopy<ad_space_cp> ad_space;

}}}

#endif
