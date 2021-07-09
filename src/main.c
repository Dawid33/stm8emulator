#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "console.h"
#include "io.h"

void exit_main() {
    exit(0);
}

int main (int argc, char **argv) {
    if (atexit(exit_main) != 0) return -1; // Run function at program exit.
    
    ConsoleFlags* flags = handle_cli_args(argc, argv);
    if (flags == NULL) return -1;
    print_console_options(flags);
    char *result;
    if ((result = read_file(flags->elf_path)) == NULL) return -1;
    printf("%s", result);

    free(flags);
    return 0;
}