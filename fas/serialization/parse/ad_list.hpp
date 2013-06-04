#ifndef FAS_SERIALIZATION_COMMON_PARSER_AD_LIST_HPP
#define FAS_SERIALIZATION_COMMON_PARSER_AD_LIST_HPP

#include <fas/except/try_.hpp>

namespace fas{ namespace serialization{ namespace common{ namespace parse{

template<typename TgEntity, typename TgSeparator, typename TgEnd, typename TgExcept>
struct ad_list
{
  typedef TgEntity    _entity_;
  typedef TgSeparator _separator_;
  typedef TgEnd       _end_;
  typedef TgExcept    _except_;
  
  template<typename T, typename R>
  bool peek( T&, R )
  {
    return true;
  }

  template<typename T, typename RR>
  RR operator()(T& t, RR rr)
  {
    std::cout << "---parse--- " << (const char*)(rr.first.begin()) << std::endl;
    if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
      return rr;

    std::cout << "parse {" << std::endl;
    for (;;)
    {
      std::cout << "[" << std::endl;
      std::cout << "1:" << rr.first << std::endl;

      rr = t.get_aspect().template get<_entity_>()(t, rr);
      std::cout << "2:" << rr.first << std::endl;
      if ( !try_<_except_>(t) )
        break;
      std::cout << "3:" << rr.first << std::endl;

      if ( t.get_aspect().template get<_end_>().peek(t, rr.first) )
        break;
      std::cout << "4:" << rr.first << std::endl;

      rr = t.get_aspect().template get<_separator_>()(t, rr);

      if ( !try_<_except_>(t) )
        break;
      std::cout << "5:" << rr.first << std::endl;

      std::cout << "]" << std::endl;
    }
    std::cout << "} parse" << std::endl;
    return rr;
  }
};

}}}}

#endif
