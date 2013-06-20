#ifndef FAS_SERIALIZATION_DESER_AD_PARSE_COPY_HPP
#define FAS_SERIALIZATION_DESER_AD_PARSE_COPY_HPP

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/parse_error.hpp>
#include <fas/serialization/tags.hpp>


#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>
#include <fas/type_list/normalize.hpp>

namespace fas{ namespace serialization{ namespace deser{

// first priority
template<typename TgList, typename TgEnd>
struct ad_parse_copy
{
  typedef typename normalize<TgList>::type target_list;
  typedef TgEnd _end_;
  
  //template<typename T, typename RR>
  //RR operator()(T& t, RR rr)
  template<typename T, typename J, typename VR, typename R>
  R operator()(T& t, J, VR vr, R r)
  {
    if ( t.get_aspect().template get<_end_>().peek(t, r) )
      return r;

    do {
      // r = _(t, std::make_pair(r, vr), target_list() ).first;
      std::pair<R, typename VR::type> rp = _(t, std::make_pair(r, vr.get() ), target_list() );
      r = rp.first;
      vr = rp.second;
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        break;
    } while ( try_<_except_>(t) );
    return r;
  }

private:
  
  template<typename T, typename RR, typename TagList>
  RR _(T& t, RR rr, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;

    while( t.get_aspect().template get<_head_>().peek(t, rr.first) )
    {
      rr = t.get_aspect().template get<_head_>()(t, rr);
      if ( !try_<_except_>(t) )
        return rr;
      if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
        return rr;
    }

    return _(t, rr, typename ::fas::tail<TagList>::type() );
  }

  template<typename T, typename RR>
  RR _(T&, RR rr, empty_list)
  {
    return rr;
  }
};
  
}}}

#endif
