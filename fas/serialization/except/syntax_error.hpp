//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_SYNTAX_ERROR_HPP
#define FAS_SERIALIZATION_EXCEPT_SYNTAX_ERROR_HPP

#include <fas/serialization/except/exception.hpp>
#include <string>

namespace fas{ namespace serialization{ 

class syntax_error
  : public exception
{
public:
  typedef exception::size_type size_type;

  syntax_error(size_type tail_of = 0)
    : exception("syntax error", tail_of)  {}

  syntax_error(const std::string& str, size_type tail_of = 0)
   : exception( str, tail_of ) {}
};

}}

#endif
