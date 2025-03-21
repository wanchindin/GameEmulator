#include "cpu.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    CPU cpu;
    cpu_init(&cpu);
    // 測試 RAM 是否初始化為 0
    for (int i = 0; i < RAM_SIZE; i++) {
        if (cpu.RAM[i] != 0) {
            printf("RAM initialization failed at index %d\n", i);
            return 1;
        }
    }

    printf("CPU initialized successfully!\n");

    // A = 5 + 10
    uint8_t program[] =  {
        LDA, 5,
        ADD, 10,
        SUB, 13,
        HLT
    };

    for(int i = 0; i < sizeof(program); i++){
        cpu.RAM[i] = program[i];
    }

    while(1){
        execute_instruction(&cpu);
    }

    free(cpu.RAM);
    return 0;
}
