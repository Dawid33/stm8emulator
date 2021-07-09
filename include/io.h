#ifndef _IO_H
#define _IO_H
typedef struct {
    
} ElfHeader;
typedef struct {
    
} ElfFile;

char* read_file(const char *file_path);
ElfFile *parse_elf_file(char *file);
#endif