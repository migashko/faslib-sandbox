#ifndef FAS_SERIALIZATION_PARSER_AD_ENTITY_HPP
#define FAS_SERIALIZATION_PARSER_AD_ENTITY_HPP

#include <fas/serialization/tags.hpp>

#include <fas/except/try_.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>

namespace fas{ namespace serialization{ namespace parse{

template<typename TgList/*, bool NearPeek*/>
struct ad_entity
{
  typedef typename ::fas::normalize<TgList>::type tag_list;
  
  template<typename T, typename R>
  bool peek( T& t, R r)
  {
    // return _peek(t, r, tag_list() );
    // однозначно идентифицируется первым элементом 
    typedef typename ::fas::head<tag_list>::type _first_;
    return t.get_aspect().template get<_first_>().peek(t, r);
    
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    //std::cout << "entity:" << &*rr.first << std::endl;
    return _(t, rr, tag_list() );
  }
  
private:

  template<typename T, typename RR, typename TagList>
  RR _(T& t, RR rr, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
    //std::cout << "entity next:" << &*rr.first << std::endl;

    rr = t.get_aspect().template get<_head_>()(t, rr);

    if ( !try_<_except_>(t) )
      return rr;

    return _(t, rr, typename ::fas::tail<TagList>::type() );

  }

  template<typename T, typename RR>
  RR _(T&, RR rr, ::fas::empty_list)
  {
    return rr;
  }

  /*
  template<typename T, typename R, typename TagList>
  bool _peek(T& t, R r, TagList)
  {
    typedef typename ::fas::head<TagList>::type _head_;
    if ( !t.get_aspect().template get<_head_>().peek(t, r) )
      return false;
    if ( NearPeek )
        return true;
    return _peek(t, r, typename ::fas::tail<TagList>::type() );


  }

  template<typename T, typename R>
  bool _peek(T&, R, ::fas::empty_list)
  {
    return true;
  }
  */

};

}}}

#endif
