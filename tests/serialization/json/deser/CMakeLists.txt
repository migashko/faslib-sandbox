add_executable(
  test_deserializer
  ${CMAKE_SOURCE_DIR}/faslib/fas/testing/testing.cpp
  test_deserializer.cpp
  deser_suite.cpp
  object_suite.cpp
  number_suite.cpp
  except_suite.cpp
)
add_test(test_deserializer test_deserializer)



