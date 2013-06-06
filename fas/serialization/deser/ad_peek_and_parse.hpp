//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_PEEK_AND_PARSE_HPP
#define FAS_SERIALIZATION_DESER_AD_PEEK_AND_PARSE_HPP

#include <fas/range/mrange.hpp>
#include <utility>
#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename TgParse>
struct ad_peek_and_parse
{
  typedef TgParse _parse_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& , R r)
  {
    std::cout << "ad_peek_and_parse 1" << std::endl;
    if ( !t.get_aspect().template get<_parse_>().peek(t, r) )
    {
      std::cout << "ad_peek_and_parse fail" << std::endl;
      t.get_aspect().template get<_status_>() = false;
      return r;
    }

    std::cout << "ad_peek_and_parse 2" << std::endl;
    return t.get_aspect().template get<_parse_>()
           ( t, std::make_pair(r, mrange(r)) ).first;
  }
};


}}}

#endif
