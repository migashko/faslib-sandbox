//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_AD_EXCEPT_HPP
#define FAS_EXCEPT_AD_EXCEPT_HPP

namespace fas{

template<typename Ex = std::exception >
struct ad_except
{
  typedef Ex exception_type;
  
  template<typename T>
  void clear(T&) {}
  
  operator bool () const { return false;}

  template<typename T>
  void operator()(T&)
  {
    throw;
  }

  template<typename T, typename E>
  void operator()(T&, const E& e)
  {
    throw e;
  }

  template<typename T, typename E, typename P >
  P operator()(T&, const E& e, P )
  {
    throw e;
  }

  exception_type exception() const
  {
    return exception_type();
  }

  void raise()
  {
    throw;
  }
};

}

#endif
