//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_INVALID_VALUE_HPP
#define FAS_SERIALIZATION_EXCEPT_INVALID_VALUE_HPP

#include <fas/serialization/except/exception.hpp>
#include <string>

namespace fas{ namespace serialization{ 

class invalid_value
  : public exception
{
public:
  typedef exception::size_type size_type;

  invalid_value(size_type tail_of = 0)
    : exception("invalid value", tail_of)  {}

  invalid_value(const std::string& str, size_type tail_of = 0)
   : exception( str, tail_of ) {}
};

}}

#endif
