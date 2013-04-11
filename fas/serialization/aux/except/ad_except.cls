//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

// #include <string>
// #include <fas/serialization/<<implementation defined>>/exception.hpp>

struct ad_except
{
  template<typename T>
  void clear(T&) {}

  operator bool () const { return false;}

  template<typename T, typename E>
  void operator()(T&, const E& e)
  {
    throw e;
  }

  template<typename T, typename R, typename E>
  R operator()(T&, const E& e, R )
  {
    throw e;
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

  exception except() const
  {
    return exception("", 0);
  }
};
