#ifndef FAS_SYSTEM_SYSTEM_HPP
#define FAS_SYSTEM_SYSTEM_HPP

#include <fas/system/unp.hpp>

namespace fas{ namespace system{

inline int isatty(int fd)
{

#ifdef HAVE__ISATTY_FUNC
  return ::_isatty(fd);
#elif defined(HAVE_ISATTY_FUNC)
  return ::isatty(fd);
#endif
  return 0;
}

inline bool is_atty_stdout()
{
#ifdef _POSIX_VERSION
  return isatty(fileno(stdout));
#elif defined WIN32
  return _isatty( _fileno( stdout ) )!=0;
#else
  return false;
#endif
};

inline bool is_atty_stderr()
{
#ifdef _POSIX_VERSION
  return isatty(fileno(stderr));
#else
#endif
  return false;
};


inline void sleep( int millisec )
{
#ifdef _POSIX_VERSION

#ifdef HAVE_HAS_SELECT_FUNC
  timeval tv={millisec/1000, (millisec%1000)*1000};
  ::select(0, 0, 0, 0, &tv);
#else
  ::sleep( millisec/1000 );
#endif

#elif defined(_WIN32)
  ::Sleep(millisec);
#endif
}


}}

#endif
