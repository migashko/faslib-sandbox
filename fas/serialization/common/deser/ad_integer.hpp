#ifndef FAS_SERIALIZATION_COMMON_DESER_AD_INTEGER_HPP
#define FAS_SERIALIZATION_COMMON_DESER_AD_INTEGER_HPP

namespace fas{ namespace serialization{ namespace common{ namespace deser{

template<typename TgParseNumber>
struct ad_integer
{
  typedef TgParseNumber _number_;
  
  template<typename T, typename J, typename R>
  bool peek(T& t, J, R r)
  {
    return t.get_aspect().template get< _number_ >().peek(t, r);
  }

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    if ( !this->peek(t, J(), r) )
    {
      t.get_aspect().template get<_status_>() = false;
      return r;
    }
    r = this->deserealize(v, r);

    typedef typename J::target target;
    typedef typename target::deserializer_tag deserializer_tag;
    r = t.get_aspect().template get< deserializer_tag >()(t, target(), v, r);
    
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

    if (*r=='0')
      return ++r;

    for ( ;r; ++r )
    {
      if (*r < '0' || *r > '9')
        break;
      v = v*10 + (*r- '0');
    }

    if (neg) v*=-1;

    return r;
  }

};

}}}}

#endif
