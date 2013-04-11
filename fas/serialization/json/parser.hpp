#ifndef FAS_SERIALIZATION_JSON_PARSER_HPP
#define FAS_SERIALIZATION_JSON_PARSER_HPP

#include <fas/aop/aspect_class.hpp>
#include <fas/serialization/json/except/except_aspect_type.hpp>
#include <fas/serialization/json/parse/aspect.hpp>
#include <utility>

namespace fas{ namespace json{

template<typename A = ::fas::aspect<> >
class parser
  : public aspect_class<A, parse::aspect_type, except_aspect_type >
{
  typedef aspect_class<A, parse::aspect_type, except_aspect_type > super;
public:
  typedef typename super::aspect aspect;

  operator bool () const
  {
    return !super::get_aspect().template get<_except_>();
  }

  template<typename R>
  R operator()(R r)
  {
    return r;
    //return parse(*this,r);
  }

  template<typename RI, typename RO>
  std::pair<RI, RO> operator()(RI ri, RO ro)
  {
    return std::make_pair(ri, ro);
    //return copy(*this,r, rd);
  }
};

}}

#endif
