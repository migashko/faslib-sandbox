#include <fas/testing.hpp>
#include <fas/integral.hpp>
#include <fas/serialization/json/deserializer.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/common/deser/ad_sequence.hpp>


#include <fas/serialization/json/meta.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/typemanip/has_typename.hpp>

using namespace fas;
using namespace ::fas::json;
namespace aj = ::fas::json;

FAS_HAS_TYPENAME(has_precondition,  precondition);
FAS_HAS_TYPENAME(has_postcondition, postcondition);

template<typename N>
struct maximum
{
  typedef void precondition;
  typedef void postcondition;
  
  template<typename V>
  bool operator() (const V& v) const
  {
    return v >= N::value;
  }
};

template<typename N>
struct minimum
{
  typedef void precondition;
  typedef void postcondition;

  template<typename V>
  bool operator() (const V& v) const
  {
    return v <= N::value;
  }
};



struct _postcondition_;

template< template<typename> class Cond_t, typename TgExcept >
struct ad_condition
{
  typedef TgExcept _except_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename select_t<
      typename J::targets,
      has_postcondition
    >::type postconditions;
    
    return r;
  }
  
private:
  template<typename T, typename V, typename R, typename CondList>
  R _(T& t, V& v, R r, CondList)
  {
    typedef typename head<CondList>::type head_cond;
    typedef typename tail<CondList>::type tail_conds;
    
    if ( head_cond()(v) )
      return _(t, v, r, tail_conds() );
    
    return throw_<_except_>( t, invalid_value( distance(r) ), r);
  }

  template<typename T, typename V, typename R>
  R _(T& , V& , R r, empty_list)
  {
    return r;
  }
};

struct _ignore_;
struct _denied_; // Для запрета сериализации или десериализации
template<typename Tg=_denied_, typename L = empty_list>
struct meta
{
  typedef Tg  _tag_;  // Общий тег для сер. и десер. 
  typedef L   target_list;
};

// TODO: общая концепция на мета описании 

// выбока о обработка
struct ad_ternary_proccess
{
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    typedef typename select_t<
      typename J::targets,
      has_postcondition
    >::type preconditions;
 
   typedef typename select_t<
      typename J::targets,
      has_midlecondition
    >::type midleconditions;
  
    typedef typename select_t<
      typename J::targets,
      has_precondition
    >::type postconditions;
    
    // три вызова подряд
    
    return r;
  }
  

};

// Обработка списка целей
struct ad_proccess_list
{
  template<typename T, typename L, typename V, typename R>
  R operator()(T& t, L, V& v, R r)
  {
    typename normalize<L>::type target_list;
    // compile-time цикл
    return r
  }
};


struct _access_;


struct _native_integer_;

struct ad_native_integer:
  ::fas::serialization::common::deser::ad_integer<_access_, _except_>
{};

struct _integer_;
struct ad_integer1:
  ::fas::serialization::common::deser::ad_sequence<
    type_list_n<
      _native_integer_,
      _postcondition_
    >::type,
    _except_
  >
{
};

template<typename L>
struct integer1
{
  typedef L targets;
  typedef _integer_ deserealizer_tag;
};

struct aspect1: fas::aspect< fas::type_list_n<
  advice< _postcondition_, ad_condition<has_postcondition, _except_> >,
  advice< _native_integer_, ad_native_integer>,
  advice< _integer_, ad_integer1>
>::type > {};
  

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  aj::deserializer<aspect1> deser;

  /*
  const char json[] = "12345";
  int result = -1;
  
  deser( aj::integer< aj::restriction< aj::maximum< fas::int_<12345> > > >(), result, fas::range(json) );

  t << equal<expect>(result, 12345) << FAS_TESTING_FILE_LINE;

  */
  
  t << nothing();
}


BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
END_SUITE(deser_suite)
