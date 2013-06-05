#ifndef FAS_SERIALIZATION_PARSER_HPP
#define FAS_SERIALIZATION_PARSER_HPP

#include <fas/aop/aspect_class.hpp>
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
  typedef typename super::aspect::template advice_cast< ::fas::serialization::_except_>::type::exception_type exception_type;
  

  template<typename RI>
  RI operator()( RI r )
  {
    return super::get_aspect().template get<_parse_>()(*this, r);
  }

  template<typename RI, typename RO>
  std::pair<RI, RO> operator()( RI ri, RO ro )
  {
    return super::get_aspect().template get<_parse_>()(*this, ri, ro);
  }

  operator bool () const
  {
    return !super::get_aspect().template get< ::fas::serialization::_except_>();
  }

  exception_type exception() const
  {
    return super::get_aspect().template get< ::fas::serialization::_except_>().exception();
  }

protected:

private:

};

}}

#endif
