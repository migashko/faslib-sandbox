class syntax_error: public exception
{
public:
  typedef exception::size_type size_type;

  syntax_error(size_type tail_of = 0)
    : exception("invalid json", tail_of)  {}

  syntax_error(const std::string& str, size_type tail_of = 0)
   : exception( str, tail_of ) {}
};
