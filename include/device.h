#ifndef _DEVICE_H
#define _DEVICE_H
#include <stdint.h>

enum Device {
    None,
};

typedef struct {
    char *instructions;
} Program;

typedef struct {
    uint8_t *flash_mem;
    uint8_t *eeprom_mem;
    uint8_t reg_A;
} Memory;

Memory *start_executable_environment(Program executable_program, enum Device device_type);
void execute_next_cycle();
void stop_execution();
void clean_executable_environment();
#endif