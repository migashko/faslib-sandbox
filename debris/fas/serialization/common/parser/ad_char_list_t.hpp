#ifndef FAS_SERIALIZATION_COMMON_PARSER_AD_CHAR_LIST_T_HPP
#define FAS_SERIALIZATION_COMMON_PARSER_AD_CHAR_LIST_T_HPP

#include <fas/serialization/common/except/try_throw.hpp>
#include <fas/serialization/common/except/unexpected_end_fragment.hpp>
#include <fas/serialization/common/except/expected_of.hpp>
#include <fas/serialization/common/except/out_of_range.hpp>

#include <fas/range/distance.hpp>
#include <fas/range/srange.hpp>
#include <fas/range/string_range.hpp>

namespace fas{ namespace serialization{ namespace parse{
	
template<typename TChars, typename TgExcept>
struct ad_char_list_t
{
	typedef TgExcept _except_;
  typedef TChars tchars;
  
  template<typename T, typename R>
  bool check( T&, R r)
  {
    if (!r) return false;
    string_range< typename TChars::value_type > rr = srange( tchars()() );
    for ( ; rr; ++rr )
      if ( *r == *rr ) return true;
    return false;
  }
  
  template<typename T, typename R>
  R operator()(T& t, R r)
  {
    if (!r) return throw_t<_except_>( t, unexpected_end_fragment(), r );
    
    string_range< typename TChars::value_type > rr = srange( tchars()() );
    
    for ( ; rr; ++rr ) if ( *r == *rr )
      return ++r;
    return throw_t<_except_>( t, expected_of( tchars()(), distance(r) ), r );
  }
  
  template<typename T, typename R, typename RO>
  std::pair<R, RO> operator()(T& t, R r, RO ro)
  {
    if (!r) return throw_t<_except_>( t, unexpected_end_fragment(), r );

    string_range< typename TChars::value_type > rr = srange( tchars()() );

    for ( ; rr; ++rr ) if ( *r == *rr )
    {
      if (!ro)
        return throw_t<_except_>( t, out_of_range( tchars()(), distance(r) ), r, ro );
      *(ro++) = *rr;
      return std::make_pair(++r, ro);
    }
    
    return throw_t<_except_>( t, expected_of( tchars()(), distance(r) ), r, ro );
  }
  
};

}}}

#endif
