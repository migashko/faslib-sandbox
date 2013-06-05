//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_PARSE_AD_PARSE_HPP
#define FAS_SERIALIZATION_PARSE_AD_PARSE_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/f_clear.hpp>
#include <fas/range/range_traits.hpp>
#include <fas/range/mrange.hpp>
#include <fas/aop/group_for_each.hpp>

namespace fas{ namespace serialization{ namespace parse{

template<typename TgFirst>
struct ad_parse
{
  typedef TgFirst _tag_;
  
  template<typename T, typename R>
  R operator() (T& t, R r)
  {
    group_for_each<_clear_>( t, f_clear() );
    return t.get_aspect().template get<_tag_>()(t, std::make_pair( r, mrange(r) ) ).first;
  }
  
  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator() (T& t, RI ri, RO ro)
  {
    group_for_each<_clear_>( t, f_clear() );
    return t.get_aspect().template get<_tag_>()(t, std::make_pair( ri, ro ) );
  }
};

}}}

#endif
