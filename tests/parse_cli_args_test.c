#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "console.h"

int verbose1 = 2;
char *verbose2[] = {
        "./stm8emulator",
        "--verbose"
        };
int verbose3 = 2;
char *verbose4[] = {
        "./stm8emulator",
        "-v"
        };
int simple1 = 3;
char *simple2[] = {
        "./stm8emulator",
        "--verbose",
        "path/to/elf.elf"
        };


void print_cli_args(int argc, char **argv) {
    for(int i = 0; i < argc; i++){
        fflush(stdout);
        printf("%s ", argv[i]);
    }
    printf("\n");
    fflush(stdout);
}

int main() {
    ConsoleFlags* flags = NULL;
    //Test : --verbose
    print_cli_args(verbose1,verbose2);
    if ((flags = parse_cli_args(verbose1, verbose2)) == NULL){
        return -1;
    } else {
        if (flags->verbose_output != true) return -1;
        free(flags);
    };
    //Test : --v
    print_cli_args(verbose3,verbose4);
    if ((flags = parse_cli_args(verbose3, verbose4)) == NULL){
        return -1;
    } else {
        if (flags->verbose_output != true) return -1;
        free(flags);
    };
    //Test : --verbose /path/to/elf.elf
    print_cli_args(simple1,simple2);
    if ((flags = parse_cli_args(simple1, simple2)) == NULL){
        return -1;
    } else {
        if (flags->verbose_output != true) return -1;
        if (strcmp(flags->elf_path, "path/to/elf.elf") != 0) return -1;
        free(flags);
    };
    return 0;
}