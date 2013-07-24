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
#include <fas/range/mrange.hpp>

namespace fas{ namespace serialization{ namespace deser{


//template<typename Tg>
struct ad_parser
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V&, R r)
  {
    typedef typename J::parser_tag _tag_;
    return t.get_aspect().template get<_tag_>()(t, std::make_pair(r, mrange(r))).first;
  }  
};


}}}

#endif
