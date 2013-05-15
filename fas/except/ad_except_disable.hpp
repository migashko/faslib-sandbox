//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_AD_EXCEPT_DISABLE_HPP
#define FAS_EXCEPT_AD_EXCEPT_DISABLE_HPP


namespace fas{

template<typename Ex = std::exception >
struct ad_except_disable
{
  typedef Ex exception_type;
  
  ad_except_disable()
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
