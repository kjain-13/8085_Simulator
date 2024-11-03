
#include <iostream>
using namespace std;
// Subroutine functions
void CALL(int (&mem)[16][16][16], int &pc, int &sp);
void RET(int (&mem)[16][16][16], int &pc, int &sp);
// Stack operations
void PUSH(int b, int c, int (&mem)[16][16][16], int &sp);
void POP(int &b, int &c, int (&mem)[16][16][16], int &sp);

// Exchange HL with top of stack
void XTHL(int &h, int &l, int &sp, int (&mem)[16][16][16]);