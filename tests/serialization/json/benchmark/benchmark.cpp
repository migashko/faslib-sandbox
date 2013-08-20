#include <iostream>
#include <typeinfo>
#include "types.hpp"
#include <fas/xtime.hpp>

void empty_serialize(request*, bool);
void empty_serialize(response*, bool);
void empty_deserialize(request*, bool);
void empty_deserialize(response*, bool);

void sprintf_serialize(request*, bool);
void sprintf_serialize(response*, bool);
void sprintf_deserialize(request*, bool);
void sprintf_deserialize(response*, bool);

void fasjson_serialize(request*, bool);
void fasjson_serialize(response*, bool);
void fasjson_deserialize(request*, bool);
void fasjson_deserialize(response*, bool);

void fasoldjson_serialize(request*, bool);
void fasoldjson_serialize(response*, bool);
void fasoldjson_deserialize(request*, bool);
void fasoldjson_deserialize(response*, bool);


void protobuf_init();
void protobuf_serialize(request*, bool);
void protobuf_serialize(response*, bool);
void protobuf_deserialize(request*, bool);
void protobuf_deserialize(response*, bool);

template<typename T, void (*f)(T*,bool), bool init>
class f_test
{
public:
  f_test(std::string desc)
    : _desc(desc)
  {
    _value = T();
  }
  
  void operator()()
  {
    f(&_value, init);
  }
  
  std::string desc() const { return _desc; }
  
private:
  std::string _desc;
  T _value;
};

/*
void empty_serialize(const request&, char*, size_t);
void empty_serialize(const request&, std::string& );
void empty_serialize(const response&, char*, size_t);
void empty_serialize(const response&, std::string&);
void empty_deserialize(const char*, size_t, request&);
void empty_serialize( const std::string&, request&);
void empty_deserialize(const char*, size_t, response&);
void empty_serialize( const std::string&, response&);

typedef void (*request_serialize_cstr)(const request&, char*, size_t);

#define BUFF_SIZE 1024

template<typename T, void (*f)(const T&, char*, size_t)>
class f_serialize_cstr
{
public:
  f_serialize_cstr(std::string desc)
    : _desc(desc)
  {
    _value = T();
  }
  
  void operator()()
  {
    f(_value, _buff, BUFF_SIZE);
  }
  
  std::string desc() const 
  { 
    return _desc;
  }
  
private:
  std::string _desc;
  T _value;
  char _buff[BUFF_SIZE];
};

template<typename T, void (*f)(const T&, std::string&)>
class f_serialize_string
{
public:
  f_serialize_string(std::string desc)
    : _desc(desc)
  {
    _value = T();
  }
  
  void operator()()
  {
    _value = T();
    _buff.clear();
    f(_value, _buff);
  }
  
  std::string desc() const { return _desc; }
  
private:
  std::string _desc;
  T _value;
  std::string _buff;
};

/// ------------------------

template<typename T, void (*f)(const char*, size_t, T&)>
class f_deserialize_cstr
{
public:
  f_serialize_cstr(std::string desc)
    : _desc(desc)
  {
    _value = T();
  }
  
  void operator()()
  {
    _value = T();
    f(_buff, BUFF_SIZE, _value);
  }
  
  std::string desc() const 
  { 
    return _desc;
  }
  
private:
  std::string _desc;
  T _value;
  char _buff[BUFF_SIZE];
};

template<typename T, void (*f)(const std::string&, const T&)>
class f_deserialize_string
{
public:
  f_serialize_string(std::string desc)
    : _desc(desc)
  {
    _value = T();
  }
  
  void operator()()
  {
    _value = T();
    _buff.clear();
    f(_buff, _value);
  }
  
  std::string desc() const { return _desc; }
  
private:
  std::string _desc;
  T _value;
  std::string _buff;
};
*/
template<typename F>
fas::nanospan test_one( F& f, size_t count  )
{
  fas::nanospan start = fas::nanotime();
  for (size_t i = 0 ; i < count; ++i)
    f();
  fas::nanospan finish = fas::nanotime();
  return finish - start;
}

template<typename F>
fas::nanospan test( F& f, size_t count, size_t probe  )
{
  fas::nanospan best = test_one( f, count);
  for (size_t i = 0 ; i < probe; ++i)
  {
    fas::nanospan current = test_one( f, count);
    if ( current < best )
      best = current;
  }
  return best;
}

template<typename F>
void show_test( F f, size_t count, bool show )
{
  fas::nanospan span = test( f, count, 100);
  if ( show ) 
  {
    std::cout << f.desc() << std::endl;
    std::cout << "time: " << span*100 << " sec" << std::endl;
    std::cout << "rate: " << fas::rate(span)*count << " persec" << std::endl;
  }
  else
  {
    std::cout << f.desc() << "\t" << span << "\t" << fas::rate(span)*count  << std::endl;
  }
}


int main()
{
  size_t count = 1000;
  bool show = false;
  protobuf_init();  
  std::cout << "#######################" << std::endl;
  std::cout << "#### serialization ####" << std::endl;
  std::cout << "====    request    ====" << std::endl;
  show_test( f_test<request, empty_serialize, false>("empty_serialize"), count, show);
  show_test( f_test<request, sprintf_serialize, false>("sprintf_serialize"), count, show);
  show_test( f_test<request, fasjson_serialize, false>("fasjson_serialize"), count, show);
  show_test( f_test<request, protobuf_serialize, false>("protobuf_serialize"), count, show);
  std::cout << "====    response    ====" << std::endl;
  show_test( f_test<response, empty_serialize, false>("empty_serialize"), count, show);
  show_test( f_test<response, sprintf_serialize, false>("sprintf_serialize"), count, show);
  show_test( f_test<response, fasjson_serialize, false>("fasjson_serialize"), count, show);
  show_test( f_test<response, protobuf_serialize, false>("protobuf_serialize"), count, show);

  std::cout << "#########################" << std::endl;
  std::cout << "#### deserialization ####" << std::endl;
  std::cout << "====    request    ====" << std::endl;
  show_test( f_test<request, empty_deserialize, false>("empty_deserialize"), count, show);
  show_test( f_test<request, sprintf_deserialize, false>("sprintf_deserialize"), count, show);
  show_test( f_test<request, fasjson_deserialize, false>("fasjson_deserialize"), count, show);
  show_test( f_test<request, fasoldjson_deserialize, false>("fasoldjson_deserialize"), count, show);
  show_test( f_test<request, protobuf_deserialize, false>("protobuf_deserialize"), count, show);
  std::cout << "====    response    ====" << std::endl;
  show_test( f_test<response, empty_deserialize, false>("empty_deserialize"), count, show);
  
  show_test( f_test<response, sprintf_deserialize, false>("sprintf_deserialize"), count, show);
  
  show_test( f_test<response, fasjson_deserialize, false>("fasjson_deserialize"), count, show);
  show_test( f_test<response, protobuf_deserialize, false>("protobuf_deserialize"), count, show);
  /*
  std::cout << "#######################" << std::endl;
  std::cout << "#### serialization ####" << std::endl;
  std::cout << "====    request    ====" << std::endl;
  std::cout << "----    char*      ----" << std::endl;
  show_test( f_serialize_cstr<request, empty_serialize>("empty_serialize"), count, show);
  std::cout << "----  std::string  ----" << std::endl;
  show_test( f_serialize_string<request, empty_serialize>("empty_serialize"), count, show);
  std::cout << "====    response    ====" << std::endl;
  std::cout << "----    char*      ----" << std::endl;
  show_test( f_serialize_cstr<response, empty_serialize>("empty_serialize"), count, show);
  std::cout << "----  std::string  ----" << std::endl;
  show_test( f_serialize_string<response, empty_serialize>("empty_serialize"), count, show);
  */
}
