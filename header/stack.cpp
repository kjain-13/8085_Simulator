#include <iostream>
#include "execution.h"
using namespace std;


void PUSH(int b, int c, int (&mem)[16][16][16], int &sp)
{
    sp--;
    mem[(sp % 4096) / 256][(sp % 256) / 16][sp % 16] = b;
    sp--;
    mem[(sp % 4096) / 256][(sp % 256) / 16][sp % 16] = c;
}

void POP(int &b, int &c, int (&mem)[16][16][16], int &sp)
{
    c = mem_of_pc(mem, sp);
    sp++;
    b = mem_of_pc(mem, sp);
    sp++;
}


void CALL(int (&mem)[16][16][16], int &pc, int &sp)
{
    // code
    pc += 2;
    PUSH(pc / 256, pc % 256, mem, sp);
    pc -= 2;
    JMP(mem, pc);
}

void RET(int (&mem)[16][16][16], int &pc, int &sp)
{
    // code
    int a, b;
    POP(a, b, mem, sp);
    pc = a * 256 + b;
}


void XTHL(int &h, int &l, int &sp, int (&mem)[16][16][16])
{
    int a = h, b = l;
    POP(h, l, mem, sp);
    PUSH(a, b, mem, sp);
}