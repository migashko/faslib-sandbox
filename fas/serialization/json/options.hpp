#ifndef FAS_SERIALIZATION_JSON_OPTIONS_HPP
#define FAS_SERIALIZATION_JSON_OPTIONS_HPP

#include <fas/serialization/json/parse/space/aspect_cp.hpp>
#include <fas/serialization/except/aspect.hpp>

namespace fas{ namespace json{

struct all_space_copy: parse::space::aspect_space_cp {};
struct white_space_copy: parse::space::aspect_white_space_cp {};
struct comment_copy: parse::space::aspect_comment_cp {};

// TODO: move to /fas/serialization
struct disable_except: ::fas::serialization::except::aspect_disable {};
struct deferred_except: ::fas::serialization::except::aspect_deferred {};

}}

#endif
