#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <stdbool.h>
typedef struct ConsoleFlags {
    char* elf_path;
    bool verbose_output;
} ConsoleFlags;

int init_console();
void close_console();
void print_str(char *str);
ConsoleFlags* handle_cli_args(int argc, char **argv);
void print_console_options(const ConsoleFlags *flags);
#endif