//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_END_SPACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_END_SPACE_HPP

#include <fas/serialization/json/except/tags.hpp>
#include <fas/serialization/common/parse/ad_charset.hpp>
#include <fas/typemanip/tstring.hpp>

namespace fas{ namespace json{ namespace parse{

FAS_STRING(end_space, "\":{}[]ntf,+-0123456789")

struct ad_end_space:
  ::fas::serialization::common::parse::ad_charset< 
    end_space, 
    _except_
  >
{};

}}}

#endif
