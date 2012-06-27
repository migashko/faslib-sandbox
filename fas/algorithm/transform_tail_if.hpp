//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ALGORITHM_TRANSFORM_TAIL_IF_HPP
#define FAS_ALGORITHM_TRANSFORM_TAIL_IF_HPP

#include <fas/algorithm/detail/transform_tail_if.hpp>
#include <fas/algorithm/algomacro.hpp>
#include <fas/mp/lambda.hpp>

namespace fas{

template<typename L, typename F, typename C >
struct transform_tail_if
{
  typedef typename detail::transform_tail_if_t_helper<
    L,
    lambda<FAS_T_SIMPLIFY(F)>::template apply,
    lambda<FAS_T_SIMPLIFY(C)>::template apply
  >::type type;
};

template<typename L, template<typename> class F, template<typename> class C >
struct transform_tail_if_t
{
  typedef typename detail::transform_tail_if_t_helper<
    L,
    F,
    C
  >::type type;

};

}

#endif
