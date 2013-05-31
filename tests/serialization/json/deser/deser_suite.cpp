#include <fas/testing.hpp>
#include <fas/integral.hpp>
#include <fas/serialization/json/deserializer.hpp>
#include <fas/serialization/json/deser/tags.hpp>
#include <fas/serialization/json/except.hpp>
#include <fas/serialization/except/invalid_value.hpp>
#include <fas/serialization/common/deser/ad_sequence.hpp>
#include <fas/serialization/common/deser/ad_compare.hpp>


//#include <fas/serialization/json/meta.hpp>
#include <fas/type_list/type_list_n.hpp>

#include <fas/typemanip/has_typename.hpp>

using namespace fas;
using namespace ::fas::json;
namespace aj = ::fas::json;

struct _condition_;

template<typename N>
struct maximum
{
  typedef _condition_ tag;
  typedef empty_list  targets;
  
  template<typename V>
  bool operator() (const V& v) const
  {
    return v <= N::value;
  }
};

template<typename N>
struct minimum
{
  typedef _condition_ tag;
  typedef empty_list  targets;

  template<typename V>
  bool operator() (const V& v) const
  {
    return v >= N::value;
    
  }
};

template< /*typename TgTarget,*/ typename TgExcept >
struct ad_condition
{
  /*typedef TgTarget _target_;*/
  typedef TgExcept _except_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    std::cout << "ad_condition 1" << std::endl;
    if ( !J()(v) )
      return throw_<_except_>( t, fas::serialization::invalid_value( distance(r) ), r);
    std::cout << "ad_condition 2" << std::endl;
    return r;
    
    //return t.get_aspect().template get<_target_>()( t, J(), v, r);
  }
  
private:
  /*
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
  */
};

template< typename TgParser >
struct ad_peek
{
  typedef TgParser _parser_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V&, R r)
  {
    if ( !t.get_aspect().template get<_parser_>().peek(t, r) )
      t.get_aspect().template get<_status_>() = false;
    return r;
  }
};

struct _target_list_;
//
template<typename TgExcept>
struct ad_target_list
{
  typedef TgExcept _except_;
  
  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    std::cout << "ad_target_list 1" << std::endl;
    typedef typename normalize<typename J::targets>::type targets;
    return _(t, /*J(),*/ v, r, targets() );
  }

private:
  template<typename T, /*typename J,*/ typename V, typename R, typename TargetList>
  R _(T& t, /*J,*/ V& v, R r, TargetList)
  {
    std::cout << "ad_target_list 2" << std::endl;
    typedef typename head<TargetList>::type head_cond;
    typedef typename tail<TargetList>::type tail_conds;

    r = t.get_aspect().template get< typename head_cond::tag >()(t, head_cond(), v, r );

    if ( !try_<_except_>(t) )
      return r;

    // TODO: status

    return _(t, /*J(),*/ v, r, tail_conds() );
  }

  template<typename T, /*typename J,*/ typename V, typename R>
  R _(T& , /*J,*/ V& , R r, empty_list)
  {
    std::cout << "ad_target_list 3" << std::endl;
    return r;
  }
};



struct _peek_number_;
struct _native_integer_;

struct ad_native_integer:
  ::fas::serialization::common::deser::ad_integer/*<aj::parse::_number_>*/
{};

struct ad_peek_number:
  ad_peek< aj::parse::_number_ >
{};

struct _integer_;
struct ad_integer1:
  ::fas::serialization::common::deser::ad_sequence<
    type_list_n<
      _peek_number_,
      _native_integer_,
      _target_list_
    >::type,
    _except_
  >
{
};

template<typename L = empty_list>
struct integer1
{
  typedef L targets;
  typedef _integer_ tag;
};

struct _compare_;

template<typename TgTargetList>
struct ad_range
{
  typedef TgTargetList _targets_;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
    // V - range или pair
    //typedef typename J::target target;

    R beg = r;
    r = t.get_aspect().template get<_parser_>()
        ( t, std::make_pair(r, mrange(r)) );
    v = V(beg.begin(), r.begin());
    return r;
  }
};


///??? нах
template<typename TgParseValue, typename TgTargetList>
struct ad_proxy
{
  typedef TgTargetList _targets_;
  typedef TgParseValue _parse_;

  // венести в аспект
  std::vector<char> buffer;

  template<typename T, typename J, typename V, typename R>
  R operator()(T& t, J, V& v, R r)
  {
     buffer.clear();
     r = t.get_aspect().template get<_parse_>()(t, r, range(proxy_value)).first;
     t.get_aspect().template get<_targets_>()( t, J(), v, range(proxy_value) );
     return r;
  }
};


template<typename L>
struct range
{
  typedef L targets;
  typedef _range_ tag;
}

template<typename L>
struct proxy
{
  typedef L targets;
  typedef _proxy_ tag;
};

struct _quite_;

struct ad_quite:
  ::fas::serialization::common::deser::ad_parse< aj::parse::_quote_ >
{};

struct _string_content_range_;
struct ad_string_content_range: ad_range< aj::parse::_string_content_ > {}

struct _string_range_;
struct ad_string_range:
  ::fas::serialization::common::deser::ad_sequence<
    type_list_n<
      _quite_,
      _string_content_range_,
      _quite_
    >::type,
    _except_
  >
{
};

/*
 *
 proxy<integer>
 * 
 */




struct aspect1: fas::aspect< fas::type_list_n<
  //advice< _postcondition_, ad_condition<has_postcondition, _except_> >,
  advice< _native_integer_, ad_native_integer>,
  advice< _peek_number_, ad_peek_number>,
  advice< _integer_, ad_integer1>,
  advice< _target_list_, ad_target_list<_except_> >,
  advice< _condition_, ad_condition<_except_> >,
  advice< _quite_, ad_quite >,
  advice< _string_content_range_, ad_string_content_range >,
  advice< _string_range_, ad_string_content_range >,
  /*,
  advice< _compare_, 
          ::fas::serialization::common::deser::ad_compare<
            _status_, 
            _except_
          > 
        >*/
>::type > {};
  

UNIT(deser1_unit, "")
{
  using namespace fas::testing;

  aj::deserializer<aspect1> deser;

  
  const char json[] = "12345";
  int result = -1;

  deser( integer1< maximum< fas::int_<12345> > >(), result, fas::range(json) );
  t << equal<expect>(result, 12345) << FAS_TESTING_FILE_LINE;
  /*deser( aj::integer< aj::restriction< aj::maximum< fas::int_<12345> > > >(), result, fas::range(json) );

  

  */
  
  t << nothing();
}


BEGIN_SUITE(deser_suite, "")
  ADD_UNIT(deser1_unit)
END_SUITE(deser_suite)
