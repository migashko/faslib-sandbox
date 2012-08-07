#ifndef FAS_SERIALIZATION_JSON_PARSER_AD_STRING_HPP
#define FAS_SERIALIZATION_JSON_PARSER_AD_STRING_HPP

#include <fas/serialization/common/parser/ad_char_t.hpp>
#include <fas/serialization/common/parser/ad_enclosed_t.hpp>

#include <fas/serialization/json/except/try_throw.hpp>
#include <fas/serialization/json/except/unexpected_end_fragment.hpp>
#include <fas/serialization/json/except/invalid_json_string.hpp>
#include <fas/serialization/json/except/expected_of.hpp>
#include <fas/serialization/json/except/out_of_range.hpp>
#include <fas/serialization/json/parser/tags.hpp>
#include <fas/range/distance.hpp>

namespace fas{ namespace json{ namespace parse{

struct ad_string
{

  template<typename T, typename R>
  bool check( T&, R r) { return r && *r=='"' ; }

  template<typename T, typename R>
  R operator()(T& t, R r)
  {
    r = this->parse(t, r);
    return r;
  }

  template<typename T, typename R, typename RD>
  std::pair<R, RD> operator()(T& t, R r, RD rd)
  {
    return this->copy(t, r, rd);
  }

private:
  
  template<typename T, typename R>
  R parse_hex(T& t, R r)
  {
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    for (register int i=0; i < 4; ++i, ++r)
    {
      if (!r)
        return throw_( t, unexpected_end_fragment(), r);

      if ( ( *r < '0' || *r>'9')
             && (*r < 'A' || *r>'F')
             && (*r < 'a' || *r>'f') )
               return throw_( t, invalid_json_string( distance(r) ), r);
    }

    return r;
  }

  template<typename T, typename R, typename RD>
  R copy_hex(T& t, R r, RD& rd)
  {
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    for (register int i=0; i < 4 ; ++i, ++r, ++rd)
    {
      if (!r)
        return throw_( t, unexpected_end_fragment(), r);
      
      if (!rd)
        return throw_( t, out_of_range(), r);

      if ( ( *r < '0' || *r > '9')
             && (*r < 'A' || *r > 'F')
             && (*r < 'a' || *r > 'f') )
               return throw_( t, invalid_json_string( distance(r) ), r);
               
      *rd = *r;
    }

    return r;
  }

  template<typename T, typename R>
  R parse_symbol(T& t, R r)
  {
    /*
    0x00000000 — 0x0000007F: 0xxxxxxx
    0x00000080 — 0x000007FF: 110xxxxx 10xxxxxx
    0x00000800 — 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
    0x00010000 — 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);
      

    if ( (*r & 128)==0 )
      return ++r;
    if ( (*r & 224)==192 && ++r && (*r & 192)==128 )
      return ++r;
    if ( (*r & 240)==224 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128 )
      return ++r;
    if ( (*r & 248)==240 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128)
      return ++r;

    if ( r )
      return throw_( t, invalid_json_string( distance(r) ), r);

    return throw_( t, unexpected_end_fragment(), r);
    
  }

  template<typename T, typename R, typename RD>
  R copy_symbol(T& t, R r, RD& rd)
  {
    /*
    0x00000000 — 0x0000007F: 0xxxxxxx
    0x00000080 — 0x000007FF: 110xxxxx 10xxxxxx
    0x00000800 — 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
    0x00010000 — 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    if ( (*r & 128)==0 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      return r;
    }

    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r && (*r & 192)==128 )
      {
        if (!rd)
          return throw_( t, out_of_range(), r);
        
        *(rd++) = *(r++);
        
        return r;
      }
    }
    
    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r && (*r & 192)==128 )
      {
        *(rd++) = *(r++);
        
        if ( r && (*r & 192)==128 )
        {
          if (!rd)
            return throw_( t, out_of_range(), r);
          
          *(rd++) = *(r++);
          
          return r;
        }
      }
    }

    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r &&  (*r & 192)==128 )
      {
        if (!rd)
          return throw_( t, out_of_range(), r);
        
        *(rd++) = *(r++);
        
        if ( r &&  (*r & 192)==128 )
        {
          if (!rd)
            return throw_( t, out_of_range(), r);
          
          *(rd++) = *(r++);
          
          if ( r && (*r & 192)==128 )
          {
            if (!rd)
              return throw_( t, out_of_range(), r);
            *(rd++) = *(r++);
            return r;
          }
        }
      }
    }

    if ( r )
      return throw_( t, invalid_json_string( distance(r) ), r);
    
    return throw_( t, unexpected_end_fragment(), r);
  }

  template<typename T, typename R>
  R parse(T& t, R r)
  {
    /*std::cout << "ad_string parse " << *r << std::endl;
    R rx = r;
    std::cout << std::endl;
    for ( ;rx; ++rx)
      std::cout << *rx;
    std::cout << std::endl;
    std::cout << std::endl;
    */
    
    //std::cout << "ad_string 1.1 " << *r << std::endl;
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    //std::cout << "ad_string 1.2 " << *r << std::endl;
    if (*r!='"') 
      return throw_( t, expected_of("\"",  distance(r) ), r);

    //std::cout << "ad_string 1.3 " << bool(r) << std::endl;
    //std::cout << "ad_string 1.3 " << *r << distance(r) << std::endl;
    r++;
    //std::cout << "ad_string 1.3 " << bool(r) << std::endl;
    //std::cout << "ad_string 1.3 " << *r << distance(r) << std::endl;
    for ( /*++r*/; r && *r!='"'; )
    {
      //std::cout << "ad_string 1.3.1" << std::endl;
      if (*r=='\\')
      {
        if ( !(++r) )
          return throw_( t, unexpected_end_fragment(), r);

        if ( *r != '"' && *r != '\\' && *r != '/'
             && *r != 't' && *r != 'b' && *r != 'n'
             && *r != 'r' && *r != 'f' && *r != 'u'
           )
            return throw_( t, invalid_json_string( distance(r) ), r);
             

        if ( *(r++) == 'u' )
        {
          r = this->parse_hex(t, r);
          if ( !try_(t) )
            return r;
        }
      }
      else
      {
        r = this->parse_symbol(t, r);
        if ( !try_(t) )
          return r;
      }
    }

    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    if (*r!='"')
      return throw_( t, expected_of("\"", distance(r) ), r);

    return ++r;;
  }

  template<typename T, typename R, typename RD>
  std::pair<R, RD> copy(T& t, R r, RD& rd)
  {
    if (!r)
      return throw_( t, unexpected_end_fragment(), r, rd);

    if (*r!='"') 
      return throw_( t, expected_of("\"",  distance(r) ), r, rd);

    if (!rd)
      return throw_( t, out_of_range(), r, rd);
    
    *(rd++) = *(r++);
    
    for ( ; r && *r!='"'; )
    {
      if (*r=='\\')
      {
        if (!rd) 
          return throw_( t, out_of_range(), r, rd);

        *(rd++) = *(r++);
        
        if ( !r ) 
          return throw_( t, unexpected_end_fragment(), r, rd);

        if ( *r != '"' && *r != '\\' && *r != '/'
             && *r != 't' && *r != 'b' && *r != 'n'
             && *r != 'r' && *r != 'f' && *r != 'u'
           )
            return throw_( t, invalid_json_string( distance(r) ), r, rd);

        if (!rd) 
          return throw_( t, out_of_range(), r, rd);

        *(rd++) = *r;

        if ( *(r++) == 'u' )
        {
          r = this->copy_hex(t, r, rd);
          if ( !try_(t) )
            return std::make_pair(r, rd);
        }

      }
      else
      {
        r = this->copy_symbol(t, r, rd);
        if ( !try_(t) )
          return std::make_pair(r, rd);
      }
    }

    if (!r)
      return throw_( t, unexpected_end_fragment(), r, rd);

    if (*r!='"')
      return throw_( t, expected_of("\"", distance(r) ), r, rd);

    if (!rd) 
      return throw_( t, out_of_range(), r, rd);
    
    *(rd++) = *(r++);
    
    return std::make_pair(r, rd);
  }
};

template<typename TgUhex, typename TgExcept>
struct ad_json_uhex_t
{
};

/*
template<typename TgUhex, typename TgExcept>
struct ad_json_escape_t
{
  typedef TgUhex   _json_uhex_;
  typedef TgExcept _except_;
  
  template<typename R>
  bool check(R r)
  {
    return *r=='\\';
  }

  template<typename T, typename R>
  R operator()( T& t, R r)
  {
    if ( !r || *r!='\\')
      return r;

    if (!(++r))
      return throw_t<_except_>(t, unexpected_end_fragment( distance(r) ), r );

    switch (*r)
    {
      case '"' :
      case '\\':
      case '/' : 
      case 't' : 
      case 'b' : 
      case 'r' : 
      case 'n' : 
      case 'f' : ++r; break;
      case 'u' : r = t.get_aspect().template get<_json_uhex_>()(t,  ++r); break;
      default:
        return throw_t<_except_>(t, invalid_string( distance(r_in) ), r_in );
    } // case

    return r;
  }

  template<typename T, typename R, typename RO>
  std::pair<R, RO> copy(T& t, R r, RO& ro)
  {
    std::pair<R, RO> rr(r, ro);
    
    if ( !rr.first || *rr.first!='\\')
      return rr;

    if (!(++rr.first))
      return throw_t<_except_>(t, unexpected_end_fragment( distance(rr.first) ), rr.first, rr.second );

    *(rr.second)++ = *rr.first;

    switch (*rr.first)
    {
      case '"' :
      case '\\':
      case '/' :
      case 't' :
      case 'b' :
      case 'r' :
      case 'n' :
      case 'f' : *(rr.second++) = *(rr.first++); break;
      case 'u' :
        *(rr.second++) = *(rr.first++);
        r = t.get_aspect().template get<_json_uhex_>()(t, rr.first, rr.second);
        break;
      default:
        return throw_t<_except_>(t, invalid_string( distance(r.first) ), r.first, r.second );
    } // case

    return rr;
  }
};
*/

struct ad_unquoted_string
{
  template<typename T, typename R>
  bool check( T&, R r) { return true; }

  template<typename T, typename R>
  R operator()(T& t, R r)
  {
    return this->parse(t, r);
  }

  template<typename T, typename R, typename RD>
  std::pair<R, RD> operator()(T& t, R r, RD rd)
  {
    return this->copy(t, r, rd);
  }

private:
  
  template<typename T, typename R>
  R parse_hex(T& t, R r)
  {
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    for (register int i=0; i < 4; ++i, ++r)
    {
      if (!r)
        return throw_( t, unexpected_end_fragment(), r);

      if ( ( *r < '0' || *r>'9')
             && (*r < 'A' || *r>'F')
             && (*r < 'a' || *r>'f') )
               return throw_( t, invalid_json_string( distance(r) ), r);
    }
    return r;
  }

  template<typename T, typename R, typename RD>
  R copy_hex(T& t, R r, RD& rd)
  {
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    for (register int i=0; i < 4 ; ++i, ++r, ++rd)
    {
      if (!r)
        return throw_( t, unexpected_end_fragment(), r);
      
      if (!rd)
        return throw_( t, out_of_range(), r);

      if ( ( *r < '0' || *r > '9')
             && (*r < 'A' || *r > 'F')
             && (*r < 'a' || *r > 'f') )
               return throw_( t, invalid_json_string( distance(r) ), r);
               
      *rd = *r;
    }

    return r;
  }

  template<typename T, typename R>
  R parse_symbol(T& t, R r)
  {
    /*
    0x00000000 — 0x0000007F: 0xxxxxxx
    0x00000080 — 0x000007FF: 110xxxxx 10xxxxxx
    0x00000800 — 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
    0x00010000 — 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);
      

    if ( (*r & 128)==0 )
      return ++r;
    if ( (*r & 224)==192 && ++r && (*r & 192)==128 )
      return ++r;
    if ( (*r & 240)==224 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128 )
      return ++r;
    if ( (*r & 248)==240 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128 && ++r && (*r & 192)==128)
      return ++r;

    if ( r )
      return throw_( t, invalid_json_string( distance(r) ), r);

    return throw_( t, unexpected_end_fragment(), r);
  }

  template<typename T, typename R, typename RD>
  R copy_symbol(T& t, R r, RD& rd)
  {
    /*
    0x00000000 — 0x0000007F: 0xxxxxxx
    0x00000080 — 0x000007FF: 110xxxxx 10xxxxxx
    0x00000800 — 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
    0x00010000 — 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    */
    if (!r)
      return throw_( t, unexpected_end_fragment(), r);

    if ( (*r & 128)==0 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      return r;
    }

    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r && (*r & 192)==128 )
      {
        if (!rd)
          return throw_( t, out_of_range(), r);
        
        *(rd++) = *(r++);
        
        return r;
      }
    }
    
    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r && (*r & 192)==128 )
      {
        *(rd++) = *(r++);
        
        if ( r && (*r & 192)==128 )
        {
          if (!rd)
            return throw_( t, out_of_range(), r);
          
          *(rd++) = *(r++);
          
          return r;
        }
      }
    }

    if ( (*r & 224)==192 )
    {
      if (!rd)
        return throw_( t, out_of_range(), r);
      
      *(rd++) = *(r++);
      
      if ( r &&  (*r & 192)==128 )
      {
        if (!rd)
          return throw_( t, out_of_range(), r);
        
        *(rd++) = *(r++);
        
        if ( r &&  (*r & 192)==128 )
        {
          if (!rd)
            return throw_( t, out_of_range(), r);
          
          *(rd++) = *(r++);
          
          if ( r && (*r & 192)==128 )
          {
            if (!rd)
              return throw_( t, out_of_range(), r);
            *(rd++) = *(r++);
            return r;
          }
        }
      }
    }

    if ( r )
      return throw_( t, invalid_json_string( distance(r) ), r);
    
    return throw_( t, unexpected_end_fragment(), r);
  }

  template<typename T, typename R>
  R parse(T& t, R r)
  {
    for ( ; r && *r!='"'; )
    {
      if (*r=='\\')
      {
        if ( !(++r) )
          return throw_( t, unexpected_end_fragment(), r);

        if ( *r != '"' && *r != '\\' && *r != '/'
             && *r != 't' && *r != 'b' && *r != 'n'
             && *r != 'r' && *r != 'f' && *r != 'u'
           )
            return throw_( t, invalid_json_string( distance(r) ), r);
             

        if ( *(r++) == 'u' )
        {
          r = this->parse_hex(t, r);
          if ( !try_(t) )
            return r;
        }
      }
      else
      {
        r = this->parse_symbol(t, r);
        if ( !try_(t) )
          return r;
      }
    }

    return r;
  }

  template<typename T, typename R, typename RD>
  std::pair<R, RD> copy(T& t, R r, RD& rd)
  {
    for ( ; r && *r!='"'; )
    {
      if (*r=='\\')
      {
        if (!rd) 
          return throw_( t, out_of_range(), r, rd);

        *(rd++) = *(r++);
        
        if ( !r ) 
          return throw_( t, unexpected_end_fragment(), r, rd);

        if ( *r != '"' && *r != '\\' && *r != '/'
             && *r != 't' && *r != 'b' && *r != 'n'
             && *r != 'r' && *r != 'f' && *r != 'u'
           )
            return throw_( t, invalid_json_string( distance(r) ), r, rd);

        if (!rd) 
          return throw_( t, out_of_range(), r, rd);

        *(rd++) = *r;

        if ( *(r++) == 'u' )
        {
          r = this->copy_hex(t, r, rd);
          if ( !try_(t) )
            return std::make_pair(r, rd);
        }

      }
      else
      {
        r = this->copy_symbol(t, r, rd);
        if ( !try_(t) )
          return std::make_pair(r, rd);
      }
    }
    return std::make_pair(r, rd);
  }
};

struct ad_quote: 
  ::fas::serialization::parse::ad_char_t<char, '"', _except_>
{};

struct ad_string1:
  ::fas::serialization::parse::ad_enclosed_t<_quote_, _unquoted_string_, _quote_, _except_>
{};

/*struct aspect_string: aspect< type_list_n<
  advice<_quote_, ad_quote>,
  advice<_unquoted_string_, ad_unquoted_string>,
  advice<_string_, ad_string1>
>::type
> {};
*/
typedef advice<_string_, ad_string> aspect_string;

}}}

#endif
