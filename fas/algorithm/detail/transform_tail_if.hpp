//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ALGORITHM_DETAIL_TRANSFORM_TAIL_IF_HPP
#define FAS_ALGORITHM_DETAIL_TRANSFORM_TAIL_IF_HPP

#include <fas/algorithm/transform.hpp>

#include <fas/type_list/length.hpp>
#include <fas/type_list/metalist.hpp>
#include <fas/type_list/type_at_c.hpp>
#include <fas/type_list/split_c.hpp>
#include <fas/type_list/merge.hpp>

namespace fas{ namespace detail{

template<int N, int NN, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl;

template<int N, int NN, typename L, template<typename> class F, template<typename> class C, int>
struct transform_tail_impl2;

template<int N, int NN, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl3;


template<typename L, template<typename> class F, template<typename> class C>
struct transform_tail_if_t_helper
  : transform_tail_impl< 0, length<L>::value, L, F, C >
{
};

template<int N, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl<N, N, L, F, C>
{
  typedef L type;
};

template<int N, int NN, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl
{
  typedef typename type_at_c<N, L>::type current;
  typedef typename transform_tail_impl2<N, NN, L, F, C, C< current >::type::value >::type type;
};

template<int N, int NN, typename L, template<typename> class F, template<typename> class C, int>
struct transform_tail_impl2
{
  typedef typename split_c< N, L >::left_list left_list;
  typedef typename split_c< N, L >::right_list right_list;
  typedef typename F< right_list >::type transform_list;
  
  typedef typename merge<left_list, transform_list>::type result_list;
  typedef typename transform_tail_impl3< N, length<result_list>::value, result_list, F, C>::type type;
};

template<int N, int NN, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl2< N, NN,  L, F, C, false >
{
  typedef typename transform_tail_impl< N + 1, NN,  L, F, C>::type type;
};

template<int N, int NN, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl3
{
  typedef typename transform_tail_impl< N + 1, NN,  L, F, C>::type type;
};

template<int N, typename L, template<typename> class F, template<typename> class C>
struct transform_tail_impl3<N, N, L, F, C>
{
  typedef L type;
};



}}

#endif
