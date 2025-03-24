# Game Emulator

A simple 8-bit game emulator written in C, simulating a basic CPU to execute simple game programs.

## Features

- **8-bit CPU simulation**
  - Registers: A (Accumulator), PC (Program Counter), FLAGS
  - 256-byte RAM
  - Basic instruction set for arithmetic, jumps, and control flow
- **Grid-based game logic**
  - Supports character movement (`W`, `A`, `S`, `D`) on a 10x10 grid
  - Displays the grid with the character's position
- **Instruction set for game control**

## Installation & Execution

### Compile the program
```bash
gcc main.c instructions.c -o emulator
```

### Run the emulator
```bash
./emulator
```

## Instruction Set

| Instruction   | Description                              |
|---------------|------------------------------------------|
| `NOP`         | Do nothing                               |
| `LDA X`       | Load value X into A register             |
| `ADD X`       | A = A + X                                |
| `SUB X`       | A = A - X                                |
| `JMP X`       | Jump to memory location X                |
| `JZ X`        | Jump to X if FLAGS == 1                  |
| `DRAW`        | Render a 10x10 grid with character       |
| `MOVE_UP`     | Move the character up                    |
| `MOVE_DOWN`   | Move the character down                  |
| `MOVE_LEFT`   | Move the character left                  |
| `MOVE_RIGHT`  | Move the character right                 |
| `HLT`         | Halt execution                           |

## Future Development

- Add graphical rendering using SDL2
- Expand the instruction set
- Support loading external ROM files

## Author

- **Developer:** WanChinTing
- **Contact:** artyidin1111@gmail.com