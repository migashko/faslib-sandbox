//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

class unexpected_end_fragment
  : public syntax_error
{
public:
  typedef syntax_error::size_type size_type;

  unexpected_end_fragment(size_type tail_of = 0)
    : syntax_error( "unexpected end of fragment", tail_of) {}

  unexpected_end_fragment(const std::string& str, size_type tail_of = 0)
   : syntax_error( str, tail_of ) {}
};

