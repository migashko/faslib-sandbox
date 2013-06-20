//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_PARSER_HPP
#define FAS_SERIALIZATION_DESER_AD_PARSER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/f_clear.hpp>
#include <fas/serialization/except/syntax_error.hpp>

#include <fas/aop/group_for_each.hpp>
#include <fas/except/throw_.hpp>
#include <fas/range.hpp>

namespace fas{ namespace serialization{ namespace deser{

  /*
struct ad_parser
{
  template<typename T, typename Tg, typename R>
  R operator()(T& t, tag<Tg>, R r)
  {
    return t.get_aspect().template get<Tg>()(t, std::make_pair(r, mrange(r)));
  }

  template<typename T, typename Tg, typename RI, typename RO>
  R operator()(T& t, tag<Tg>, RI ri, RO ro)
  {
    return t.get_aspect().template get<Tg>()(t, std::make_pair(ri, ro));
  }

};*/

}}}

#endif
