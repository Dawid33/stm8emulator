#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"

#define BUFFER_SIZE 200
char* read_file(const char* file_path) {
    char *result = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    FILE *elf_file = fopen(file_path,"r"); // Get file handle
    if (elf_file == NULL) {
        printf("Cannot open file : %s", file_path);
        return NULL;
    }

    bool  is_reading_file = true;
    // Read 200 characters of the file into buffer.
    // If \n or EOF is encountered then return everything
    // up to that point.
    char *residual_chars = NULL;
    int cnt = 1;
    while (true) {
        char *total_output = NULL;
        while ((residual_chars = fgets(result,BUFFER_SIZE,elf_file)) == NULL) { 
            char *total_output = (char*)malloc(sizeof(char) * cnt * BUFFER_SIZE);
            int max_index = cnt * BUFFER_SIZE;
            for(int i = BUFFER_SIZE; i < BUFFER_SIZE; i++) {
                result[i] = total_output[i + (cnt * BUFFER_SIZE)];
            }
        }
        if (residual_chars == NULL) {
            break;
        } else {
            int len = strlen(residual_chars);
            char *output = (char*)malloc(sizeof(char) * cnt * BUFFER_SIZE + len);
            output = total_output;
            
        }
    }
    

    if (fclose(elf_file) < 0) {
        printf("Cannot close file : %s", file_path);
        return NULL;
    }
    return result;
}