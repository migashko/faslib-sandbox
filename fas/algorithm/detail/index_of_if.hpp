//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ALGORITHM_DETAIL_INDEX_OF_IF_HPP
#define FAS_ALGORITHM_DETAIL_INDEX_OF_IF_HPP

#include <fas/type_list/length.hpp>

#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/is_organized.hpp>
#include <fas/type_list/errorlist.hpp>
#include <fas/type_list/metalist.hpp>

#include <fas/type_list/type_list.hpp>
#include <fas/type_list/empty_list.hpp>

#include <fas/static_check/static_error.hpp>

namespace fas{ namespace detail{
  
template<typename L, template<typename> class F >
struct index_of_if_impl_t;

template<typename M, typename L, template<typename> class F >
struct index_of_if_impl1_t;

template<typename L, template<typename> class F, bool B >
struct index_of_if_impl2_t;

#ifdef FASLIB_TYPE_LIST_CHECK

template<typename L, template<typename> class F>
struct index_of_if_helper_t
  : static_error< errorlist::not_type_list, is_type_list<L>::value >::type
  , static_error< errorlist::not_organized, is_organized<L>::value >::type
  , index_of_if_impl_t<L, F>
{
};

#else

template<typename L, template<typename> class F>
struct index_of_if_helper_t
  : index_of_if_impl_t<L, F>
{
};

#endif

template<typename L, template<typename> class F >
struct index_of_if_impl_t
{
  enum
  {
    first = index_of_if_impl1_t<typename L::metatype, L, F>::value,
    second = length<L>::value,
    value = ( static_cast<int>(first) == static_cast<int>(second) || second == 0)? -1 : first
  };
};

#ifndef DISABLE_TYPE_LIST_SPEC

template<typename L, typename R, template<typename> class F >
struct index_of_if_impl_t< type_list<L, R>, F >
{
  enum
  {
    first = index_of_if_impl2_t< type_list<L, R>, F, F<L>::type::value >::value,
    second = length< type_list<L, R> >::value,
    value = ( static_cast<int>(first) == static_cast<int>(second) || second == 0 )? -1 : first
  };
};

template< template<typename> class F >
struct index_of_if_impl_t< empty_list, F >
{
  enum { value = -1 };
};

#endif // DISABLE_TYPE_LIST_SPEC


template<typename L, template<typename> class F>
struct index_of_if_impl1_t<metalist::type_list, L, F>
{
  enum 
  {
    value = index_of_if_impl2_t< L, F, F<typename L::left_type>::type::value >::value 
  };
};

template<typename L, template<typename> class F>
struct index_of_if_impl1_t<metalist::empty_list, L, F>
{
  enum { value = 0 };
};

template<typename L, template<typename> class F>
struct index_of_if_impl2_t<L, F, true>
{
  enum { value = 0 };
};

template<typename L, template<typename> class F>
struct index_of_if_impl2_t<L, F, false>
{
  typedef typename L::right_type tail;
  enum { value = 1 + index_of_if_impl1_t<typename tail::metatype, tail, F>::value };
};


#ifndef DISABLE_TYPE_LIST_SPEC

template<typename L, typename LL, typename RR,  template<typename> class F>
struct index_of_if_impl2_t< type_list<L, type_list<LL, RR> >, F, false>
{
  enum { value = 1 + index_of_if_impl2_t< type_list<LL, RR>, F, F<LL>::type::value >::value };
};

template<typename L, template<typename> class  F>
struct index_of_if_impl2_t< type_list<L, empty_list>, F, false>
{
  enum { value = 1 };
};

template<template<typename> class F>
struct index_of_if_impl2_t<empty_list, F, true>
{
  enum { value = 0 };
};

#endif // DISABLE_TYPE_LIST_SPEC


}}


#endif
