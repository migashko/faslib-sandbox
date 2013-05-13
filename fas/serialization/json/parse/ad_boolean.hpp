//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_BOOLEAN_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_BOOLEAN_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_variant.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_boolean:
  ::fas::serialization::common::parse::ad_variant<
    type_list_n<
      _true_,
      _false_
    >::type,
    _except_
  >
{};

}}}

#endif
