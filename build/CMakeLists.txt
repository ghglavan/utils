cmake_minimum_required ( VERSION 2.6 )
project (Utils)

include_directories("../include")

set(EXECUTABLE_OUTPUT_PATH "../bin")

file(GLOB SOURCES "../tests/*.cpp")
add_executable (string_utils_test ${SOURCES})