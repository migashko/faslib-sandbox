//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_EXCEPT_AD_DEFERRED_EXCEPT_HPP
#define FAS_EXCEPT_AD_DEFERRED_EXCEPT_HPP

#include <exception>

namespace fas{

template<typename E = std::exception >
struct ad_deferred_except
{
  typedef E exception_type;

  ~ad_deferred_except()
  {
    delete _exception;
    _exception = 0;
  }
  
  ad_deferred_except()
    : _exception(0)
  {
  }

  ad_deferred_except(const ad_deferred_except& exception)
  {
    ad_deferred_except::operator = (exception);
  }

  ad_deferred_except& operator = (const ad_deferred_except& exception)
  {
    if ( _exception == 0)
      _exception = new exception_type(*exception._exception);
    else
      *_exception = *exception._exception;
    return *this;
  }

  template<typename T>
  void clear(T&) 
  {
    delete _exception;
    _exception = 0;
  }
  
  operator bool () const 
  {
    return _exception!=0;
  }

  template<typename T>
  void operator()(T&)
  {
    if ( _exception == 0 )
      _exception = new exception_type();
    else
      *_exception = exception_type();
  }
  
  template<typename T>
  void operator()(T&, const exception_type& e )
  {
    if ( _exception == 0 )
      _exception = new exception_type(e);
    else
      *_exception = e;
  }

  template<typename T, typename P>
  P operator()(T& t, const exception_type& e, P p )
  {
    ad_deferred_except::operator ()( t, e );
    return p;
  }

  const exception_type* exception() const
  {
    return _exception;
  }

  void raise()
  {
    if (_exception)
      throw *_exception;
    throw;
  }

private:
  exception_type* _exception;
};

}

#endif
