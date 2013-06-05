#ifndef FAS_SERIALIZATION_DESER_AD_UTF8_LETTER_HPP
#define FAS_SERIALIZATION_DESER_AD_UTF8_LETTER_HPP

#include <fas/serialization/except/out_of_range.hpp>
#include <fas/serialization/except/unexpected_end_fragment.hpp>
#include <fas/serialization/except/parse_error.hpp>
#include <fas/serialization/tags.hpp>


#include <fas/except/throw_.hpp>
#include <fas/except/try_.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace serialization{ namespace deser{

// TODO: delete and use parse::ad_utf8_letter
struct ad_utf8_letter
{
  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    if ( (*rr.first & 128)==0 )
      *(rr.second++) = *(rr.first++);
    else if ( (*rr.first & 224)==192 )
      return utf8_copy_n<2>(t, rr);
    else if ( (*rr.first & 240)==224 )
      return utf8_copy_n<3>(t, rr);
    else if ( (*rr.first & 248)==240 )
      return utf8_copy_n<4>(t, rr);
    else
      return throw_<_except_>(t, parse_error( distance(rr.first) ), rr );
    return rr;
  }

private:
  
  template<int N, typename T, typename RR>
  RR utf8_copy_n(T& t, RR rr)
  {
    register int i = 0;
    for (; i < N && rr.first && rr.second ; ++i)
    {
      *(rr.second++) = *(rr.first++);
    }
    
    if ( i < N)
    {
      if (!rr.first)
        return throw_<_except_>(t, unexpected_end_fragment(), rr);

      if (!rr.second)
        return throw_<_except_>(t, out_of_range( distance(r.first) ), rr );
    }
    
    return rr;
  }
};
  
}}}

#endif
