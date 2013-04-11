add_executable(
  test_serialization_except
  ${FAS_TESTING_CPP}
  test_serialization_except.cpp
)

add_test(test_serialization_except test_serialization_except)
