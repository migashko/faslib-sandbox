//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

// #include <string>
// #include <fas/serialization/<<implementation defined>>/exception.hpp>

class ad_emptyexcept
{
public:
  ad_emptyexcept()
    : _except(false)
  {
    _except = false;
  }

  template<typename T>
  void clear(T&)
  {
    _except = false;
  }

  operator bool () const
  {
    return _except;
  }

  template<typename T, typename E>
  void operator()(T&, const E& e )
  {
    _except = true;
  }

  template<typename T, typename R, typename E>
  R operator()(T&, const E& e, R r )
  {
    _except = true;
    return r;
  }

  std::string what() const
  {
    return std::string();
  }

  template<typename R>
  std::string message(R) const
  {
    return std::string();
  }

  exception exception() const
  {
    return exception("", 0);
  }

private:
  bool _except;
};
