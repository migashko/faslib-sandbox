//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_EXCEPT_AD_NOEXCEPT_HPP
#define FAS_SERIALIZATION_COMMON_EXCEPT_AD_NOEXCEPT_HPP

#include <string>
#include <fas/serialization/common/except/common_error.hpp>

namespace fas{ namespace serialization{

struct ad_noexcept
{
  ad_noexcept()
    : _except_fmm(false)
    , _error("")
  {
  }
  
  template<typename T>
  void clear(T&) 
  {
    _error = common_error("");
    _except_fmm = false; 
  }
  
  operator bool () const 
  {
    return _except_fmm;
  }

  template<typename T>
  void operator()(T&, const common_error& e )
  {
    _except_fmm = true;
    _error = e;
  }

  template<typename T, typename R>
  R operator()(T&, const common_error& e, R r )
  {
    _except_fmm = true;
    _error = e;
    return r;
  }
  
  std::string what() const
  {
    return _error.what();
  }

  template<typename R>
  std::string message(R r) const
  {
    return _error.message(r);
  }

  const common_error& exception() const
  {
    return _error;
  }

private:
  // fucking microsoft macro
  bool _except_fmm;
  common_error _error;
};

}}

#endif
