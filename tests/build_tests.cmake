# Put all the executables in their own folder
if(NOT EXISTS "tests")
    file(MAKE_DIRECTORY "tests")
endif()

# Make all the following execuables put their output in that folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "tests")

include_directories("tests/include")

# Make testing elf's availabe for tests
#file(COPY "elf" DESTINATION "./")
# Tests file used by some tests
file(COPY "tests/test_files" DESTINATION "./")

add_library(tests_lib
    "tests/test.c"
)

link_libraries(tests_lib)

# UNIT TESTS
add_executable(handle_cli_args_test "tests/parse_cli_args_test.c")
add_executable(parse_elf_file_test "tests/parse_elf_file_test.c")
add_executable(read_file_test "tests/read_file_test.c")

add_test(
    NAME read_file
    COMMAND $<TARGET_FILE:read_file_test>
)
add_test(
    NAME handle_cli_args
    COMMAND $<TARGET_FILE:handle_cli_args_test>
)
add_test(
    NAME parse_elf_file
    COMMAND $<TARGET_FILE:parse_elf_file_test>
)

# Example test running a command
# add_test(
#     NAME test_command
#     COMMAND $<TARGET_FILE:stm8emulator> -product null -cpu stm8s207r8 -elf elf/dhrystone.elf
# )