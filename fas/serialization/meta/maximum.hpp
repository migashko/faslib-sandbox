#ifndef FAS_SERIALIZATION_META_MAXIMUM_HPP
#define FAS_SERIALIZATION_META_MAXIMUM_HPP

#include <fas/serialization/proval/tags.hpp>

namespace fas{ namespace serialization{

template<typename N>
struct maximum
{
  typedef proval::_value_check_ tag;

  template<typename V>
  bool operator() (const V& v) const
  {
    return v <= N::value;
  }
};


}}

#endif
