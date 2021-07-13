#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "run.h"
#include "console.h"
#include "device.h"
#include "io.h"

// Free these variables if they are not null on exit.
ConsoleFlags *flags = NULL;
// ElfFile *elf_file = NULL;
void exit_main() {
    if (flags) free(flags);
    // if(elf_file) free(elf_file);
}

int run(int argc, char **argv) {
    if (atexit(exit_main) != 0) return -1;  // Run function at program exit.

    flags = parse_cli_args(argc, argv);
    if (flags == NULL) {
        return 0;
    }
    pretty_print_cli_flags(flags);

    // Load and parse the ELF file.
    char *raw_file = NULL;
    Program *program = NULL;
    if ((raw_file = read_file(flags->elf_path)) == NULL) {
        if ((program = parse_hex_file(raw_file)) == NULL) {
            printf("Cannot parse hex file.\n");
            free(raw_file);
            return -1;
        } else {
            free(raw_file);
        }
        printf("Cannot read hex file.\n");
        return -1;
    }

    Memory *memory = start_executable_environment(program, None);
    stop_executable_environment(memory);

    return 0;
}
