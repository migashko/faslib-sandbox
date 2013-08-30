//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_AD_DISABLED_EXCEPT_HPP
#define FAS_EXCEPT_AD_DISABLED_EXCEPT_HPP

#include <exception>

namespace fas{

template<typename Ex = std::exception >
struct ad_disabled_except
{
  typedef Ex exception_type;
  
  ad_disabled_except()
    : _exception_flag(false)
  {
  }
  
  template<typename T>
  void clear(T&) 
  {
    _exception_flag = false; 
  }
  
  operator bool () const
  {
    return _exception_flag;
  }

  template<typename T>
  void operator()(T&)
  {
    _exception_flag = true;
  }

  template<typename T, typename E>
  void operator()(T&, const E&  )
  {
    _exception_flag = true;
  }

  template<typename T, typename E, typename P>
  P operator()(T&, const E& , P p)
  {
    _exception_flag = true;
    return p;
  }

  exception_type exception() const
  {
    return exception_type();
  }

  void raise()
  {
    throw;
  }

private:
  
  bool _exception_flag;
};

}

#endif
