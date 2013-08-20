#ifndef FAS_SERIALIZATION_DESER_ASPECT_HPP
#define FAS_SERIALIZATION_DESER_ASPECT_HPP

#include <fas/serialization/deser/ad_parser.hpp>

#include <fas/serialization/deser/ad_entity.hpp>
#include <fas/serialization/deser/ad_entity_piece.hpp>
#include <fas/serialization/deser/ad_sequence_each.hpp>
#include <fas/serialization/deser/ad_sequence_smart.hpp>
#include <fas/serialization/tags.hpp>
#include <fas/serialization/deser/tags.hpp>

#include <fas/aop/advice.hpp>
#include <fas/aop/aspect.hpp>
#include <fas/type_list/type_list_n.hpp>

namespace fas{ namespace serialization{ namespace deser{

typedef ::fas::aspect< type_list_n<
  advice< _parser_, ad_parser>,
  value_advice< _status_, bool>
>::type > basic_aspect;

typedef ::fas::aspect< type_list_n<
  advice<_entity_, ad_entity>,
  advice<_entity_piece_, ad_entity_piece>,
  advice<_sequence_each_, ad_sequence_each>,
  advice<_sequence_smart_, ad_sequence_smart>,
  basic_aspect
>::type > aspect;

}}}

#endif
