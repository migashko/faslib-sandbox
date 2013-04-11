//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_SERIALIZATION_ERROR_HPP
#define FAS_SERIALIZATION_EXCEPT_SERIALIZATION_ERROR_HPP

#include <string>
#include <stdexcept>
#include <cstddef>

namespace fas{ namespace serialization{

class serialization_error
  : public std::logic_error
{

public:
  typedef std::ptrdiff_t size_type;

  serialization_error(const std::string& msg, size_type tail_of = 0 )
    : std::logic_error(msg)
    , _tail_of(tail_of)
  { }

  size_type tail_of() const
  {
    return _tail_of;
  }

private:
  
  size_type _tail_of;
};

}}

#endif
