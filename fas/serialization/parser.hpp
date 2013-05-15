#ifndef FAS_SERIALIZATION_PARSER_HPP
#define FAS_SERIALIZATION_PARSER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/f_clear.hpp>
#include <fas/range/range_traits.hpp>
#include <fas/range/mrange.hpp>


#include <fas/aop/aspect_class.hpp>
#include <fas/aop/group_for_each.hpp>
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
class parser
  : public aspect_class<A1, A2, A3, A4, A5>
{
  typedef aspect_class<A1, A2, A3, A4, A5> super;
public:
  typedef typename super::aspect aspect;
  typedef typename super::aspect::template advice_cast<_except_>::type::exception_type exception_type;
  

  template<typename RI>
  RI operator()( RI ri )
  {
    return this->parse(*this, std::make_pair( ri, mrange(ri) ) ).first;
  }

  template<typename RI, typename RO>
  std::pair<RI, RO> operator()( RI ri, RO ro )
  {
    return this->parse(*this, std::make_pair( ri, ro ) );
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

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    typedef typename ::fas::range_traits<typename RR::first_type>::range_category  first_range_category;
    typedef typename ::fas::range_traits<typename RR::second_type>::range_category second_range_category;
    
    group_for_each<_clear_>( t, f_clear() );
    
    return t.get_aspect().template get<_parse_>()(t, rr);
  }

private:

};

}}

#endif
