//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_AUX_EXCEPT_OUT_OF_RANGE_HPP
#define FAS_SERIALIZATION_AUX_EXCEPT_OUT_OF_RANGE_HPP

#include <fas/serialization/aux/except/exception.hpp>
#include <string>

namespace fas{ namespace serialization{ namespace aux{

class out_of_range
  : public exception
{
public:
  typedef exception::size_type size_type;

  out_of_range(size_type tail_of = 0)
    : exception( "out of range", tail_of) {}

  out_of_range(const std::string& str, size_type tail_of = 0)
   : exception( std::string("out of range: ") + str, tail_of ) {}
};

}}}

#endif
