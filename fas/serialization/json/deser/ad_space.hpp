//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_DESER_AD_SPACE_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_SPACE_HPP

#include <fas/serialization/json/parse/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/common/deser/ad_parse.hpp>


namespace fas{ namespace json{ namespace parse{

struct ad_space:
  ::fas::serialization::common::deser::ad_parse<
    parse::_space_,
    _status_
  >
{
};


}}}

#endif
