#include "device.h"
#include "stdint.h"

Memory *start_executable_environment(Program executable_program, enum Device device_type) {
    
}
// Execute next instruction.
void execute_next_cycle() {

}
// Clean all allocated memory.
void stop_executable_environment(Memory *mem) {
    free(mem->flash_mem);
    free(mem->eeprom_mem);
    free(mem);
}