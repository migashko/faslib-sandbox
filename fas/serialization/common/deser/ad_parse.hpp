//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_PARSER_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_PARSER_HPP

#include <fas/range/mrange.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgParse>
struct ad_parser
{
  typedef TgParse _parse_;
  
  /*
  template<typename T, typename J, typename R>
  bool peek( T& t, R r)
  {
    return true;
  }*/

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& , R r)
  {
    return t.get_aspect().template get<_parser_>()
           ( t, std::make_pair(r, mrange(r)) );
  }
};

}}}}

#endif
