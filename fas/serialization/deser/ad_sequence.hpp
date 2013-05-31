//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>


namespace fas{ namespace serialization{ namespace deser{

template<typename TgList>
struct ad_sequence
{
  typedef typename ::fas::normalize<TgList>::type tag_list;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    R orig = r;
    r =  _(t, J(), v, r, tag_list() );

    if ( !try_<_except_>(t) )
      return orig;

    if ( !t.get_aspect().template get<_status_>() )
      return orig;

    return r;
  }

private:

  template<typename T, typename J, typename V, typename R, typename TagList>
  R _(T& t, J, V& v, R r, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
    std::cout << "seq: " << r << std::endl;

    r = t.get_aspect().template get<_head_>()(t, J(), v, r);

    std::cout << "seq: " << t.get_aspect().template get<_status_>() << std::endl;

    if ( !try_<_except_>(t) )
    {
      std::cout << "seq: " << "except" << std::endl;
      return r;
    }

    if ( !t.get_aspect().template get<_status_>() )
      return r;

    return _(t, J(), v, r, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename J, typename V, typename R>
  R _(T& , J, V& , R r, empty_list)
  {
    std::cout << "seq: " << "final" << std::endl;
    return r;
  }
};

}}}

#endif
