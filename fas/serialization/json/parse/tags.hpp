//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011, 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef FAS_SERIALIZATION_JSON_PARSE_TAGS_HPP
#define FAS_SERIALIZATION_JSON_PARSE_TAGS_HPP

namespace fas{ namespace json{ namespace parse{

struct _number_;
struct _utf8_letter_;
struct _four_hex_digits_;
struct _control_character_;
struct _quote_;
struct _string_content_;
struct _string_;
struct _empty_;

struct _value_;
struct _colon_;
struct _comma_;
struct _left_bracket_;
struct _right_bracket_;
struct _left_brace_;
struct _right_brace_;

struct _array_item_;
struct _item_list_;
struct _array_;

struct _object_field_;
struct _field_list_;
struct _object_;


struct _boolean_;
struct _true_;
struct _false_;
struct _null_;

struct _begin_comment_;
struct _end_comment_;
struct _comment_;
struct _comment_content_;
struct _any_;
struct _white_space_;
struct _end_space_;
struct _space_variant_;
struct _space_;

}}}

#endif
