//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_EXPECTED_OF_HPP
#define FAS_SERIALIZATION_EXCEPT_EXPECTED_OF_HPP

#include <fas/serialization/except/syntax_error.hpp>

namespace fas{ namespace serialization{

class expected_of
  : public syntax_error
{
public:
  typedef syntax_error::size_type size_type;
  
  explicit expected_of(const std::string& str, size_type tail_of)
    : syntax_error( std::string("expected of '") + str + std::string("'"), tail_of)
  {}
    
  explicit expected_of(char ch, size_type tail_of)
    : syntax_error( std::string("expected of '") + ch + std::string("'"), tail_of)
  {}
    
};


}}

#endif
