
struct ad_integer
{
  template<typename T, typename M, typename R>
  bool peek(T& t, M, R r)
  {
    return t.get_aspect().template get<parse::_number_>().peek(t, r);
  }

  template<typename T, typename M, typename V, typename R>
  R operator()(T& t, M, V& v, R r)
  {
    if ( !this->peek(t, M(), r) )
      return throw_(t, syntax_error(distance(r)), r);
    return this->deserealize(v, r);
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

