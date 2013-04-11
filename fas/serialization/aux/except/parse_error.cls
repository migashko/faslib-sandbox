class parse_error: public exception
{
public:
  typedef exception::size_type size_type;

  parse_error(size_type tail_of = 0)
    : exception("parse error", tail_of) {}
};
