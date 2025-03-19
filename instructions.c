#include "instructions.h"
#include <stdio.h>

void execute_instruction(CPU *cpu){
    uint8_t opcode = cpu->RAM[cpu->PC];     //指令
    uint8_t operand = cpu->RAM[cpu->PC + 1];    //參數
    cpu->PC += 2; //指令長度為2bytes

    switch(opcode){
        case NOP:
            break;
        case LDA:
            cpu->A = operand;
            break;
        case ADD:
            cpu->A += operand;
            break;
        case JMP:
            cpu->PC = operand;
            break;
        case HLT:
            printf("CPU Halted.");
            exit(0);    //正常結束
        default:
            printf("Unknown opcode: %02X\n", opcode);
            exit(1);    //異常結束
    }
}