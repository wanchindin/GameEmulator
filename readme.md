# Game Emulator

A simple 8-bit game emulator written in C, simulating a basic CPU to execute simple game programs. This project includes a grid-based maze game where the player navigates through a 10x10 maze to reach the exit.

---

## Features

### **8-bit CPU Simulation**
- **Registers**: 
  - `A` (Accumulator)
  - `PC` (Program Counter)
  - `FLAGS` (Condition Flags)
- **Memory**: 
  - 256-byte RAM
- **Instruction Set**: 
  - Supports arithmetic, jumps, control flow, and game-specific operations.

### **Maze Game Logic**
- **Grid-based gameplay**:
  - Navigate a 10x10 maze using `W`, `A`, `S`, `D` keys.
  - Prevents movement through walls (`#`).
  - Detects when the player reaches the exit (`E`).
- **Dynamic rendering**:
  - Displays the maze with the player's current position (`0`).

---

## Installation & Execution

### **1. Compile the Program**
Use GCC to compile the program:
```bash
gcc main.c instructions.c cpu.c -o emulator
```

### **2. Run the Emulator**
Execute the compiled program:
```bash
./emulator
```

---

## Controls

- **Move Up**: Press `W`
- **Move Down**: Press `S`
- **Move Left**: Press `A`
- **Move Right**: Press `D`

---

## Instruction Set

The emulator supports the following instructions:

| Opcode | Mnemonic  | Description                          |
|--------|-----------|--------------------------------------|
| `0x01` | `LOAD`    | Load a value into the accumulator.  |
| `0x02` | `ADD`     | Add a value to the accumulator.     |
| `0x03` | `SUB`     | Subtract a value from the accumulator. |
| `0x04` | `JMP`     | Jump to a specific memory address.  |
| `0x05` | `JZ`      | Jump if the zero flag is set.       |
| `0x06` | `JNZ`     | Jump if the zero flag is not set.   |
| `0x07` | `CMP`     | Compare a value with the accumulator. |
| `0x08` | `NOP`     | No operation (do nothing).          |
| `0x09` | `HLT`     | Halt the program execution.         |
---

## Example Output

```
##########
#0       #
#   ###  #
#   #E#  #
#   ###  #
#        #
##########
```
The player (`0`) must navigate through the maze to reach the exit (`E`).