#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "console.h"

void display_help() {
    printf("hello, world!??\n");
}

/// If the return value is null, the parsing faild.
/// Caller must deallocate return value.
ConsoleFlags* handle_cli_args(int argc, char **argv) {
    ConsoleFlags* result = (ConsoleFlags*)malloc(sizeof(ConsoleFlags));
    if (result == NULL) {
        printf("Allocation error\n");
        return NULL;
    }
    if (argc < 2) return NULL;

    bool has_elf_path = false;

    for(int i = 1; i < argc; i++){
        int len = strlen(argv[i]);
        //Does the argument start with a --?
        if(argv[i][0] == '-' && argv[i][0] == '-' && len > 2) {
            // Move the pointer to the start of the command flag (past the --)
            char *flag = argv[i] + 2;
            if (strcmp(flag, "help") == 0) {
                display_help();
                free(result);
                return NULL;
            } else if (strcmp(flag, "verbose") == 0) {
                result->verbose_output = true;
            } else {
                printf("Command line argument \"%s\" not recognised\n", argv[i]);
                free(result);
                return NULL;
            }
        } else if (argv[i][0] == '-' && len > 1) {
            // Move the pointer to the start of the command flag (past the -)
            int j = 1;
            for (; j < len; j++) {
                if (argv[i][j] == 'v') {
                    result->verbose_output = true;
                }
            }
        } else if (!has_elf_path) {
            result->elf_path = (char*)malloc(sizeof(char) * len);
            strcpy(result->elf_path, argv[i]);
            has_elf_path = true;
        } else {
            printf("Command line argument \"%s\" not recognised\n", argv[i]);
            free(result);
            return NULL;
        }
    }
    
    return result;
}

void print_console_options(const ConsoleFlags *flags) {
    if (flags->verbose_output) {
        printf("Verbose Output enabled\n");
    }
}