//
// Author: Vladimir Migashko <migashko@gmail.com>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#include <fas/except/ad_deferred_except.hpp>
#include <fas/except/ad_except.hpp>
#include <fas/except/ad_except_disable.hpp>
#include <fas/except/throw_t.hpp>
#include <fas/except/try_t.hpp>

#include <fas/testing.hpp>

UNIT(except_disable_unit, "")
{
  using namespace ::fas::testing;

  fas::ad_except_disable except;
  
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;

  except(t);
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;

  except( t, std::domain_error("test ad_except_disable") );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;

  int param = except( t, std::domain_error("test ad_except_disable"), 10 );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect>( param, 10 ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
}

UNIT(deferred_except_unit, "")
{
  using namespace ::fas::testing;
  fas::ad_deferred_except<> except;

  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;
  
  except(t);
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except.exception()->what(), "std::exception" ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;

  except( t, std::exception() );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except.exception()->what(), "std::exception" ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;

  int param = except( t, std::exception(), 10 );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except.exception()->what(), "std::exception" ) << FAS_TESTING_FILE_LINE;
  t << equal<expect>( param, 10 ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;
}

UNIT(deferred_except2_unit, "")
{
  using namespace ::fas::testing;
  fas::ad_deferred_except<std::domain_error> except;

  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;

  except( t, std::domain_error("domain error") );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except.exception()->what(), "domain error" ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;

  int param = except( t, std::domain_error("domain error"), 10 );
  t << is_true<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except.exception()->what(), "domain error" ) << FAS_TESTING_FILE_LINE;
  t << equal<expect>( param, 10 ) << FAS_TESTING_FILE_LINE;
  except.clear(t);
  t << is_false<expect>( except ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, const void*>( except.exception(), (void*)0 ) << FAS_TESTING_FILE_LINE;
}

UNIT(deferred_except3_unit, "")
{
  using namespace ::fas::testing;
  fas::ad_deferred_except<std::domain_error> except1, except2;

  except1( t, std::domain_error("error1") );
  except2( t, std::domain_error("error2") );

  except1 = except2;
  except2 = except1;
  
  t << is_true<assert>( except1 ) << FAS_TESTING_FILE_LINE;
  t << is_true<assert>( except2 ) << FAS_TESTING_FILE_LINE;

  t << equal<expect, std::string>( except1.exception()->what(), "error2" ) << FAS_TESTING_FILE_LINE;
  t << equal<expect, std::string>( except2.exception()->what(), "error2" ) << FAS_TESTING_FILE_LINE;

  try
  {
    except1.raise();
    t << fail("") << FAS_TESTING_FILE_LINE;
  }
  catch(const std::domain_error& e)
  {
     t << equal<expect, std::string>( e.what(), "error2" ) << FAS_TESTING_FILE_LINE;
  }
}


UNIT(except_unit, "")
{
  using namespace ::fas::testing;
  t << nothing();
}



struct _except1_{};
struct _deferred_;
struct _diasbled_;

UNIT(try_throw_unit, "")
{
  using namespace ::fas::testing;
  try
  {
    t.get_aspect().template get<_except1_>()( t, std::logic_error("logic error") );
    t << fail("") << FAS_TESTING_FILE_LINE;
  }
  catch(const std::logic_error& e)
  {
    t << equal<expect, std::string>( e.what(), "logic error" ) << FAS_TESTING_FILE_LINE;
  }
  
  try
  {
    t.get_aspect().template get<_deferred_>()( t, std::domain_error("domain error") );
    t << is_true<expect>(true) << FAS_TESTING_FILE_LINE;
    t.get_aspect().template get<_deferred_>().raise();
    t << fail("") << FAS_TESTING_FILE_LINE;
  }
  catch(const std::domain_error& e)
  {
    t << equal<expect, std::string>( e.what(), "domain error" ) << FAS_TESTING_FILE_LINE;
  }

  t.get_aspect().template get<_diasbled_>()( t, std::exception() );
  t << is_true<assert>( t.get_aspect().template get<_diasbled_>() ) << FAS_TESTING_FILE_LINE;
}

BEGIN_SUITE(except_suite, "")
  ADD_UNIT(except_disable_unit)
  ADD_UNIT(deferred_except_unit)
  ADD_UNIT(deferred_except2_unit)
  ADD_UNIT(deferred_except3_unit)
  ADD_UNIT(except_unit)
  ADD_UNIT(try_throw_unit)

  ADD_ADVICE(_except1_, fas::ad_except )
  ADD_ADVICE(_deferred_, fas::ad_deferred_except<std::domain_error> )
  ADD_ADVICE(_diasbled_, fas::ad_except_disable )
END_SUITE(except_suite)

BEGIN_TEST
  RUN_SUITE(except_suite)
END_TEST
