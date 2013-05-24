#ifndef FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_JSON_DESER_ASPECT_HPP

#include <fas/aop.hpp>

namespace fas{ namespace json{ namespace deser{

struct aspect:
  ::fas::aspect< type_list_n<
    >::type >
{};

}}}

#endif
