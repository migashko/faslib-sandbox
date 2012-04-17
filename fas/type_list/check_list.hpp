//
// Author: Vladimir Migashko <migashko@faslib.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_TYPE_LIST_CHECK_LIST_HPP
#define FAS_TYPE_LIST_CHECK_LIST_HPP


#include <fas/type_list/detail/check_list.hpp>
#include <fas/integral/bool_.hpp>


namespace fas{

template<typename L>
struct check_list
{
  typedef detail::check_list_helper<L> helper;
  typedef typename helper::error error;
  enum { value = helper::value};
  typedef bool_<value> type;
};

}


#endif
