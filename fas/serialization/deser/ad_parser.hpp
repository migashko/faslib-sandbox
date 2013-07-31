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

struct ad_parser
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename J::parser_tag _tag_;
    return _(t, J(), v, r, typename J::parse_if(), typename J::copy());
  }
  
private:

  template<typename T, typename J, typename V, typename R>
  R _(T& t, J, V&, R r, false_, false_)
  {
    typedef typename J::parser_tag _tag_;
    return t.get_aspect().template get<_tag_>()(t, std::make_pair(r, mrange(r))).first;
  }

  template<typename T, typename J, typename V, typename R>
  R _(T& t, J, V&, R r, true_, false_)
  {
    typedef typename J::parser_tag _tag_;
    if ( !t.get_aspect().template get<_tag_>().peek(t, r))
      t.get_aspect().template get<_status_>() = false;
    else
      r = t.get_aspect().template get<_tag_>()(t, std::make_pair(r, mrange(r))).first;
    return r;
  }
 
// copy

  template<typename T, typename J, typename V, typename R>
  R _(T& t, J, V& v, R r, false_, true_)
  {
    typedef typename J::parser_tag _tag_;
    std::pair<R, V> res = t.get_aspect().template get<_tag_>()(t, std::make_pair(r, v));
    v = res.second;
    return res.first;
  }

  template<typename T, typename J, typename V, typename R>
  R _(T& t, J, V& v, R r, true_, true_)
  {
    typedef typename J::parser_tag _tag_;

    if ( !t.get_aspect().template get<_tag_>().peek(t, r))
      t.get_aspect().template get<_status_>() = false;
    else
    {
      std::pair<R, V> res = t.get_aspect().template get<_tag_>()(t, std::make_pair(r, v));
      r = res.first;
      v = res.second;
    }
    return r;
  }
};

}}}

#endif
