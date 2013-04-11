//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2012, 2013
//
// Copyright: See COPYING file that comes with this distribution
//

class expected_of
  : public syntax_error
{
public:
  typedef syntax_error::size_type size_type;
  expected_of(const std::string& str, size_type tail_of = 0)
    : syntax_error( std::string("expected of '") + str + std::string("'"), tail_of) {}
  expected_of(char ch, size_type tail_of = 0)
    : syntax_error( std::string("expected of '") + ch + std::string("'"), tail_of) {}
};
