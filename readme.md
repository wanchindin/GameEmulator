# Game Emulator

## Introduction

A simple 8-bit game emulator written in C to simulate a basic CPU and learn **pointers, function pointers, and memory management**.

## Features

- **8-bit CPU simulation**
  - Registers: A, PC, FLAGS
  - 256-byte RAM
  - Basic instruction set (LDA, ADD, JMP, etc.)
- **Execute simple game programs**

## Installation & Execution

### Compile the program
```bash
gcc emulator.c -o emulator
```

### Run the emulator
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

- Add graphics (SDL2) for rendering
- Implement keyboard input
- Support more instructions and ROM loading

## Author

- **Developer:** WanChinTing
- **Contact:** artyidin1111@gmail.com