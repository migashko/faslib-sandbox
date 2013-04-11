#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_TYPE_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_TYPE_HPP

#include <fas/serialization/json/deser/ad_integer.hpp>
#include <fas/serialization/json/deser/tags.hpp>

namespace fas{ namespace json{ namespace deser{

typedef aspect< type_list_n<
      advice< deser::_integer_, deser::ad_integer>
>::type > aspect_type;


}}}

#endif
