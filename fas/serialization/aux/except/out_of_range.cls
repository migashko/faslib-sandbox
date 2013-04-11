class out_of_range
  : public exception
{
public:
  typedef exception::size_type size_type;

  out_of_range(size_type tail_of = 0)
    : exception( "out of range", tail_of) {}

  out_of_range(const std::string& str, size_type tail_of = 0)
   : exception( std::string("out of range: ") + str, tail_of ) {}
};
