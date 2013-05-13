add_executable(
  test_parser
  ${CMAKE_SOURCE_DIR}/faslib/fas/testing/testing.cpp
  test_parser.cpp
  number_suite.cpp
  string_suite.cpp
  except_suite.cpp
  space_suite.cpp
  parser_suite.cpp
)
add_test(test_parser test_parser)



