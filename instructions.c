#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char maze[10][10] = {
    "##########",
    "#........#",
    "#..#####.#",
    "#..#.....#",
    "#..#..####",
    "#..#.....#",
    "#..#####.#",
    "#........#",
    "#.....E..#",
    "##########"  
};
void clear_screen(){
    printf("\033[2J"); // Clear the screen]")
}

void execute_instruction(CPU *cpu){
    uint8_t opcode = cpu->RAM[cpu->PC];     //指令
    uint8_t operand = cpu->RAM[cpu->PC + 1];    //參數

    switch(opcode){
        case NOP:
            sleep(2);
            //printf("NOP: No operation.\n");
            cpu->PC += 1;
            break;
        case LDA:
            cpu->A = operand;
            //printf("LDA: loaded %02X into accumulator (A).\n", cpu->A);
            cpu->PC += 2;
            break; 
        case ADD:
            cpu->A += operand;
            //printf("ADD: accumulator (A) + %02X = %02X.\n", operand, cpu->A);
            cpu->PC += 2;
            break;
        case SUB:
            cpu->A -= operand;
            //printf("SUB: accumulator (A) - %02X = %02X.\n", operand, cpu->A);
            cpu->PC += 2;
            break;
        case JMP:
            cpu->PC = operand;
            //printf("JMP: jumping to %02X.\n", cpu->PC);
            break;
        case JZ:
            if(cpu->FLAGS == 0x01){
                cpu->PC = operand;
                //printf("JZ: jumping to %02X.\n", cpu->PC);
            }else{
                cpu->PC += 2;
            }
            break;
        case CMP:
            if(cpu->A == operand){
                cpu->FLAGS = 0x01;
            }else{
                cpu->FLAGS = 0x00; //Clear FLAGS
            }
            //printf("CMP: Comparing A (%02X) with %02X. FLAGS = %02X\n", cpu->A, operand, cpu->FLAGS);
            cpu->PC += 2;
            break;
        case STORE:
            cpu->RAM[0] = operand;
            //printf("STORE: stored %02X in memory.\n", operand);
            cpu->PC += 2;
            break;
        case IN:
            printf("Enter a command(W/A/S/D to move, Q to quit):");
            char input;
            scanf(" %c", &input);   //前面有個空格 讀取input前跳過所有可能的空白字元
            clear_screen();
            cpu->A = input;
            cpu->PC += 1;
            break;
        case DRAW:
            //10x10 matrix
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i * 10 + j) == cpu->RAM[0]) {
                        printf("0 ");  // 玩家位置
                    } else {
                        printf("%c ", maze[i][j]);  // 顯示迷宮內容
                    }
                }
                printf("\n");
            }
            cpu->PC += 1;
            break;
        case CLR:
            memset(cpu->RAM, 0, 100);
            //printf("CLR: screen cleared.\n");
            cpu->PC += 1;
            break;
        case MOVE_UP:
            if(cpu->FLAGS == 0x01 && cpu->RAM[0]-10 >= 0 && 
                maze[(cpu->RAM[0] - 10) / 10][(cpu->RAM[0] - 10) % 10] != '#'){
                cpu->RAM[0] -= 10;
                //printf("MOVE_UP: character moved up.\n");
                cpu->FLAGS = 0x00;
            }
            cpu->PC += 1;
            break;
        case MOVE_DOWN:
            if(cpu->FLAGS == 0x01 && cpu->RAM[0]+10 < 100 &&
                maze[(cpu->RAM[0] + 10) / 10][(cpu->RAM[0] + 10) % 10] != '#'){
                cpu->RAM[0] += 10;
                //printf("MOVE_DOWN: character moved down.\n");
                cpu->FLAGS = 0x00;
            }
            cpu->PC += 1;
            break;
        case MOVE_LEFT:
            if(cpu->FLAGS == 0x01 && cpu->RAM[0] % 10 != 0 &&
                maze[cpu->RAM[0] / 10][(cpu->RAM[0] - 1) % 10] != '#'){
                cpu->RAM[0] -= 1;
                //printf("MOVE_LEFT: character moved left.\n");
                cpu->FLAGS = 0x00;
            }
            cpu->PC += 1;
            break;
        case MOVE_RIGHT:
            if(cpu->FLAGS == 0x01 && cpu->RAM[0] % 10 != 9 &&
                maze[cpu->RAM[0] / 10][(cpu->RAM[0] + 1) % 10] != '#'){
                cpu->RAM[0] += 1;
                //printf("MOVE_RIGHT: character moved right.\n");
                cpu->FLAGS = 0x00;
            }
            cpu->PC += 1;
            break;
        case CHECK_EXIT:
            if (maze[cpu->RAM[0] / 10][cpu->RAM[0] % 10] == 'E') {
                printf("Congratulations! You reached the exit!\n");
                exit(0);  // 結束遊戲
            }
            cpu->PC += 1;
            break;
        case END_GAME:
            if(cpu->FLAGS == 0x01){
                printf("END_GAME: Game Over.\n");
                cpu->PC += 1;
            }
            break;
        case HLT:
            //printf("CPU Halted.");
            cpu->PC += 1;
            exit(0);    //正常結束
        default:
            printf("Unknown opcode: %02X\n", opcode);   //輸出數字至少佔兩位 不足會在前面補零 16進位
            exit(1);    //異常結束
    }
    //printf("CPU State: A = %02X, PC = %02X\n", cpu->A, cpu->PC);
    //printf("-----------------------------\n");
}
