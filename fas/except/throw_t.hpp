//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_THROW_T_HPP
#define FAS_EXCEPT_THROW_T_HPP

namespace fas{

template<typename Tg, typename T, typename E>
inline void throw_t( T& t, const E& e)
{
  typedef Tg _except_;
  return t.get_aspect().template get<_except_>()( t, e);
}

template<typename Tg, typename T, typename E, typename P>
inline P throw_t( T& t, const E& e, P p)
{
  typedef Tg _except_;
  return t.get_aspect().template get<_except_>()( t, e, p);
}

}

#endif
