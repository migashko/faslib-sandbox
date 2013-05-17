//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_COPY_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_COPY_HPP

#include <fas/range/range.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgParse, typename TgStatus>
struct ad_copy
{
  typedef TgParse _parse_;
  typedef TgStatus _status_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& , R r)
  {
    if ( !t.get_aspect().template get<_parse_>().peek(t, r) )
      t.get_aspect().template get<_status_>() = false;
    else
      r = t.get_aspect().template get<_parse_>()
           ( t, std::make_pair(r, range(r)) );
    return r;
  }
};


template<typename TgParse>
struct ad_copy_strong
{
  typedef TgParse _parse_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::target target;
    
    return t.get_aspect().template get<_parser_>()
           ( t, std::make_pair(r, range(v)) );
  }
};

}}}}

#endif
