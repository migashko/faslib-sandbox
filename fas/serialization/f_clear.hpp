#ifndef FAS_SERIALIZATION_F_CLEAR_HPP
#define FAS_SERIALIZATION_F_CLEAR_HPP

namespace fas{ namespace serialization{

struct f_clear
{
  template<typename T, typename Tg>
  void operator()(T& t, tag<Tg>)
  {
    t.get_aspect().template get<Tg>().clear(t);
  }
};

}}

#endif
