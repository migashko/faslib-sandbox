#ifndef FAS_SERIALIZATION_DESERIALIZER_HPP
#define FAS_SERIALIZATION_DESERIALIZER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/except/tags.hpp>
#include <fas/serialization/deser/aspect.hpp>
#include <fas/aop/aspect_class.hpp>
#include <fas/typemanip/reference_wrapper.hpp>

namespace fas{ namespace serialization{

template<
  typename A1
>
class deserializer
  : public aspect_class<A1, deser::aspect >
{
  typedef aspect_class<A1, deser::aspect > super;
public:
  typedef typename super::aspect aspect;
  typedef typename super::aspect::template advice_cast<_except_>::type::exception_type exception_type;

  template<typename J, typename V, typename R>
  R operator()(J, V& v, R r)
  {
    return super::get_aspect().template get<_deser_>()(*this, J(), v, r);
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
