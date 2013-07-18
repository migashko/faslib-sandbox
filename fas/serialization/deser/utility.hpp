#ifndef FAS_SERIALIZATION_UTILITY_HPP
#define FAS_SERIALIZATION_UTILITY_HPP

namespace fas{ namespace serialization{ namespace deser{

template<typename T, typename J, typename V, typename R>
R protar(T& t, J, V& v, R r)
{
  typedef typename J::target target;
  typedef typename target::tag _tag_;
  return t.get_aspect().template get<_tag_>()(t, target(), v, r);
}

template<typename T, typename L, typename V, typename R>
R protar_list(T& t, L, V& v, R r)
{
  typedef typename head<L>::type target;
  typedef typename tail<L>::type target_list;
  protar(t, target(), v, r);
  // TDOD: status
  if ( !t.get_aspect().template get<_status_>() )
    return r;
  return protar_list(t, target_list(), v, r);
}

template<typename T, typename V, typename R >
R protar_list(T& , empty_list, V&,  R r )
{
  return r;
}


///
/// process value 
///
  
template<typename T, typename J, typename V, typename R >
R proval(T& t, J, V& v, R r )
{
  typedef J target;
  typedef typename target::tag _tag_;
  t.get_aspect().template get<_tag_>()(t, target(), v);
  return r;
}

  
template<typename T, typename J, typename V, typename R >
R proval_list(T& t, J, V& v,  R r )
{
  typedef typename head<J>::type target;
  typedef typename tail<J>::type target_list;
  proval(t, target(), v,r);
  return proval_list(t, target_list(), v, r);
}
  
template<typename T, typename V, typename R >
R proval_list(T& , empty_list, V&,  R r )
{
  return r;
}


}}}

#endif
