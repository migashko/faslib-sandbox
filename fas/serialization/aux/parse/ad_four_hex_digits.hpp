//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2009, 2010, 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_AUX_PARSE_AD_FOUR_HEX_DIGITS_HPP
#define FAS_SERIALIZATION_AUX_PARSE_AD_FOUR_HEX_DIGITS_HPP

#include <fas/serialization/aux/except/out_of_range.hpp>
#include <fas/serialization/aux/except/unexpected_end_fragment.hpp>
#include <fas/serialization/aux/except/parse_error.hpp>
#include <fas/except/throw_.hpp>
#include <fas/range/distance.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace aux{ namespace parse{

template<typename TgExcept>
struct ad_four_hex_digits
{
  typedef TgExcept _except_;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return r && (
                     ( *r >= '0' && *r <='9' )
                  || ( *r >= 'A' && *r <='F' )
                  || ( *r >= 'a' && *r <='f')
                );
  }

  template<typename T, typename RI, typename RO>
  std::pair<RI, RO> operator()(T& t, RI ri, RO ro)
  {
    return this->parse(t, std::make_pair(ri, ro) );
  }

private:

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    for (register int i=0; i < 4; ++i)
    {
      if ( !this->peek(t, rr.first) )
      {
        if (rr.first)
          return throw_<_except_>( t, parse_error( distance(rr.first) ), rr);
        else
          return throw_<_except_>( t, unexpected_end_fragment(), rr);
      }

      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);
    }
    return rr;
  }
};

}}}}

#endif
