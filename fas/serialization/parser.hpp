#ifndef FAS_SERIALIZATION_PARSER_HPP
#define FAS_SERIALIZATION_PARSER_HPP

#include <fas/serialization/tags.hpp>
#include <fas/serialization/f_clear.hpp>

#include <fas/range/range.hpp>
#include <fas/range/mrange.hpp>
#include <fas/range/orange.hpp>
#include <fas/range/range_traits.hpp>

#include <fas/aop/aspect_class.hpp>
#include <fas/aop/group_for_each.hpp>
#include <fas/typemanip/empty_type.hpp>
#include <utility>

namespace fas{ namespace serialization{

template<typename R, int flag>
struct parse_helper_impl;

template<typename R>
struct parse_helper_impl<R, typerange_flag::pointer>
{
  typedef R return_type;

  static inline string_range<R> make_iparam(R ptr)
  {
    return string_range<R>(ptr);
  }

  static inline string_range<R> make_oparam(R ptr)
  {
    return string_range<R>(ptr);
  }

  template<typename RR>
  static inline return_type make_return(RR rr)
  {
    return rr.first.begin();
  }
};

template<typename Ar>
struct parse_helper_impl<Ar, typerange_flag::array>
{
  typedef typename ::fas::typerange<Ar>::range::iterator return_type;

  static inline typename ::fas::typerange<Ar>::range make_iparam(Ar ptr)
  {
    return ::fas::range<Ar>(ptr);
  }

  static inline typename ::fas::typerange<Ar>::range make_oparam(Ar ptr)
  {
    return ::fas::range<Ar>(ptr);
  }

  template<typename RR>
  static inline return_type make_return(RR rr)
  {
    return rr.first.begin();
  }
};


template<typename R>
struct parse_helper_impl<R, typerange_flag::range>
{
  typedef R return_type;

  static inline R make_iparam(R r)
  {
    return r;
  }

  static inline R make_oparam(R r)
  {
    return r;
  }

  template<typename RR>
  static inline return_type make_return(RR rr)
  {
    return rr.first;
  }
};


template<typename It>
struct parse_helper_impl<It, typerange_flag::iterator >
{
  typedef typename ::fas::typerange<It>::range::iterator return_type;

  static inline typename ::fas::typerange<It>::range make_iparam(It it)
  {
    return ::fas::range(it);
  }

  // TODO: добавить в range
  static inline fas::output_range<It, typename It::value_type > make_oparam(It it)
  {
    return fas::output_range<It, typename It::value_type >(it);
  }

  template<typename RR>
  static inline return_type make_return(RR rr)
  {
    return rr.first.begin();
  }
};



template<typename R>
struct parse_helper
  : parse_helper_impl< R, typerange<R>::flag >
{
};

/*
 * 1. если указатель или итератор возвращаем указатель или итератор
 */
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

  operator bool () const
  {
    return !super::get_aspect().template get<_except_>();
  }

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

  

  /*
  template<typename R>
  struct helper: parse_helper_impl< R, typerange<R>::flag > {};

  template<typename P1>
  typename helper<P1>::return_type operator()(P1 p1)
  {
    return this->parse(*this, helper<P1>::make_iparam(p1) );
  }

  template<typename P1, typename P2>
  typename helper<P1>::return_type operator()(P1 p1, P2 p2)
  {
    return this->parse(*this, helper<P1>::make_iparam(p1), helper<P2>::make_oparam(p2) );
  }
  */

protected:


  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    typedef typename ::fas::range_traits<typename RR::first_type>::range_category  first_range_category;
    typedef typename ::fas::range_traits<typename RR::second_type>::range_category second_range_category;
    group_for_each<_clear_>( t, f_clear() );
    return t.get_aspect().template get<_parse_>()(t, rr);
  }

  /*
  template<typename T, typename R>
  typename helper<R>::return_type parse(T& t, R r)
  {
    return helper<R>::make_return(
      this->_parse(t, std::make_pair( r, mrange(r) ) )
    );
  }

  template<typename T, typename R, typename RO >
  typename helper<R>::return_type parse(T& t, R r, RO ro)
  {
    return helper<R>::make_return(
      this->_parse(t, std::make_pair( r, ro ) )
    );
  }
  */
  
private:

  /*
  template<typename T, typename RR>
  RR _parse(T& t, RR rr)
  {
    group_for_each<_clear_>( t, f_clear() );
    return t.get_aspect().template get<_parse_>()(t, rr);
  }
  */
  
};

}}

#endif
