//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2009, 2010, 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_JSON_NUMBER_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_JSON_NUMBER_HPP

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/parse_error.hpp>
#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgExcept>
struct ad_json_number
{
  typedef TgExcept _except_;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return r && ( *r=='-' || ( *r>='0' && *r<='9' ) );
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    return this->parse(t, rr );
  }

private:

  template<typename T, typename RR>
  RR parse_digits(T& t, RR rr)
  {
    if ( !rr.first )
      return throw_<_except_>( t, unexpected_end_fragment(), rr );

    if ( (*rr.first) < '0' || (*rr.first) > '9' )
      return throw_<_except_>( t, parse_error( distance(rr.first) ), rr);

    for ( ;rr.first && *rr.first >= '0' && *rr.first <= '9';)
    {
      if ( !rr.second )
        return throw_<_except_>( t, out_of_range(distance(rr.first) ), rr );

      *(rr.second++) = *(rr.first++);
    }
    return rr;
  }

  template<typename T, typename RR>
  RR parse(T& t, RR rr)
  {
    if ( !rr.first )
      return throw_<_except_>( t, unexpected_end_fragment(), rr );

    // if '-'
    if ( *rr.first == '-' )
    {
      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );
      *(rr.second++)= *(rr.first++);
    }

    // if '0'
    if ( rr.first && *rr.first == '0')
    {
      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );
      *(rr.second++)= *(rr.first++);
      // 00 prohibited
      return rr;
    }
    else
    {
      rr = this->parse_digits(t, rr);

      if ( !try_<_except_>(t) )
        return rr;
    }

    // if '.'
    if ( rr.first && *rr.first=='.' )
    {
      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);

      if ( !rr.first )
        return throw_<_except_>( t, unexpected_end_fragment(), rr );

      rr = this->parse_digits(t, rr);

      if ( !try_<_except_>(t) )
        return rr;
    }

    // if 'e'
    if ( rr.first && ( *rr.first=='e' || *rr.first=='E' ) )
    {
      if ( !rr.second )
        return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++)= *(rr.first++);

      if ( !rr.first )
        return throw_<_except_>( t, unexpected_end_fragment(), rr );

      if ( rr.first && (*rr.first=='-' || *rr.first=='+'))
      {
        if ( !rr.second )
          return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr );

        *(rr.second++)= *(rr.first++);
      }

      rr = this->parse_digits(t, rr);
    }

    return rr;
  }
};

}}}}

#endif

