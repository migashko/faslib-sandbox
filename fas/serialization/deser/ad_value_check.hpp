//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_DESER_AD_VALUE_CHECK_HPP
#define FAS_SERIALIZATION_DESER_AD_VALUE_CHECK_HPP

namespace fas{ namespace serialization{ namespace deser{

template<typename TgStatus>
struct ad_value_check
{
  typedef TgStatus _status_;
  
  template<typename T, typename J, typename V>
  void operator()(T& t, J, V& v)
  {
    if ( !J()(v) )
      t.get_aspect().template get<_status_>() = false;
  }
};

}}}

#endif
