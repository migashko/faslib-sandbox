//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_RANGE_MOKE_RANGE_HPP
#define FAS_RANGE_MOKE_RANGE_HPP

#include <fas/range/range_category.hpp>
#include <iterator>
#include <cassert>


namespace fas {


template<typename T>
class moke_range
{
public:
  typedef random_access_range_tag range_category;

  typedef T iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef moke_range<reverse_iterator> reverse_range;
  typedef typename std::iterator_traits<T>::iterator_category iterator_category;
  typedef typename std::iterator_traits<T>::value_type        value_type;
  typedef typename std::iterator_traits<T>::difference_type   difference_type;
  typedef typename std::iterator_traits<T>::pointer           pointer;
  typedef typename std::iterator_traits<T>::value_type        reference;

  struct moke
  {
    moke(){}
    moke(const moke&){}
    moke(const value_type&){}
    moke& operator=(const value_type&) {return *this;}
  };

  moke_range() {}

  moke_range(T b, T e) {}

  operator bool () const { return true; }

  moke operator*() const { return _moke; }

  moke operator ->() const  { return _moke;}

  iterator begin() const { return iterator(); }

  iterator end() const { return iterator(); }

  reverse_iterator rbegin() const { return reverse_iterator(iterator()); }

  reverse_iterator rend() const { return reverse_iterator(iterator()); }

  reverse_range reverse() const { return reverse_range( rbegin(), rend() ); }

  difference_type distance() const { return 0; }

  void advance(difference_type) { }

  void increase(difference_type, difference_type) {}

  void decrease(difference_type cbeg, difference_type cend) { }

  moke_range<T>& operator++() { return *this; }

  moke_range<T> operator++(int) { return moke_range<T>(); }

  moke_range<T>& operator--() { return *this; }

  moke_range<T> operator--(int) { return moke_range<T>(); }

  bool operator == (const moke_range<T>&) const { return true; }

  bool operator != (const moke_range<T>&) const { return false; }

  bool operator < (const moke_range<T>&) const  { return false; }

  bool operator > (const moke_range<T>& ) const { return false; }

  bool operator <= (const moke_range<T>& r ) const { return !this->operator >( r ); }

  bool operator >= (const moke_range<T>& r ) const {  return !this->operator < ( r ); }

  moke_range<T>& operator += (difference_type ) { return *this; }

  moke_range<T>& operator -= (difference_type n ) { return *this; }

  moke& operator[] ( difference_type ) const { return _moke; }

private:
  moke _moke;

};


template<typename T, typename Dist>
inline moke_range<T> operator +
  (
    moke_range<T> r,
    Dist n
  )
{
  return r+=n;
}

template<typename T, typename Dist>
inline moke_range<T> operator +
  (
    Dist n,
    moke_range<T> r
  )
{
  return r+= n;
}

template<typename T, typename Dist>
inline moke_range<T> operator -
  (
    moke_range<T> r,
    Dist n
  )
{
  return r-= n;
}

template<typename T, typename Dist>
inline moke_range<T> operator -
  (
    Dist n,
    moke_range<T> r
  )
{
  return r -= n;
}

template<typename T>
inline typename moke_range<T>::difference_type operator -
  (
    moke_range<T> r1,
    moke_range<T> r2
  )
{
  return 0;
}

}

#endif
