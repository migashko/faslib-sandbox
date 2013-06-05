//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_AD_END_SPACE_HPP
#define FAS_SERIALIZATION_JSON_PARSE_AD_END_SPACE_HPP

#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/parse/ad_charset.hpp>
#include <fas/typemanip/tstring.hpp>

namespace fas{ namespace json{ namespace parse{


FAS_STRING(not_space, "\":{}[]ntf,+-0123456789")

struct ad_not_space:
  ::fas::serialization::parse::ad_charset< not_space>
{};

struct ad_end_space:
  ::fas::serialization::parse::ad_variant< type_list_n<
    _not_space_,
    _end_fragment_
  >::type >
{};


}}}

#endif
