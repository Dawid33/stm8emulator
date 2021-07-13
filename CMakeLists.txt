cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set($ENV{CTEST_OUTPUT_ON_FAILURE} 1)

project(stm8-emulator)
include(CMakePrintHelpers)

# This can be done differently, but it makes the
# cmake files easier to edit.
# All targets need this directory.
include_directories("include")

add_library(stm8_lib
"src/run.c"
"src/io.c"
"src/console.c"
"src/device.c"
)

# All targets needs to link this
link_libraries(stm8_lib)
add_executable(stm8emulator "src/main.c")
enable_testing()
include("tests/build_tests.cmake")