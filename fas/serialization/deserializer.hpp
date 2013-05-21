#ifndef FAS_SERIALIZATION_DESERIALIZER_HPP
#define FAS_SERIALIZATION_DESERIALIZER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/f_clear.hpp>
#include <fas/except/throw_.hpp>
#include <fas/serialization/except/syntax_error.hpp>


#include <fas/aop/aspect_class.hpp>
#include <fas/aop/group_for_each.hpp>

#include <fas/range.hpp>

#include <fas/typemanip/empty_type.hpp>
#include <utility>


namespace fas{ namespace serialization{

template<
  typename A1,
  typename A2 = empty_type,
  typename A3 = empty_type,
  typename A4 = empty_type,
  typename A5 = empty_type
>
class deserializer
  : public aspect_class<A1, A2, A3, A4, A5>
{
  typedef aspect_class<A1, A2, A3, A4, A5> super;
public:
  typedef typename super::aspect aspect;
  typedef typename super::aspect::template advice_cast<_except_>::type::exception_type exception_type;
  

  template<typename J, typename V, typename R>
  R operator()(J, V& v, R r)
  {
    return this->deserialize(*this, J(), v, r);
  }

  operator bool () const
  {
    return !super::get_aspect().template get<_except_>();
  }

  exception_type exception() const
  {
    return super::get_aspect().template get<_except_>().exception();
  }

protected:

  template<typename T, typename J, typename V, typename R>
  R deserialize(T& t, J, V& v, R r)
  {
    typedef typename ::fas::range_traits<R>::range_category  first_range_category;
    typedef typename ::fas::range_traits<R>::range_category second_range_category;
    
    group_for_each<_clear_>( t, f_clear() );
    
    t.get_aspect().template get<_status_>() = true;
    
    r = t.get_aspect().template get< typename J::tag >()(t, J(), v, r);

    if ( false == t.get_aspect().template get<_status_>() )
      return throw_<_except_>(t, syntax_error(distance(r)), r);
    
    return r;
  }

private:

};

}}

#endif
