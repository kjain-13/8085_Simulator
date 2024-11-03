#include <iostream>
#include "execution.h"
using namespace std;

void MOV_regM(int &reg0, int h, int l, int (&mem)[16][16][16])
{
    reg0 = mem[h % 16][l / 16][l % 16];
}

void MOV_Mreg(int reg0, int h, int l, int (&mem)[16][16][16])
{
    mem[h % 16][l / 16][l % 16] = reg0;
}

void MOV_AB(int &A, int B)
{
    A = B;
}

void LDA(int &A, int (&mem)[16][16][16], int &pc)
{
    pc++;
    int h = mem_of_pc(mem, pc);
    pc++;
    int l = mem_of_pc(mem, pc);
    MOV_regM(A, h, l, mem);
}

void STA(int A, int (&mem)[16][16][16], int &pc)
{
    pc++;
    int h = mem_of_pc(mem, pc);
    pc++;
    int l = mem_of_pc(mem, pc);
    MOV_Mreg(A, h, l, mem);
}

void LHLD(int &h, int &l, int (&mem)[16][16][16], int &pc)
{
    pc++;
    int h1 = mem_of_pc(mem, pc);
    pc++;
    int l1 = mem_of_pc(mem, pc);
    int val = h1 * 256 + l1;
    l = mem_of_pc(mem, val);
    h = mem_of_pc(mem, val + 1);
}

void SHLD(int h, int l, int (&mem)[16][16][16], int &pc)
{
    pc++;
    int h1 = mem_of_pc(mem, pc);
    pc++;
    int l1 = mem_of_pc(mem, pc);
    int val = h1 * 256 + l1;
    mem[val / 256][(val % 256) / 16][(val % 256) % 16] = l;
    val++;
    mem[val / 256][(val % 256) / 16][(val % 256) % 16] = h;
}

void INR(int &A, bool (&flag)[8])
{
    A = (A + 1) % 256;
    update_flag(A, flag);
}

void DCR(int &A, bool (&flag)[8])
{
    A = (A + 255) % 256;
    update_flag(A, flag);
}

void MVI(int &A, int (&mem)[16][16][16], int &pc)
{
    pc++;
    A = mem_of_pc(mem, pc);
}

void MVI_M(int h, int l, int (&mem)[16][16][16], int &pc)
{
    pc++;
    mem[h % 16][l / 16][l % 16] = mem_of_pc(mem, pc);
}

void DAA(int &A, bool (&flag)[8])
{
    if (A & 0xF0 > 0x90)
    {
        A += 0x60;
    }
    if (flag[0])
    {
        A += 0x60;
    }
    if (A & 15 > 9)
    {
        A += 6;
    }
    if (flag[4])
    {
        A += 6;
    }
    update_flag(A, flag);
    A = A % 256;
}

void INX(int &b, int &c)
{
    int h = b * 256 + c;
    h = (h + 1) % 65536;
    b = h / 256;
    c = h % 256;
}

void DCX(int &b, int &c)
{
    int h = b * 256 + c;
    h = (h + 65535) % 65536;
    b = h / 256;
    c = h % 256;
}

void LDAX(int &A, int B, int C, int (&mem)[16][16][16])
{
    A = mem_of_pc(mem, B * 256 + C);
}

void STAX(int A, int B, int C, int (&mem)[16][16][16])
{
    mem[B % 16][C / 16][C % 16] = A;
}

void LXI(int &B, int &C, int (&mem)[16][16][16], int &pc)
{
    pc++;
    B = mem_of_pc(mem, pc);
    pc++;
    C = mem_of_pc(mem, pc);
}
void DAD(int &h, int &l, int b, int c, bool (&flag)[8])
{
    int a1 = h * 256 + l;
    int a2 = b * 256 + c;
    a1 = a1 + a2;
    flag[0] = a1 & 65536;
    h = (a1 % 65536) / 256;
    l = a1 % 256;
}

void PCHL(int h, int l, int &pc)
{
    pc = h * 256 + l;
}
