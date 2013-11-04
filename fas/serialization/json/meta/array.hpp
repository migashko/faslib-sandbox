#ifndef FAS_SERIALIZATION_JSON_META_ARRAY_HPP
#define FAS_SERIALIZATION_JSON_META_ARRAY_HPP

#include <fas/serialization/json/tags.hpp>
#include <fas/type_list/normalize.hpp>
#include <fas/typemanip/if_c.hpp>
#include <fas/functional/member.hpp>
#include <fas/type_list/is_type_list.hpp>
#include <fas/type_list/empty_list.hpp>
#include <fas/type_list/type_list_n.hpp>
#include <fas/range.hpp>

#include "sequence.hpp"

#include <fas/serialization/json/parse/tags.hpp>

// ---
#include <fas/serialization/meta/container.hpp>

namespace fas{ namespace json{

using ::fas::serialization::container;

}}

#include <fas/serialization/json/meta/item_sequence.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/serialization/deser/tags.hpp>

// ---

namespace fas{ namespace json{

// сделать Вторым параметром список целей, пост условий
template< typename Target, typename Alt = ignore_item >
struct array
{
  //typedef container< item_sequence_ex< element< item< Target > > > > target;
  typedef container< item_sequence< Target, Alt > > target;

  typedef _array_ tag;
};

// сделать Вторым параметром список целей, пост условий
template< typename Target, typename Alt = ignore_item >
struct array_ex
{
  //typedef container< item_sequence_ex< element< item< Target > > > > target;
  typedef Target target;
  typedef _array_ tag;
};


}}

#endif
