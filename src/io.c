#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"
#include "console.h"

char* read_file(const char* file_path) {
    FILE *elf_file = fopen(file_path,"r"); // Get file handle
    if (elf_file == NULL) {
        printf("Cannot open file : %s", file_path);
        return NULL;
    }

    // REVIEW
    // Set the pointer to the end of the file
    fseek(elf_file, 0, SEEK_END);
    // Get the position of the pointer.
    // file_size is size in bytes.
    long file_size = ftell(elf_file);
    // Reset pointer back to start.
    fseek(elf_file, 0, SEEK_SET);
    // Allocate enough memory to store the entire file.
    char *result = (char*)malloc(sizeof(char) * file_size);
    if (result == NULL) {
        printf("Allocation error.");
        free(elf_file);
        return NULL;
    }

    // Read file contents into result;
    fread(result, sizeof(char), file_size, elf_file);

    if (fclose(elf_file) < 0) {
        printf("Cannot close file : %s", file_path);
        free(result);
        return NULL;
    }

    return result;
}

Program *parse_hex_file(char* file) {
    
}