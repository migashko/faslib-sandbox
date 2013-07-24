#ifndef FAS_SERIALIZATION_UTILITY_HPP
#define FAS_SERIALIZATION_UTILITY_HPP


#include <fas/aop/tag.hpp>
#include "../tags.hpp"

#include <fas/type_list/type_at.hpp>
#include <fas/type_list/head.hpp>
#include <fas/type_list/tail.hpp>
#include <fas/type_list/empty_list.hpp>

namespace fas{ namespace serialization{ namespace deser{

// Обертки для тегов
struct target{};

template<int>
struct target_n{};

struct ignore_status{};
struct false_status{};

template<typename T>
struct parser{};

template<typename T>
struct copy_parse{};


template<typename T>
struct deser{};

// entity

template<typename T, typename J, typename V, typename R>
R entity_(T& t, J, V& v, R r, target)
{
  typedef typename J::target target;
  typedef typename target::tag _tag_;
  return t.get_aspect().template get<_tag_>()(t, target(), v, r);
}

template<typename T, typename J, typename V, typename R, int N>
R entity_(T& t, J, V& v, R r, target_n<N>)
{
  typedef typename J::target_list target_list;
  typedef typename type_at_c<N, target_list>::type target;
  typedef typename target::tag _tag_;
  return t.get_aspect().template get<_tag_>()(t, target(), v, r);
}


template<typename T, typename J, typename V, typename R>
R entity_(T& t, J, V&, R r, ignore_status)
{
  t.get_aspect().template get<_status_>()=true;
  return r;
}

template<typename T, typename J, typename V, typename R>
R entity_(T& t, J, V&, R r, false_status)
{
  t.get_aspect().template get<_status_>()=false;
  return r;
}

template<typename T, typename J, typename V, typename R, typename Tg>
R entity_(T& t, J, V&, R r, parser<Tg>)
{
  return t.get_aspect().template get<Tg>()(t, std::make_pair(r, mrange(r))).first;
}

template<typename T, typename J, typename V, typename R, typename Tg>
R entity_(T& t, J, V& v, R r, copy_parse<Tg>)
{
  std::pair<R, V> res = t.get_aspect().template get<Tg>()(t, std::make_pair(r, v));
  v = res.second;
  return res.first;
  /*
  // TODO: ref
  return t.get_aspect().template get<Tg>()(t, std::make_pair(r, v)).first;
  */
}

template<typename T, typename J, typename V, typename R, typename Tg>
R entity_(T& t, J, V& v, R r, deser<Tg>)
{
  return t.get_aspect().template get<Tg>()(t, J(), v, r);
}

template<typename T, typename J, typename V, typename R>
R entity_(T&, J, V&, R r, empty_list)
{
  return r;
}

// return r - после последнкго успешного (перед первым fail)
template<typename T, typename J, typename V, typename R, typename L>
R entity_(T& t, J, V& v, R r, L)
{
  if ( !try_<_except_>(t) )
    return r;

  if ( !t.get_aspect().template get<_status_>() )
    return r;

  typedef typename head<L>::type head_item;
  typedef typename tail<L>::type tail_list;
  
  r = entity_(t, J(), v, r, head_item());
  
  return entity_(t, J(), v, r, tail_list());
}

// entity proval

template<typename T, typename J, typename V>
void entity_(T& t, J, V& v, target)
{
  typedef typename J::target target;
  typedef typename target::tag _tag_;
  t.get_aspect().template get<_tag_>()(t, target(), v);
}

template<typename T, typename J, typename V, int N>
void entity_(T& t, J, V& v, target_n<N>)
{
  typedef typename J::target_list target_list;
  typedef typename type_at_c<N, target_list>::type target;
  typedef typename target::tag _tag_;
  t.get_aspect().template get<_tag_>()(t, target(), v);
}

template<typename T, typename J, typename V>
void entity_(T&, J, V&, ignore_status)
{
}

template<typename T, typename J, typename V>
void entity_(T&, J, V&, false_status)
{
}

template<typename T, typename J, typename V, typename Tg>
void entity_(T&, J, V&, parser<Tg>)
{
}

template<typename T, typename J, typename V, typename Tg>
void entity_(T&, J, V&, copy_parse<Tg>)
{
}

template<typename T, typename J, typename V, typename Tg>
void entity_(T& t, J, V& v, deser<Tg>)
{
  t.get_aspect().template get<Tg>()(t, J(), v);
}

template<typename T, typename J, typename V>
void entity_(T&, J, V&, empty_list)
{
}

template<typename T, typename J, typename V, typename L>
void entity_(T& t, J, V& v, L)
{
  if ( !try_<_except_>(t) )
    return;

  typedef typename head<L>::type head_item;
  typedef typename tail<L>::type tail_list;
  
  entity_(t, J(), v, head_item());
  entity_(t, J(), v, tail_list());
}


///
  
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
