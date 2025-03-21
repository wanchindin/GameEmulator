#include "cpu.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void cpu_init(CPU *cpu){
    // 初始化非指標成員
    cpu->A = 0;
    cpu->PC = 0;
    cpu->FLAGS = 0;

    // 動態分配 RAM
    cpu->RAM = (uint8_t *)malloc(RAM_SIZE * sizeof(uint8_t));
    if (cpu->RAM == NULL) {
        printf("Memory allocation for RAM failed!\n");
        exit(1); // 如果分配失敗，退出程式
    }

    // 初始化 RAM 為 0
    memset(cpu->RAM, 0, RAM_SIZE);
}