// #include <iostream>
// #include <conio.h>
// using namespace std;


// 8085_emulator.h

#ifndef EMULATOR_8085_H
#define EMULATOR_8085_H

#include <iostream>
using namespace std;

// Retrieves memory at given PC
int mem_of_pc(int (&mem)[16][16][16], int pc);

// Flag update function
void update_flag(int Af, bool (&flag)[8]);

void JMP(int (&mem)[16][16][16], int &pc);
// Main execution function
void execution(bool (&flag)[8], int (&reg)[7], int (&mem)[16][16][16], int &pc, int &sp);

#endif // EMULATOR_8085_H



// int mem_of_pc(int (&mem)[16][16][16], int pc);

// void PUSH(int b, int c, int (&mem)[16][16][16], int &sp);
// void POP(int &b, int &c, int (&mem)[16][16][16], int &sp);
// void execution(bool (&flag)[8] , int (&reg)[7] , int (&mem)[16][16][16] , int& pc , int &sp);