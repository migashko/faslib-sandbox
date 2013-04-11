//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

// #include <string>
// #include <fas/serialization/<<implementation defined>>/exception.hpp>

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
    _error = exception("");
    _except_fmm = false;
  }

  operator bool () const
  {
    return _except_fmm;
  }

  template<typename T>
  void operator()(T&, const exception& e )
  {
    _except_fmm = true;
    _error = e;
  }

  template<typename T, typename R>
  R operator()(T&, const exception& e, R r )
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

  const exceptionr& exception() const
  {
    return _error;
  }

private:
  // fucking microsoft macro
  bool _except_fmm;
  exception _error;
};
