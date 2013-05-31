#ifndef FAS_SERIALIZATION_AD_DESER_HPP
#define FAS_SERIALIZATION_AD_DESER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/f_clear.hpp>
#include <fas/except/throw_.hpp>
#include <fas/serialization/except/syntax_error.hpp>

#include <fas/aop/group_for_each.hpp>

#include <fas/range.hpp>

namespace fas{ namespace serialization{

struct ad_deser
{
  template<typename T, typename J, typename V, typename R>
  R deserialize(T& t, J, V& v, R r)
  {
    // R range verify
    typedef typename ::fas::range_traits<R>::range_category  first_range_category;
    
    group_for_each<_clear_>( t, f_clear() );
    
    t.get_aspect().template get<_status_>() = true;
    
    r = t.get_aspect().template get< typename J::tag >()(t, J(), v, r);

    if ( false == t.get_aspect().template get<_status_>() )
      return throw_<_except_>(t, syntax_error(distance(r)), r);
    
    return r;
  }
};

}}

#endif
