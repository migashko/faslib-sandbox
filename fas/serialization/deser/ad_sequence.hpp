#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP

#include <fas/range/orange.hpp>
#include <fas/range/typerange.hpp>
#include <fas/typemanip/reference_wrapper.hpp>

namespace fas{ namespace serialization{ namespace deser{

template<typename Target, typename TgParseEnd>
struct ad_sequence1
{
  typedef Target          _target_;
  // typedef TgParseElement  _element_;
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    for (;;)
    {
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;

      r = t.get_aspect().template get<_target_>()(t, J(), v, r);

      if ( !t.get_aspect().template get<_status_>() )
        return r;

      if ( !try_<_except_>(t) )
        return r;
    }
  }
};

  
}}}

#endif
