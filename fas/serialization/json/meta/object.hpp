#ifndef FAS_SERIALIZATION_JSON_META_OBJECT_HPP
#define FAS_SERIALIZATION_JSON_META_OBJECT_HPP

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

#include <fas/serialization/json/meta/acc.hpp>
#include <fas/serialization/json/meta/field.hpp>
#include <fas/serialization/json/meta/field_list.hpp>
#include <fas/serialization/json/meta/element.hpp>
#include <fas/serialization/json/meta/parse.hpp>
#include <fas/serialization/json/meta/ignore.hpp>
#include <fas/serialization/json/meta/string_content.hpp>
#include <fas/serialization/json/meta/string.hpp>
#include <fas/serialization/json/meta/string_ex.hpp>
#include <fas/serialization/json/meta/equal_content.hpp>
#include <fas/serialization/json/meta/equal_string.hpp>
#include <fas/serialization/json/meta/base.hpp>
#include <fas/serialization/json/meta/item.hpp>
#include <fas/serialization/json/meta/item_sequence.hpp>
#include <fas/serialization/json/meta/array.hpp>



#include <fas/serialization/tags.hpp>
#include <fas/serialization/deser/tags.hpp>

namespace fas{ namespace json{

template< typename FieldList = empty_list, typename Alt = ignore_field >
struct object
{
  typedef field_list<FieldList, Alt> target;
  typedef _object_ tag;
};

template< typename Target>
struct object_ex
{
  typedef Target target;
  typedef _object_ tag;
};

}}

#endif
