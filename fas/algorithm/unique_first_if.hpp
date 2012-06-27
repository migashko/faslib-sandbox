//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_ALGORITHM_UNIQUE_FIRST_IF_HPP
#define FAS_ALGORITHM_UNIQUE_FIRST_IF_HPP

#include <fas/algorithm/detail/unique_first_if.hpp>
#include <fas/algorithm/algomacro.hpp>

#include <fas/mp/placeholders.hpp>
#include <fas/mp/lambda.hpp>

#include <fas/typemanip/some_type.hpp>
#include <fas/integral/less.hpp>

namespace fas{

template<typename L, template<typename, typename> class F >
struct unique_first_if_t
{
  typedef typename detail::unique_first_if_helper_t< L, F >::type type;
};

template<typename L, typename F = some_type<_1, _2> >
struct unique_first_if
{
  typedef typename detail::unique_first_if_helper_t< L, lambda_r< FAS_T_SIMPLIFY(F) , 2 >::template apply >::type type;
};


}


#endif
