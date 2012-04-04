// Author: Vladimir Migashko <migashko@faslib.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_TYPEMANIP_REMOVE_CONST_HPP
#define FAS_TYPEMANIP_REMOVE_CONST_HPP


namespace fas{

template<typename T>
struct remove_const
{
  typedef T type;
};

template<typename T>
struct remove_const<const T>
{
  typedef T type;
};

/*
template<typename T>
struct is_const: false_ { typedef false_ type; };

template<typename T>
struct is_const<const T>: true_ { typedef true_ type; };;
*/


}

#endif
