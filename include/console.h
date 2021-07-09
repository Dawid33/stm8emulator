#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <stdbool.h>
typedef struct ConsoleFlags {
    char* elf_path;
    bool verbose_output;
} ConsoleFlags;

int init_console();
void close_console();
ConsoleFlags* parse_cli_args(int argc, char **argv);
void pretty_print_cli_flags(const ConsoleFlags *flags);
void display_help();
#endif