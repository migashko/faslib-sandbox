#ifndef FAS_SERIALIZATION_DESER_AD_INTEGER_HPP
#define FAS_SERIALIZATION_DESER_AD_INTEGER_HPP

namespace fas{ namespace serialization{ namespace deser{

struct ad_integer
{
  template<typename T, typename J, typename V>
  void operator()(T& /*t*/, J, V& /*v*/)
  {
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T&, J, V& v, R r)
  {
    return this->deserealize(v, r);
  }

  template<typename V, typename R >
  R toto( V& v, R r )
  {
    if( !r )
      return r;

    v = 0;

    register bool neg = *r=='-';

    if ( neg ) ++r;

    if ( !r || *r < '0' || *r > '9')
      return r;

    // цифры с первым нулем запрещены (напр 001), только 0

    if ( *r == '0' )
      return ++r;

    for ( ;r; ++r )
    {
      if ( *r < '0' || *r > '9' )
        break;
      v = v*10 + (*r- '0');
    }

    if (neg) v*=-1;

    return r;
  }
  
private:

  template<typename V, typename R >
  R deserealize( V& v, R r )
  {
    if( !r )
      return r;

    v = 0;

    register bool neg = *r=='-';

    if ( neg ) ++r;

    if ( !r || *r < '0' || *r > '9')
      return r;

    // цифры с первым нулем запрещены (напр 001), только 0

    if ( *r == '0' )
      return ++r;

    for ( ;r; ++r )
    {
      if ( *r < '0' || *r > '9' )
        break;
      v = v*10 + (*r- '0');
    }

    if (neg) v*=-1;

    return r;
  }

};

}}}

#endif
