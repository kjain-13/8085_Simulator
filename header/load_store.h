
#include <iostream>
using namespace std;

// Data transfer functions
void MOV_regM(int &reg0, int h, int l, int (&mem)[16][16][16]);
void MOV_Mreg(int reg0, int h, int l, int (&mem)[16][16][16]);
void MOV_AB(int &A, int B);

// Memory and address instructions
void LDA(int &A, int (&mem)[16][16][16], int &pc);
void STA(int A, int (&mem)[16][16][16], int &pc);

void LHLD(int &h, int &l, int (&mem)[16][16][16], int &pc);
void SHLD(int h, int l, int (&mem)[16][16][16], int &pc);

// Increment and decrement functions
void INR(int& A, bool (&flag)[8]);
void DCR(int& A, bool (&flag)[8]);

// Immediate data functions
void MVI(int &A, int (&mem)[16][16][16], int &pc);
void MVI_M(int h, int l, int (&mem)[16][16][16], int &pc);

// Decimal adjust accumulator
void DAA(int &A, bool (&flag)[8]);

// 16-bit increment/decrement
void INX(int &b, int &c);
void DCX(int &b, int &c);

// Load/store accumulator
void LDAX(int &A, int B, int C, int (&mem)[16][16][16]);
void STAX(int A, int B, int C, int (&mem)[16][16][16]);

// Load immediate
void LXI(int &B, int &C, int (&mem)[16][16][16], int &pc);

// Double add
void DAD(int &h, int &l, int b, int c, bool (&flag)[8]);

// Jump to address in HL
void PCHL(int h, int l, int &pc);
