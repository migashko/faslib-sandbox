//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_EXCEPT_ERROR_MESSAGE_HPP
#define FAS_SERIALIZATION_EXCEPT_ERROR_MESSAGE_HPP

#include <fas/serialization/except/serialization_error.hpp>

#include <fas/range/distance.hpp>
#include <fas/range/advance.hpp>
#include <fas/range/begin.hpp>
#include <fas/range/end.hpp>

#include <string>

namespace fas{ namespace serialization{

template<typename R>
inline std::string error_message(const serialization_error& e, R r)
{
  std::string message = e.what();
  
  if ( ::fas::distance(r) < e.tail_of() )
    return message;

  R rr = r;
  ::fas::advance(rr, ::fas::distance(r) - e.tail_of() );

  message += std::string(": ")
      + std::string( ::fas::begin(r), ::fas::begin(rr) )
      + ">>>"
      + std::string( ::fas::begin(rr), ::fas::end(r) );

  return message;
}

}}

#endif
