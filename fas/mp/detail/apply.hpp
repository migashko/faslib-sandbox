//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_MP_DETAIL_APPLY_HPP
#define FAS_MP_DETAIL_APPLY_HPP

#include <fas/mp/is_placeholder.hpp>
#include <fas/mp/p.hpp>
#include <fas/mp/a.hpp>
#include <fas/mp/has_type.hpp>

namespace fas{ namespace detail{

template<typename F>
struct apply_helper;

template<typename F, int>
struct apply_impl;

template<typename F>
struct apply_impl2;

template<typename F, int>
struct apply_impl3;

template<typename F>
struct apply_helper
{
  typedef typename apply_impl<F, is_a<F>::value >::type type;
};

/// ///////////////////////////
template<typename F>
struct apply_impl<F, true>
{
  typedef typename una<F>::type type;
};

template<typename F>
struct apply_impl<F, false>
{
  typedef typename apply_impl2<F>::type apply_type;
  typedef typename apply_impl3<apply_type, has_type<apply_type>::value >::type type;
};

template<typename F>
struct apply_impl2_1;

template<typename F>
struct apply_impl2_2;

template<typename F>
struct apply_impl2_3;

template<typename F>
struct apply_impl2_4;


template<typename F>
struct apply_impl2
  : apply_impl2_4< F >
{
};

template<typename F>
struct apply_impl2_1
{
  typedef F type;
};

template<
  template<typename> class F,
  typename P0
>
struct apply_impl2_1< F<P0> >
{
  typedef P0 arg0;
  typedef F<
    typename apply_impl< arg0, is_a<arg0>::value >::type
  > type;
};

template<typename F>
struct apply_impl2_2
  : apply_impl2_1< F > 
{};

template<
  template<typename, typename> class F, 
  typename P0, typename P1
>
struct apply_impl2_2< F<P0, P1> >
{
  typedef P0 arg0;
  typedef P1 arg1;
  typedef F<
    typename apply_impl< arg0, is_a<arg0>::value >::type,
    typename apply_impl< arg1, is_a<arg1>::value >::type
  > type;
};

template<typename F>
struct apply_impl2_3
  : apply_impl2_2< F >
{};

template<
  template<typename, typename, typename> class F,
  typename P0, typename P1, typename P2
>
struct apply_impl2_3< F<P0, P1, P2> >
{
  typedef P0 arg0;
  typedef P1 arg1;
  typedef P2 arg2;
  typedef F<
    typename apply_impl< arg0, is_a<arg0>::value >::type,
    typename apply_impl< arg1, is_a<arg1>::value >::type,
    typename apply_impl< arg2, is_a<arg2>::value >::type
  > type;
};

template<typename F>
struct apply_impl2_4
  : apply_impl2_3< F >
{};

template<
  template<typename, typename, typename, typename> class F,
  typename P0, typename P1, typename P2, typename P3
>
struct apply_impl2_4< F<P0, P1, P2, P3> >
{
  typedef P0 arg0;
  typedef P1 arg1;
  typedef P2 arg2;
  typedef P3 arg3;
  typedef F<
    typename apply_impl< arg0, is_a<arg0>::value >::type,
    typename apply_impl< arg1, is_a<arg1>::value >::type,
    typename apply_impl< arg2, is_a<arg2>::value >::type,
    typename apply_impl< arg3, is_a<arg3>::value >::type
  > type;
};

template<
  template<typename, typename, typename, typename, typename> class F,
  typename P0, typename P1, typename P2, typename P3, typename P4
>
struct apply_impl2< F<P0, P1, P2, P3, P4> >
{
  typedef P0 arg0;
  typedef P1 arg1;
  typedef P2 arg2;
  typedef P3 arg3;
  typedef P4 arg4;
  typedef F<
    typename apply_impl< arg0, is_a<arg0>::value >::type,
    typename apply_impl< arg1, is_a<arg1>::value >::type,
    typename apply_impl< arg2, is_a<arg2>::value >::type,
    typename apply_impl< arg3, is_a<arg3>::value >::type,
    typename apply_impl< arg4, is_a<arg4>::value >::type
  > type;
};

template<typename F, int>
struct apply_impl3
{
  typedef typename F::type type;
};

template<typename F>
struct apply_impl3<F, false>
{
  typedef F type;
};


}}

#endif
