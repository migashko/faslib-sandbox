#ifndef FAS_SERIALIZATION_DESER_TARGET_LIST_HPP
#define FAS_SERIALIZATION_DESER_TARGET_LIST_HPP


namespace fas{ namespace serialization{ namespace deser{

  // Условия не выставления _sttatus_ в false
struct target_list
{
  enum {
    least_once,   // Хотябы один 
    strong_all,   // обязательно все
    first_of      // первый из (variant)
  } type;
  
};
  
}}}

#endif
