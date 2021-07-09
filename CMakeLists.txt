cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(stm8emulator)
include(CMakePrintHelpers)
#find_package(Curses REQUIRED)
file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE TESTS "tests/*.c")
include_directories("src/include")

add_executable(test ${SOURCES} ${TESTS})

add_executable(stm8emulator ${SOURCES})
#target_include_directories(stm8emulator PRIVATE ${CURSES_INCLUDE_DIRS})
#target_link_libraries(stm8emulator PRIVATE ${CURSES_LIBRARIES})