// Include guard 防止標頭檔(.h)被重複定義
#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define RAM_SIZE 256

typedef struct {
    uint8_t A;      // Accumulator
    uint8_t PC;     // Program Counter
    uint8_t FLAGS;  // Flags
    uint8_t *RAM;   // 256 bytes RAM  
} CPU;

void cpu_init(CPU *cpu);

#endif