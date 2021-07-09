#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "io.h"

const char *test_file1 = "\
This is my file\n\
It is used in the read_file read_file test\n\
yes";

int main() {
    char *result = read_file("test_files/test_file1.txt");
    if (result != NULL) {
        printf("FINE STORED IN BINARY :\n%s\n", test_file1);
        printf("FINE STORED IN FILESYSTEM :\n%s\n", result);
        fflush(stdout);
        if (strcmp(result, test_file1) != 0) {
            free(result);
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}