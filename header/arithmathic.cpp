
#include <iostream>
#include "execution.h"
using namespace std;

void ADI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc), init_val = A;
    A += h;
    update_flag(A, flag);
    A = A % 256;
}

void ACI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc), init_val = A;
    A += h + flag[0];
    update_flag(A, flag);
    A = A % 256;
}

void ADD(int &A, int b, bool (&flag)[8])
{
    A += b;
    update_flag(A, flag);
    A = A % 256;
}

void ADC(int &A, int b, bool (&flag)[8])
{
    A += b + flag[0];
    update_flag(A, flag);
    A = A % 256;
}

void SBI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc), init_val = A;
    A = A - h - flag[0];
    update_flag(A, flag);
    if (A < 0)
    {
        A += 256;
    }
}
void SUI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc), init_val = A;
    A = A - h;
    update_flag(A, flag);
    if (A < 0)
    {
        A += 256;
    }
}

void SUB(int &A, int b, bool (&flag)[8])
{
    A -= b;
    update_flag(A, flag);
    A = (A+255) % 256;
}

void SBB(int &A, int b, bool (&flag)[8])
{
    A = A - b - flag[0];
    update_flag(A, flag);
    A = (A+255) % 256;
}

void ADD_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    A = A + mem_of_pc(mem, addr);
    update_flag(A, flag);
    A = A % 256;
}

void ADC_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    A = A + mem_of_pc(mem, addr) + flag[0];
    update_flag(A, flag);
    A = A % 256;
}

void SUB_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    A = A - mem_of_pc(mem, addr);
    update_flag(A, flag);
    A = (A+255) % 256;
}

void SBB_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    A = A - mem_of_pc(mem, addr) - flag[0];
    update_flag(A, flag);
    A = (A+255) % 256;
}