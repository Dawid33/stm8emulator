#ifndef _IO_H
#define _IO_H
#include "device.h"
char* read_file(const char *file_path);
Program *parse_hex_file(char *file);
#endif