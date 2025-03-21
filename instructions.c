#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

void execute_instruction(CPU *cpu){
    uint8_t opcode = cpu->RAM[cpu->PC];     //指令
    uint8_t operand = cpu->RAM[cpu->PC + 1];    //參數
    cpu->PC += 2; //指令長度為2bytes

    switch(opcode){
        case NOP:
            printf("NOP: No operation.\n");
            break;
        case LDA:
            cpu->A = operand;
            printf("LDA: loaded %02X into accumulator (A).\n", cpu->A);
            break; 
        case ADD:
            cpu->A += operand;
            printf("ADD: accumulator (A) + %02X = %02X.\n", operand, cpu->A);
            break;
        case SUB:
            cpu->A -= operand;
            printf("SUB: accumulator (A) - %02X = %02X.\n", operand, cpu->A);
            break;
        case JMP:
            cpu->PC = operand;
            printf("JMP: jumping to %02X.\n", cpu->PC);
            break;
        case HLT:
            printf("CPU Halted.");
            exit(0);    //正常結束
        default:
            printf("Unknown opcode: %02X\n", opcode);   //輸出數字至少佔兩位 不足會在前面補零 16進位
            exit(1);    //異常結束
    }
    printf("CPU State: A = %02X, PC = %02X\n", cpu->A, cpu->PC);
    printf("-----------------------------\n");
}