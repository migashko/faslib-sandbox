#ifndef FAS_SERIALIZATION_JSON_META_RESTRICTION_HPP
#define FAS_SERIALIZATION_JSON_META_RESTRICTION_HPP

//#include <fas/serialization/json/ser/tags.hpp>
#include <fas/serialization/json/deser/tags.hpp>

//#include <fas/serialization/json/meta/metalist.hpp>

namespace fas{ namespace json{

template<typename N>
struct maximum
{
  typedef void precondition;
  typedef void postcondition;
  
  template<typename V>
  bool operator() (const V& v) const
  {
    return v >= N::value;
  }
};

template<typename N>
struct minimum
{
  typedef void precondition;
  typedef void postcondition;

  template<typename V>
  bool operator() (const V& v) const
  {
    return v <= N::value;
  }
};

template<typename F>
struct restriction
{
  //typedef metalist::number metatype;
  //typedef ser::_integer_ serializer_tag;
  typedef deser::_restriction_ deserializer_tag;

  template<typename V>
  bool operator()( const V& v ) const
  {
    return F()(v);
  }
};

}}

#endif
