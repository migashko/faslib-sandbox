#ifndef FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP
#define FAS_SERIALIZATION_DESER_AD_SEQUENCE_HPP

#include <fas/range/orange.hpp>
#include <fas/range/typerange.hpp>

namespace fas{ namespace serialization{ namespace deser{



// TgParseElement - вместе с запятой
template<typename Target, typename TgParseElement, typename TgParseEnd>
struct ad_sequence
{
  typedef Target          _target_;
  typedef TgParseElement  _element_;
  typedef TgParseEnd      _end_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {

    typedef typename typerange<V>::orange range_type;
    typedef typename range_type::value_type value_type;

    /*typedef typename J::target   target;
    typedef typename target::tag tag;*/

    range_type vr = orange(v);
    
    for (;;)
    {
      if ( t.get_aspect().template get<_end_>().peek(t, r) )
        return r;

      value_type value = value_type();
      R orig = r;
      t.get_aspect().template get<_status_>() = true;
      r = t.get_aspect().template get<_target_>()(t, J(), value, r);
      
      if ( t.get_aspect().template get<_status_>() )
        *(vr++) = value;
      else
        r = t.get_aspect().template get<_element_>()(t, std::make_pair(orig, mrange(r))).first;
    }
  }

};

}}}

#endif
