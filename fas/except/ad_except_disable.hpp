//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_AD_EXCEPT_DISABLE_HPP
#define FAS_EXCEPT_AD_EXCEPT_DISABLE_HPP


namespace fas{

struct ad_except_disable
{
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

private:
  
  bool _exception_flag;
};

}

#endif
