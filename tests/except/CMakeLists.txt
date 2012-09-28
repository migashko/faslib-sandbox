add_executable(
  test_except
  ${FAS_TESTING_CPP}
  test_except.cpp
)

add_test(test_except test_except)
