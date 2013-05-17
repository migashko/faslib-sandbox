//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_SEQUENCE_HPP

#include <fas/except/throw_.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/range/distance.hpp>

#include <fas/except/try_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>


namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgList, typename TgExcept>
struct ad_sequence
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  typedef TgExcept _except_;


  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    return _(t, J(), v, r, tag_list() );
  }

private:

  template<typename T, typename J, typename V, typename R, typename TagList>
  R operator()(T& t, J, V& v, R r, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;

    r = t.get_aspect().template get<_head_>()(t, J(), v, r);

    if ( !try_<_except_>(t) )
      return rr;

    if ( !t.get_aspect().template get<_status_>() )
      return r;


    return _(t, J(), v, r, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename J, typename V, typename R, typename TagList>
  R operator()(T& , J, V& , R r, TagList)
  {
    return r;
  }
};

}}}}

#endif
