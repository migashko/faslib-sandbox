//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2009, 2010, 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_COMMON_PARSE_AD_UTF8_LETTER_HPP
#define FAS_SERIALIZATION_COMMON_PARSE_AD_UTF8_LETTER_HPP

#include <fas/serialization/common/except/unexpected_end_fragment.hpp>
#include <fas/serialization/common/except/parse_error.hpp>
#include <fas/serialization/common/except/out_of_range.hpp>
#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>
#include <fas/integral/int_.hpp>
#include <utility>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgExcept>
struct ad_utf8_letter
{
  typedef TgExcept _except_;

  template<typename T, typename R>
  bool peek( T&, R r)
  {
    return r && (
      (*r & 128)==0 ||
      (*r & 224)==192 ||
      (*r & 240)==224 ||
      (*r & 248)==240
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
    /*
    0x00000000 — 0x0000007F: 0xxxxxxx
    0x00000080 — 0x000007FF: 110xxxxx 10xxxxxx
    0x00000800 — 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
    0x00010000 — 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */

    if (!rr.first)
      return throw_<_except_>( t, unexpected_end_fragment(), rr);

    // 1
    if ( (*rr.first & 128)==0 )
      return this->parse(t, rr, int_<0>());

    // 2
    if ( (*rr.first & 224)==192 )
      return this->parse(t, rr, int_<1>());

    // 3
    if ( (*rr.first & 240)==224 )
      return this->parse(t, rr, int_<2>());

    // 4
    if ( (*rr.first & 248)==240 )
      return this->parse(t, rr, int_<3>());

    return throw_<_except_>( t, parse_error( distance(rr.first) ), rr);
  }

  template<typename T, typename RR>
  RR parse(T& t, RR rr, int_<0>)
  {
    if (!rr.second)
      return throw_<_except_>( t, out_of_range( distance(rr.first) ), rr);

    *(rr.second++) = *(rr.first++);

    return rr;
  }

  template<typename T, typename RR, int N>
  RR parse(T& t, RR rr, int_<N>)
  {
    if (!rr.first)
      return throw_<_except_>( t, unexpected_end_fragment(), rr);

    rr = this->parse(t, rr, int_<0>() );

    if ( !try_<_except_>(t) )
      return rr;

    if ( (*rr.first & 192)==128 )
      return this->parse(t, rr, int_<N-1>() );

    return throw_<_except_>( t, parse_error( distance(rr.first) ), rr);
  }
};

}}}}

#endif
