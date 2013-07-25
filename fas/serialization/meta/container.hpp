#ifndef FAS_SERIALIZATION_META_CONTAINER_HPP
#define FAS_SERIALIZATION_META_CONTAINER_HPP

#include <fas/serialization/tags.hpp>

namespace fas{ namespace serialization{

struct append{};

template<typename T, typename S = empty_type>
struct container
{ 
  typedef S size;
  typedef _container_ tag;  
  typedef T target;
};


}}

#endif
