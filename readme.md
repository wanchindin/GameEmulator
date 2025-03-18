# Game Emulator

## Introduction

This is a simple 8-bit game emulator written in C. The goal is to learn **pointers, function pointers, and memory management** while simulating a basic CPU.

## Features

- **8-bit CPU simulation**
  - Registers: A, PC, FLAGS
  - Simple instruction set (LDA, ADD, JMP, etc.)
- **256-byte RAM simulation**
- **Execute basic game programs**

## Installation & Execution

### 1. Compile the program

```bash
gcc emulator.c -o emulator
```

### 2. Run the emulator

```bash
./emulator
```

## Instruction Set

| Instruction | Description                  |
| ----------- | ---------------------------- |
| `NOP`       | Do nothing                   |
| `LDA X`     | Load value X into A register |
| `ADD X`     | A = A + X                    |
| `SUB X`     | A = A - X                    |
| `JMP X`     | Jump to memory location X    |
| `JZ X`      | Jump to X if A == 0          |
| `HLT`       | Halt execution               |

## Future Development

- **Add graphics (SDL2)** for simple rendering
- **Implement keyboard input** for user interaction
- **Support more instructions and ROM loading**

## Author

- **Developer:** WanChinTing
- **Contact:** artyidin1111@gmail.com

