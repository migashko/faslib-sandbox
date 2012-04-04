#ifndef FAS_range_INPUT_RANGE_HPP
#define FAS_range_INPUT_RANGE_HPP

#include <fas/range/range_category.hpp>
#include <iterator>
#include <cassert>

namespace fas {

template<typename T, typename ValueType>
class input_range
{
public:
  typedef input_range_tag range_category;
  
  typedef T iterator;

  typedef ValueType value_type;
  typedef typename std::iterator_traits<T>::iterator_category iterator_category;
  typedef typename std::iterator_traits<T>::difference_type   difference_type;
  typedef typename std::iterator_traits<T>::pointer           pointer;
  typedef typename std::iterator_traits<T>::reference         reference;

  class proxy {
    ValueType keep_;
  public:
    proxy (ValueType c) : keep_(c){ }
    ValueType operator*() {return keep_;}
  };
  
  input_range()
    : b(), e()
  {};

  explicit input_range(T b, T e)
    : b(b), e(e)
  {};

  operator bool () const { return b!=e; }

  value_type operator*() const { return *b; }

  // pointer operator ->() { return &(*b);}

  /*const*/ pointer operator ->() const  { return &(*b);}

  /*const T*/ iterator begin() const { return b; }
  
  /*const T*/ iterator end() const { return e; }

  input_range<T, ValueType>& operator++() 
  {
    // assert(b!=e);
    ++b; 
    return *this; 
  }

  proxy operator++(int) 
  {
    proxy p( *b );
    // assert(b!=e);
    //input_range<T, ValueType> ans = *this;   
    b++; 
    return p; 
  }

  difference_type distance() const { return std::distance(b, e); }
  
  input_range<T, ValueType>& advance(difference_type s)  { std::advance(b, s); return *this;}
  
  bool operator == (const input_range<T, ValueType>& r ) const { return b == r.b && e==r.e;  }

  bool operator != (const input_range<T, ValueType>& r ) const { return !(*this == r); }

protected:
  T b;
  T e;
};

}

#endif
