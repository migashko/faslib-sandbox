#ifndef FAS_SERIALIZATION_DESER_AD_PROCESS_OR_PARSE_HPP
#define FAS_SERIALIZATION_DESER_AD_PROCESS_OR_PARSE_HPP

//#include <fas/except/throw_.hpp>

#include <fas/except/try_.hpp>
#include <fas/serialization/tags.hpp>
#include <utility>
/*
#include <fas/type_list/erase_c.hpp>
#include <fas/type_list/type_at_c.hpp>
#include <fas/type_list/length.hpp>
#include <fas/integral/int_.hpp>

#include <fas/type_list/empty_list.hpp>
*/

namespace fas{ namespace serialization{ namespace deser{

  
/*
template<typename Tg, typename TgParse>
struct ad_process_or_parse
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    t.get_aspect().template get<_status_>() = true;
    R orig = r;
    r = t.get_aspect().template get<Tg>()(t, J(), v, r);

    if ( !try_<_except_>(t) )
      return r;
    
    if ( !t.get_aspect().template get<_status_>() )
    {
      t.get_aspect().template get<_status_>() = true;
      // TODO: сделать _parse_(t, tag<TgParse>(), r);
      r = t.get_aspect().template get<TgParse>() (t, std::make_pair(orig, mrange(orig)) ).first;
    }
    return r;
  }
};

*/


}}}

#endif
