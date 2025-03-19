#include "cpu.h"
#include <string.h>

void cpu_init(CPU *cpu){
    memset(cpu, 0, sizeof(CPU));
}