#ifndef FAS_SERIALIZATION_JSON_DESER_AD_BOOLEAN_HPP
#define FAS_SERIALIZATION_JSON_DESER_AD_BOOLEAN_HPP

#include <fas/serialization/json/parser/tags.hpp>
//#include <fas/serialization/json/except/try_throw.hpp>


namespace fas{ namespace json{ namespace deser{

struct ad_boolean
{
  template<typename T, typename M, typename R>
  bool check(T& t, M, R r)
  {
    return t.get_aspect().template get<parse::_boolean_>().check(t, r)
           || t.get_aspect().template get<parse::_null_>().check(t, r);
  };

  template<typename T, typename M, typename V, typename R>
  R operator()(T& t, M, V& v, R r)
  {
    using namespace ::fas::json;
    if ( t.get_aspect().template get<parse::_null_>().check(t, r) )
    {
      r = t.get_aspect().template get<parse::_null_>()(t, r);
      v = V();
    }
    else if ( t.get_aspect().template get<parse::_boolean_>().check(t, r) )
    {
      if ( r && *r=='t') v = true;
      else v = false;
      r = t.get_aspect().template get<parse::_boolean_>()(t, r);
    }
    return r;
  }
};

}}}


#endif
