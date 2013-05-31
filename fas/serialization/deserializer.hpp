#ifndef FAS_SERIALIZATION_DESERIALIZER_HPP
#define FAS_SERIALIZATION_DESERIALIZER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/except/tags.hpp>
#include <fas/aop/aspect_class.hpp>

namespace fas{ namespace serialization{

template<
  typename A1,
  typename A2 = empty_type,
  typename A3 = empty_type,
  typename A4 = empty_type,
  typename A5 = empty_type
>
class deserializer
  : public aspect_class<A1, A2, A3, A4, typename aspect_merge<A5, ::fas::serialzation::aspect>::type >
{
  typedef aspect_class<A1, A2, A3, A4, typename aspect_merge<A5, ::fas::serialzation::aspect>::type > super;
public:
  typedef typename super::aspect aspect;
  typedef typename super::aspect::template advice_cast<_except_>::type::exception_type exception_type;

  template<typename J, typename V, typename R>
  R operator()(J, V& v, R r)
  {
    return t.get_aspect().template get<_deser_>()(t, J(), v, r); 
  }

  operator bool () const
  {
    return !super::get_aspect().template get<_except_>();
  }

  exception_type exception() const
  {
    return super::get_aspect().template get<_except_>().exception();
  }
};

}}

#endif
