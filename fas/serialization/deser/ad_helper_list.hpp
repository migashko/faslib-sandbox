#ifndef FAS_SERIALIZATION_DESER_AD_HELPER_LIST_HPP
#define FAS_SERIALIZATION_DESER_AD_HELPER_LIST_HPP

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/parse_error.hpp>
#include <fas/serialization/tags.hpp>


#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace deser{

// first priority
template<typename TgList, typename TgEnd>
struct ad_helper_list
{
  typedef organize<TgList> target_list;
  typedef TgEnd _end_;
  
  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
      return rr;
    
    do {
      rr = _(t, tt, target_list() );
      if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
        break;
    } while ( try_<_except_>(t) );
      
    return rr;
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
  R _(T&, RR rr, empty_list)
  {
    return rr;
  }
};
  
}}}

#endif
