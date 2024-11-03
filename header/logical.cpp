#include <iostream>
using namespace std;
#include "execution.h"

void ANA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    addr = mem_of_pc(mem, addr);
    A = A & addr;
    update_flag(A, flag);
}
void XRA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    addr = mem_of_pc(mem, addr);
    A = A ^ addr;
    update_flag(A, flag);
}
void ORA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    addr = mem_of_pc(mem, addr);
    A = A | addr;
    update_flag(A, flag);
}
void CMP_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8])
{
    int addr = (h % 16) * 256 + l;
    addr = mem_of_pc(mem, addr);
    // fn
    update_flag(A - addr, flag);
}

void ANI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc);
    A = A & h;
    update_flag(A, flag);
}

void ANA(int &A, int b, bool (&flag)[8])
{
    A = A & b;
    update_flag(A, flag);
}

void XRA(int &A, int b, bool (&flag)[8])
{
    A = A ^ b;
    update_flag(A, flag);
}

void ORA(int &A, int b, bool (&flag)[8])
{
    A = A | b;
    update_flag(A, flag);
}

void CMP(int &A, int b, bool (&flag)[8])
{
    // fn
    update_flag(A - b, flag);
}

void XRI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc);
    A = A ^ h;
    update_flag(A, flag);
}

void ORI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc);
    A = A | h;
    update_flag(A, flag);
}

void CPI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8])
{
    pc++;
    int h = mem_of_pc(mem, pc);
    update_flag(A - h, flag);
    // fn
}

void RLC(int &A, bool &cy)
{
    int b7 = (A & 128) % 128;
    A = (A << 1) % 256;
    cy = b7;
    A += b7;
}
void RAL(int &A, bool &cy)
{
    int b0 = cy;
    cy = (A & 128) % 128;
    A = (A << 1) % 256;
    A += b0;
}

void RRC(int &A, bool &cy)
{
    int b0 = A & 1;
    cy = b0;
    A = (A >> 1) + (128 * b0);
}

void RAR(int &A, bool &cy)
{
    int b0 = A & 1;
    A = (A >> 1) + (128 * cy);
    cy = b0;
}