#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

#define NOP   0x00  // No operation (do nothing)
#define LDA   0x01  // Load value X into A register
#define ADD   0x02  // A = A + X
#define SUB   0x03  // A = A - X
#define JMP   0x04  // Jump to X (unconditional)
#define JZ    0x05  // Jump to X if zero flag is set
#define CMP   0x06  // Compare A with X
#define STORE 0x07  // Store value in memory

#define IN    0x08  // Read value from keyboard
#define DRAW  0x09  // Draw the screen
#define CLR   0x0A  // Clear the screen

// Movement Instructions for WASD
#define MOVE_UP    0x0B  // Move character up (W)
#define MOVE_DOWN  0x0C  // Move character down (S)
#define MOVE_LEFT  0x0D  // Move character left (A)
#define MOVE_RIGHT 0x0E  // Move character right (D)
#define END_GAME   0x0F  // End the game
#define CHECK_EXIT 0x10  // Check if the game should exit

#define HLT   0xFF  // Halt execution



void execute_instruction(CPU *cpu);

#endif