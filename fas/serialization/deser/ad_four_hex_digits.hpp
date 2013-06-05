#ifndef FAS_SERIALIZATION_DESER_AD_FOUR_HEX_DIGITS_HPP
#define FAS_SERIALIZATION_DESER_AD_FOUR_HEX_DIGITS_HPP

#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/parse_error.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace deser{
  
struct ad_four_hex_digits
{
  template<typename T, typename RR>
  RR operator()( T& t, RR rr)
  {
    if ( !rr.first )
      return throw_<_except_>(t, unexpected_end_fragment(), rr.first );
    
    unsigned short hex = 0;

    const unsigned short fail_value = static_cast<unsigned short>(-1);
    unsigned short value = uchar2ushort(rr.first++);
    
    // //////////////
    if ( value != fail_value )
      hex |= value << 12;
    else
      return throw_<_except_>(t, parse_error( distance(rr.first) ), rr );

    if (!rr.first)
      return throw_<_except_>(t, unexpected_end_fragment(), rr );

    // //////////////
    value = uchar2ushort(rr.first++);
    if ( value != fail_value )
      hex |= value << 8;
    else
      return throw_<_except_>(t, parse_error( distance(rr.first) ), rr );

    if (!rr.first)
      return throw_<_except_>(t, unexpected_end_fragment(), rr.first );

    // //////////////
    value = uchar2ushort(rr.first++);
    if ( value != fail_value )
      hex |= value << 4;
    else
      return throw_<_except_>(t, parse_error( distance(rr.first) ), rr );

    if (!rr.first)
      return throw_<_except_>(t, unexpected_end_fragment(), rr.first );

    // //////////////

    value = uchar2ushort(rr.first++);
    if ( value != fail_value )
      hex |= value;
    else
      return throw_<_except_>(t, parse_error( distance(rr.first) ), rr );

    // //////////////
    if ( hex <= 0x007F )
      *(rr.second++) = static_cast<unsigned char>(hex);
    else if ( hex <= 0x007FF )
    {
      *(rr.second++) = 192 | static_cast<unsigned char>( hex >> 6 );

      if ( !rr.second )
        return throw_<_except_>(t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++) = 128 | ( static_cast<unsigned char>( hex ) & 63 );
    }
    else
    {
      *(rr.second++) = 224 | static_cast<unsigned char>( hex >> 12 );

      if ( !rr.second )
        return throw_<_except_>(t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++) = 128 | ( static_cast<unsigned char>( hex >> 6 ) & 63 );

      if ( !rr.second )
        return throw_<_except_>(t, out_of_range( distance(rr.first) ), rr );

      *(rr.second++) = 128 | ( static_cast<unsigned char>( hex ) & 63 );
    }
    return rr;
  }

  template<typename R>
  unsigned short uchar2ushort(R c)
  {
    register unsigned short ch = *c;
    if ( ch >= '0' && ch<='9' ) return ch - '0';
    if ( ch >= 'a' && ch<='f' ) return (ch - 'a') + 10;
    if ( ch >= 'A' && ch<='F' ) return (ch - 'A') + 10;
    return static_cast<unsigned short>(-1);
  }
};

}}}

#endif
