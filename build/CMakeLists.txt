cmake_minimum_required ( VERSION 2.6 )
project (Utils)

include_directories("../include")

set(EXECUTABLE_OUTPUT_PATH "../bin")

file(GLOB STRING_SOURCES "../tests/string_utils_test.cpp")
file(GLOB PTR_SOURCES "../tests/owned_ptr_test.cpp")

add_executable (string_utils_test ${STRING_SOURCES})
add_executable (owned_ptr_test ${PTR_SOURCES})