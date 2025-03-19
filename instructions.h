#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

#define NOP 0x00    //do nothing
#define LDA 0x01    //Load value X into A register
#define ADD 0x02    //A = A + X               
#define JMP 0x03    //Jump to X if A == 0 
#define HLT 0xFF    //halt execution

void execute_instruction(CPU *cpu);

#endif