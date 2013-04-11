//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_PARSE_ERROR_HPP
#define FAS_SERIALIZATION_EXCEPT_PARSE_ERROR_HPP

#include <fas/serialization/except/serialization_error.hpp>

namespace fas{ namespace serialization{

class parse_error
  : public serialization_error
{
public:
  typedef serialization_error::size_type size_type;

  parse_error(const std::string& msg, size_type tail_of = 0 )
    : serialization_error(msg, tail_of)
  { }

  parse_error(size_type tail_of = 0)
    : serialization_error("parse error", tail_of)
  {}
};

}}

#endif
