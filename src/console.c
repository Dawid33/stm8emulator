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
//TESTME
ConsoleFlags* parse_cli_args(int argc, char **argv) {
    ConsoleFlags flags;
    if (argc < 2) return NULL;

    bool has_elf_path = false;

    for(int i = 1; i < argc; i++){
        int len = strlen(argv[i]);
        //Parse for double dash flag "--"
        if(argv[i][0] == '-' && argv[i][0] == '-' && len > 2) {
            // Move the pointer to the start of the command flag (past the --)
            char *flag = argv[i] + 2;

            if (strcmp(flag, "help") == 0) {
                display_help();
                return NULL;
            } else if (strcmp(flag, "verbose") == 0) {
                flags.verbose_output = true;
            } else {
                printf("Command line argument \"%s\" not recognised\n", argv[i]);
                return NULL;
            }
        // Single letter flags i.e. -v
        } else if (argv[i][0] == '-' && len > 1) {
            // Move the pointer to the start of the command flag (past the -)
            int j = 1;
            for (; j < len; j++) {
                if (argv[i][j] == 'v') {
                    flags.verbose_output = true;
                }
            }
        // If the argument is not a flag then it must be the path to the exec. 
        } else if (!has_elf_path) {
            flags.elf_path = (char*)malloc(sizeof(char) * len);
            //FIXME: dont use strcopy
            strcpy(flags.elf_path, argv[i]);
            has_elf_path = true;
        } else {
            printf("Command line argument \"%s\" not recognised\n", argv[i]);
            return NULL;
        }
    }
    
    ConsoleFlags* result = (ConsoleFlags*)malloc(sizeof(ConsoleFlags));
    if (result == NULL) {
        printf("Allocation error\n");
        return NULL;
    }
    result->elf_path = flags.elf_path;
    result->verbose_output = flags.verbose_output;
    return result;
}

void pretty_print_cli_flags(const ConsoleFlags *flags) {
    printf("Verbose Output : ");
    if (flags->verbose_output) printf("Yes\n"); else printf("No\n");
}