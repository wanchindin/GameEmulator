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

    uint8_t program[] =  {
        LDA, 11,
        STORE, 11,
        DRAW,
        IN,
        //WASD
        CMP, 'W',
        JZ, 0x1C,
        CMP, 'S',
        JZ, 0X21,
        CMP, 'A',
        JZ, 0x26,
        CMP, 'D',
        JZ, 0x2B,
        CMP, 'Q',
        JZ, 0x30,
        JMP, 5, //輸入無效跳回IN
        MOVE_UP, //28 = 0x1C
        CHECK_EXIT,
        DRAW,
        JMP, 5,
        MOVE_DOWN,  //33 = 0x21
        CHECK_EXIT,
        DRAW,
        JMP, 5,
        MOVE_LEFT, //38 = 0x26
        CHECK_EXIT,
        DRAW,
        JMP, 5,
        MOVE_RIGHT, //43 = 0x2B
        CHECK_EXIT,
        DRAW,
        JMP, 5,
        END_GAME, //48 = 0x30
        HLT
    };

    for(int i = 0; i < sizeof(program); i++){
        cpu.RAM[i] = program[i];
        //printf("RAM[%02X] = %02X\n", i, cpu.RAM[i]);
    }

    while(1){
        execute_instruction(&cpu);
    }

    free(cpu.RAM);
    return 0;
}
