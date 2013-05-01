//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_ENCLOSED_ENTITY_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_ENCLOSED_ENTITY_HPP

#include <fas/serialization/common/except/out_of_range.hpp>
#include <fas/serialization/common/except/unexpected_end_fragment.hpp>
#include <fas/serialization/common/except/parse_error.hpp>
#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>
#include <utility>


namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgBegin, typename TgContent, typename TgEnd, typename TgExcept>
struct ad_enclosed_entity
{
  typedef TgBegin   _begin_;
  typedef TgContent _content_;
  typedef TgEnd     _end_;
  typedef TgExcept _except_;


  template<typename T, typename R>
  bool peek( T& t, R r)
  {
    return t.get_aspect().template get<_begin_>().peek(t, r);
  }

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    rr = t.get_aspect().template get<_begin_>()(t, rr.first, rr.second);

    if ( !try_<_except_>(t) )
      return rr;

    rr = t.get_aspect().template get<_content_>()(t, rr.first, rr.second);

    if ( !try_<_except_>(t) )
      return rr;

    rr = t.get_aspect().template get<_end_>()(t, rr.first, rr.second);

    if ( !try_<_except_>(t) )
      return rr;

    return rr;
  }

  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator()(T& t, RI ri, RO ro)
  {
    return this->parse(t, std::make_pair(ri, ro));
  }
};

}}}}

#endif
