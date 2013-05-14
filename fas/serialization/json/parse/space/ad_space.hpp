//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_SPACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_SPACE_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_list.hpp>
#include <fas/type_list/type_list_n.hpp>


namespace fas{ namespace json{ namespace parse{

struct ad_space:
  ::fas::serialization::common::parse::ad_list<
    _space_variant_,
    _empty_,
    _end_space_,
    _except_
  >
{};

}}}

#endif
