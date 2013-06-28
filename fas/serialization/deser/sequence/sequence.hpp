#ifndef FAS_SERIALIZATION_DESER_SEQUENCE_HPP
#define FAS_SERIALIZATION_DESER_SEQUENCE_HPP


namespace fas{ namespace serialization{ namespace deser{

// Условия не выставления _sttatus_ в false
// ОТрабатывает как target_list
// Если не получилось, то target
struct sequence
{
  enum {
    smart, // для объектов
    each,  // для каждого (массивы)
    brute, // пытается десериализовать каждый элемент 
    repeat // Походит по списку и возвращается к началу 
  } type;
  
};

template<sequence::type ST, typename TgAlt, typename TgParseEnd>
struct ad_sequence;

  
}}}

#endif
