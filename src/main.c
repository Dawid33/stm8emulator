#include <stdlib.h>
#include <curses.h>
#include "console.h"

void exit_main() {
    close_console();
    exit(0);
}

int main (int argc, char **argv) {
    //Initialisation code.
    if (atexit(exit_main) != 0) return -1; // Run function at program exit.

    if (init_console() != 0){
        close_console();
        return -1;
    }

    ConsoleFlags* flags = parse_args(argc, argv);
    if (flags == NULL) return -1;

    return 0;
}