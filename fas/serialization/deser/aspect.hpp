#ifndef FAS_SERIALIZATION_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_DESER_ASPECT_HPP

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/aop/advice.hpp>
#include <fas/aop/aspect.hpp>
#include <fas/type_list/type_list_n.hpp>
namespace fas{ namespace serialization{ namespace deser{

typedef ::fas::aspect< type_list_n<
  advice<_entity3_, ad_entity3>,
  advice<_entity3_variant_, ad_entity3_variant>
>::type > aspect;

}}}

#endif
