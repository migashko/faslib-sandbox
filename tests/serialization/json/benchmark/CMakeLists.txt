project(benchmark-json)

if(UNIX)
  SET(CMAKE_CXX_FLAGS "-W -Wall -pedantic -frtti -O3 -DNDEBUG -Wno-unused-parameter")
elseif(MSVC)
  SET(CMAKE_CXX_FLAGS "/W3 /wd4503 /wd4307 /EHsc /D_CRT_SECURE_NO_WARNINGS /D_SCL_SECURE_NO_WARNINGS /O2 /DNDEBUG")
endif(UNIX)

INCLUDE (${CMAKE_ROOT}/Modules/CheckLibraryExists.cmake)

find_package(Protobuf)

check_library_exists(rt clock_gettime "time.h" HAVE_RT_LIB)



SET(
  benchmark_src
  benchmark.cpp
  empty.cpp
  sprintf.cpp
  fasjson.cpp
  fasoldjson.cpp
  protobuf.cpp
  jsoncpp/src/json_reader.cpp 
  jsoncpp/src/json_value.cpp 
  jsoncpp/src/json_writer.cpp
)

if (PROTOBUF_FOUND)
include_directories( ${PROTOBUF_INCLUDE_DIR} )
SET(benchmark_src ${benchmark_src} request.pb.cc )
endif (PROTOBUF_FOUND)

add_executable(benchmark ${benchmark_src} )

include_directories( jsoncpp )

if (PROTOBUF_FOUND)
target_link_libraries(benchmark z pthread ${PROTOBUF_LIBRARY})
endif(PROTOBUF_FOUND)

if (HAVE_RT_LIB)
target_link_libraries(benchmark rt)
endif (HAVE_RT_LIB)
