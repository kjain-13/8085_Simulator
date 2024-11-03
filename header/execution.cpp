#include <iostream>
#include <conio.h>
#include "stack.h"
#include "arithmathic.h"
#include "logical.h"
#include "load_store.h"

using namespace std;

int mem_of_pc(int (&mem)[16][16][16], int pc)
{
    return mem[pc / 256][(pc % 256) / 16][(pc % 256) % 16];
}

void update_flag(int Af, bool (&flag)[8])
{
    (Af == 0) ? flag[6] = 1 : flag[6] = 0;
    (Af & 128) ? flag[7] = 1 : flag[7] = 0;
    (Af > 255 || Af < 0) ? flag[0] = 1 : flag[0] = 0;
    // aux carry ?
    Af = (Af + 256) & 256;
    int count = 0;
    while (Af != 0)
    {
        if (Af % 2 == 1)
        {
            count++;
        }
        Af /= 2;
    }
    (count % 2 == 1) ? flag[2] == 0 : flag[2] == 1;
}

void JMP(int (&mem)[16][16][16], int &pc)
{
    pc++;
    int h = mem_of_pc(mem, pc);
    pc++;
    int l = mem_of_pc(mem, pc);
    pc = (h % 16) * 256 + l-1;
}


void execution(bool (&flag)[8], int (&reg)[7], int (&mem)[16][16][16], int &pc, int &sp)
{
    switch (mem_of_pc(mem, pc))
    {
    case 0x00:
        break;
    case 0x76:
        break;
    // load store inst.
    case 0x3A:
        LDA(reg[0], mem, pc);
        break;
    case 0x32:
        STA(reg[0], mem, pc);
        break;
    case 0xEB:
        swap(reg[3], reg[5]);
        swap(reg[4], reg[6]);
        break;
    case 0x2A:
        LHLD(reg[5], reg[6], mem, pc);
        break;
    case 0x22:
        SHLD(reg[5], reg[6], mem, pc);
        break;

    case 0xE3:
        XTHL(reg[5], reg[6], sp, mem);
        break;
    case 0xF9:
        PCHL(reg[5], reg[6], sp);
        break;
    case 0xE9:
        PCHL(reg[5], reg[6], pc);
        break;

    case 0x03: // INX B
        INX(reg[1], reg[2]);
        break;

    case 0x13: // INX D
        INX(reg[3], reg[4]);
        break;

    case 0x23: // INX H
        INX(reg[5], reg[6]);
        break;

    case 0x33: // INX SP
        sp = (sp + 1) % 65536;
        break;

    case 0x0B: // DCX B
        DCX(reg[1], reg[2]);
        break;

    case 0x1B: // DCX D
        DCX(reg[3], reg[4]);
        break;

    case 0x2B: // DCX H
        DCX(reg[5], reg[6]);
        break;

    case 0x3B: // DCX SP
        sp = (sp + 65535) % 65536;
        break;

    case 0x01: // LXI B
        LXI(reg[1], reg[2], mem, pc);
        break;

    case 0x11: // LXI D
        LXI(reg[3], reg[4], mem, pc);
        break;

    case 0x21: // LXI H
        LXI(reg[5], reg[6], mem, pc);
        break;

    case 0x31: // LXI SP
        int a, b;
        LXI(a, b, mem, pc);
        sp = a * 256 + b;
        break;

    case 0x09: // DAD B
        DAD(reg[5], reg[6], reg[1], reg[2], flag);
        break;

    case 0x19: // DAD D
        DAD(reg[5], reg[6], reg[3], reg[4], flag);
        break;

    case 0x29: // DAD H
        DAD(reg[5], reg[6], reg[5], reg[6], flag);
        break;

    case 0x39: // DAD SP
        DAD(reg[5], reg[6], sp / 256, sp % 256, flag);
        break;

    case 0x0A: // LDAX B
        LDAX(reg[0], reg[1], reg[2], mem);
        break;

    case 0x1A: // LDAX D
        LDAX(reg[0], reg[3], reg[4], mem);
        break;

    case 0x02: // STAX B
        STAX(reg[0], reg[1], reg[2], mem);
        break;

    case 0x12: // STAX D
        STAX(reg[0], reg[3], reg[4], mem);
        break;

    case 0xC5: // PUSH B
        PUSH(reg[1], reg[2], mem, sp);
        break;

    case 0xD5: // PUSH D
        PUSH(reg[3], reg[4], mem, sp);
        break;

    case 0xE5: // PUSH H
        PUSH(reg[5], reg[6], mem, sp);
        break;

    case 0xF5:{ // PUSH PSW
        int flg1 = (int)flag[0] + (int)flag[2] << 2 + (int)flag[4] << 4 + (int)flag[6] << 6 + (int)flag[7] << 7;
        PUSH(reg[0], flg1, mem, sp);
        break;
    }
    case 0xC1: // POP B
        POP(reg[1], reg[2], mem, sp);
        break;

    case 0xD1: // POP D
        POP(reg[3], reg[4], mem, sp);
        break;

    case 0xE1: // POP H
        POP(reg[5], reg[6], mem, sp);
        break;

    case 0xF1:{ // POP PSW
        int flg = 0;
        POP(reg[0], flg, mem, sp);
        flag[0] = flg & 1;
        flag[2] = flg & 4;
        flag[4] = flg & (1 << 4);
        flag[6] = flg & (1 << 6);
        flag[7] = flg & (1 << 7);
        break;
    }
    case 0x3E:
        MVI(reg[0], mem, pc);
        break;
    case 0x06:
        MVI(reg[1], mem, pc);
        break;
    case 0x0E:
        MVI(reg[2], mem, pc);
        break;
    case 0x16:
        MVI(reg[3], mem, pc);
        break;
    case 0x1E:
        MVI(reg[4], mem, pc);
        break;
    case 0x26:
        MVI(reg[5], mem, pc);
        break;
    case 0x2E:
        MVI(reg[6], mem, pc);
        break;
    case 0x36:
        MVI_M(reg[5], reg[6], mem, pc);
        break;
        // rotation and flags setter

    case 0x37:
        flag[0] = 1;
        break;
    case 0x3F:
        flag[0] = !flag[0];
        break;
    case 0x2F:
        reg[0] = reg[0] ^ 255;
        break;
    case 0x07:
        RLC(reg[0], flag[0]);
        break;
    case 0x17:
        RAL(reg[0], flag[0]);
        break;
    case 0x0F:
        RRC(reg[0], flag[0]);
        break;
    case 0x1F:
        RAR(reg[0], flag[0]);
        break;

        // arithmatic-immediate

    case 0xC6:
        ADI(reg[0], pc, mem, flag);
        break;
    case 0xCE:
        ACI(reg[0], pc, mem, flag);
        break;
    case 0xDE:
        SBI(reg[0], pc, mem, flag);
        break;
    case 0xD6:
        SUI(reg[0], pc, mem, flag);
        break;
    case 0x27:
        DAA(reg[0], flag);
        break;

    case 0x87:
        ADD(reg[0], reg[0], flag);
        break;
    case 0x80:
        ADD(reg[0], reg[1], flag);
        break;
    case 0x81:
        ADD(reg[0], reg[2], flag);
        break;
    case 0x82:
        ADD(reg[0], reg[3], flag);
        break;
    case 0x83:
        ADD(reg[0], reg[4], flag);
        break;
    case 0x84:
        ADD(reg[0], reg[5], flag);
        break;
    case 0x85:
        ADD(reg[0], reg[6], flag);
        break;

    case 0x8F:
        ADC(reg[0], reg[0], flag);
        break;
    case 0x88:
        ADC(reg[0], reg[1], flag);
        break;
    case 0x89:
        ADC(reg[0], reg[2], flag);
        break;
    case 0x8A:
        ADC(reg[0], reg[3], flag);
        break;
    case 0x8B:
        ADC(reg[0], reg[4], flag);
        break;
    case 0x8C:
        ADC(reg[0], reg[5], flag);
        break;
    case 0x8D:
        ADC(reg[0], reg[6], flag);
        break;

    case 0x97:
        SUB(reg[0], reg[0], flag);
        break;
    case 0x90:
        SUB(reg[0], reg[1], flag);
        break;
    case 0x91:
        SUB(reg[0], reg[2], flag);
        break;
    case 0x92:
        SUB(reg[0], reg[3], flag);
        break;
    case 0x93:
        SUB(reg[0], reg[4], flag);
        break;
    case 0x94:
        SUB(reg[0], reg[5], flag);
        break;
    case 0x95:
        SUB(reg[0], reg[6], flag);
        break;

    case 0x9F:
        SBB(reg[0], reg[0], flag);
        break;
    case 0x98:
        SBB(reg[0], reg[1], flag);
        break;
    case 0x99:
        SBB(reg[0], reg[2], flag);
        break;
    case 0x9A:
        SBB(reg[0], reg[3], flag);
        break;
    case 0x9B:
        SBB(reg[0], reg[4], flag);
        break;
    case 0x9C:
        SBB(reg[0], reg[5], flag);
        break;
    case 0x9D:
        SBB(reg[0], reg[6], flag);
        break;

        // mem oper

    case 0x86:
        ADD_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0x8E:
        ADC_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0x96:
        SUB_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0x9E:
        SBB_M(reg[0], reg[5], reg[6], mem, flag);
        break;

    case 0x3C:
        INR(reg[0], flag);
        break;
    case 0x04:
        INR(reg[1], flag);
        break;
    case 0x0C:
        INR(reg[2], flag);
        break;
    case 0x14:
        INR(reg[3], flag);
        break;
    case 0x1C:
        INR(reg[4], flag);
        break;
    case 0x24:
        INR(reg[5], flag);
        break;
    case 0x2C:
        INR(reg[6], flag);
        break;

    case 0x3D:
        DCR(reg[0], flag);
        break;
    case 0x05:
        DCR(reg[1], flag);
        break;
    case 0x0D:
        DCR(reg[2], flag);
        break;
    case 0x15:
        DCR(reg[3], flag);
        break;
    case 0x1D:
        DCR(reg[4], flag);
        break;
    case 0x25:
        DCR(reg[5], flag);
        break;
    case 0x2D:
        DCR(reg[6], flag);
        break;

        // ANA

    case 0xA7:
        ANA(reg[0], reg[0], flag);
        break;
    case 0xA0:
        ANA(reg[0], reg[1], flag);
        break;
    case 0xA1:
        ANA(reg[0], reg[2], flag);
        break;
    case 0xA2:
        ANA(reg[0], reg[3], flag);
        break;
    case 0xA3:
        ANA(reg[0], reg[4], flag);
        break;
    case 0xA4:
        ANA(reg[0], reg[5], flag);
        break;
    case 0xA5:
        ANA(reg[0], reg[6], flag);
        break;

    case 0xAF:
        XRA(reg[0], reg[0], flag);
        break;
    case 0xA8:
        XRA(reg[0], reg[1], flag);
        break;
    case 0xA9:
        XRA(reg[0], reg[2], flag);
        break;
    case 0xAA:
        XRA(reg[0], reg[3], flag);
        break;
    case 0xAB:
        XRA(reg[0], reg[4], flag);
        break;
    case 0xAC:
        XRA(reg[0], reg[5], flag);
        break;
    case 0xAD:
        XRA(reg[0], reg[6], flag);
        break;

    case 0xB7:
        ORA(reg[0], reg[0], flag);
        break;
    case 0xB0:
        ORA(reg[0], reg[1], flag);
        break;
    case 0xB1:
        ORA(reg[0], reg[2], flag);
        break;
    case 0xB2:
        ORA(reg[0], reg[3], flag);
        break;
    case 0xB3:
        ORA(reg[0], reg[4], flag);
        break;
    case 0xB4:
        ORA(reg[0], reg[5], flag);
        break;
    case 0xB5:
        ORA(reg[0], reg[6], flag);
        break;

    case 0xBF:
        CMP(reg[0], reg[0], flag);
        break;
    case 0xB8:
        CMP(reg[0], reg[1], flag);
        break;
    case 0xB9:
        CMP(reg[0], reg[2], flag);
        break;
    case 0xBA:
        CMP(reg[0], reg[3], flag);
        break;
    case 0xBB:
        CMP(reg[0], reg[4], flag);
        break;
    case 0xBC:
        CMP(reg[0], reg[5], flag);
        break;
    case 0xBD:
        CMP(reg[0], reg[6], flag);
        break;

    case 0xE6:
        ANI(reg[0], pc, mem, flag);
        break;
    case 0xEE:
        XRI(reg[0], pc, mem, flag);
        break;
    case 0xF6:
        ORI(reg[0], pc, mem, flag);
        break;
    case 0xFE:
        CPI(reg[0], pc, mem, flag);
        break;

        // mem operations

    case 0xA6:
        ANA_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0xAE:
        XRA_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0xB6:
        ORA_M(reg[0], reg[5], reg[6], mem, flag);
        break;
    case 0xBE:
        CMP_M(reg[0], reg[5], reg[6], mem, flag);
        break;

    // move instructions
    case 0x7E:
        MOV_regM(reg[0], reg[5], reg[6], mem);
        break;
    case 0x46:
        MOV_regM(reg[1], reg[5], reg[6], mem);
        break;
    case 0x4E:
        MOV_regM(reg[2], reg[5], reg[6], mem);
        break;
    case 0x56:
        MOV_regM(reg[3], reg[5], reg[6], mem);
        break;
    case 0x5E:
        MOV_regM(reg[4], reg[5], reg[6], mem);
        break;
    case 0x66:
        MOV_regM(reg[5], reg[5], reg[6], mem);
        break;
    case 0x6E:
        MOV_regM(reg[6], reg[5], reg[6], mem);
        break;

    case 0x77:
        MOV_Mreg(reg[0], reg[5], reg[6], mem);
        break;
    case 0x70:
        MOV_Mreg(reg[1], reg[5], reg[6], mem);
        break;
    case 0x71:
        MOV_Mreg(reg[2], reg[5], reg[6], mem);
        break;
    case 0x72:
        MOV_Mreg(reg[3], reg[5], reg[6], mem);
        break;
    case 0x73:
        MOV_Mreg(reg[4], reg[5], reg[6], mem);
        break;
    case 0x74:
        MOV_Mreg(reg[5], reg[5], reg[6], mem);
        break;
    case 0x75:
        MOV_Mreg(reg[6], reg[5], reg[6], mem);
        break;

    case 0x78:
        MOV_AB(reg[0], reg[1]);
        break;
    case 0x79:
        MOV_AB(reg[0], reg[2]);
        break;
    case 0x7A:
        MOV_AB(reg[0], reg[3]);
        break;
    case 0x7B:
        MOV_AB(reg[0], reg[4]);
        break;
    case 0x7C:
        MOV_AB(reg[0], reg[5]);
        break;
    case 0x7D:
        MOV_AB(reg[0], reg[6]);
        break;

    case 0x47:
        MOV_AB(reg[1], reg[0]);
        break;
    case 0x41:
        MOV_AB(reg[1], reg[2]);
        break;
    case 0x42:
        MOV_AB(reg[1], reg[3]);
        break;
    case 0x43:
        MOV_AB(reg[1], reg[4]);
        break;
    case 0x44:
        MOV_AB(reg[1], reg[5]);
        break;
    case 0x45:
        MOV_AB(reg[1], reg[6]);
        break;

    case 0x4F:
        MOV_AB(reg[2], reg[0]);
        break;
    case 0x48:
        MOV_AB(reg[2], reg[1]);
        break;
    case 0x4A:
        MOV_AB(reg[2], reg[3]);
        break;
    case 0x4B:
        MOV_AB(reg[2], reg[4]);
        break;
    case 0x4C:
        MOV_AB(reg[2], reg[5]);
        break;
    case 0x4D:
        MOV_AB(reg[2], reg[6]);
        break;

    case 0x57:
        MOV_AB(reg[3], reg[0]);
        break;
    case 0x50:
        MOV_AB(reg[3], reg[1]);
        break;
    case 0x51:
        MOV_AB(reg[3], reg[2]);
        break;
    case 0x53:
        MOV_AB(reg[3], reg[4]);
        break;
    case 0x54:
        MOV_AB(reg[3], reg[5]);
        break;
    case 0x55:
        MOV_AB(reg[3], reg[6]);
        break;

    case 0x5F:
        MOV_AB(reg[4], reg[0]);
        break;
    case 0x58:
        MOV_AB(reg[4], reg[1]);
        break;
    case 0x59:
        MOV_AB(reg[4], reg[2]);
        break;
    case 0x5A:
        MOV_AB(reg[4], reg[3]);
        break;
    case 0x5C:
        MOV_AB(reg[4], reg[5]);
        break;
    case 0x5D:
        MOV_AB(reg[4], reg[6]);
        break;

    case 0x67:
        MOV_AB(reg[5], reg[0]);
        break;
    case 0x60:
        MOV_AB(reg[5], reg[1]);
        break;
    case 0x61:
        MOV_AB(reg[5], reg[2]);
        break;
    case 0x62:
        MOV_AB(reg[5], reg[3]);
        break;
    case 0x63:
        MOV_AB(reg[5], reg[4]);
        break;
    case 0x65:
        MOV_AB(reg[5], reg[6]);
        break;

    case 0x6F:
        MOV_AB(reg[6], reg[0]);
        break;
    case 0x68:
        MOV_AB(reg[6], reg[1]);
        break;
    case 0x69:
        MOV_AB(reg[6], reg[2]);
        break;
    case 0x6A:
        MOV_AB(reg[6], reg[3]);
        break;
    case 0x6B:
        MOV_AB(reg[6], reg[4]);
        break;
    case 0x6C:
        MOV_AB(reg[6], reg[5]);
        break;

    // jump inst.
    case 0xC3:
        JMP(mem, pc);
        break;
    case 0xC2:
        if (!flag[6])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xCA:
        if (flag[6])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xD2:
        if (!flag[0])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xDA:
        if (flag[0])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xE2:
        if (!flag[2])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xEA:
        if (flag[2])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xF2:
        if (!flag[7])
            JMP(mem, pc);
        else pc += 2;
        break;
    case 0xFA:
        if (flag[7])
            JMP(mem, pc);
        else pc += 2;
        break;

    case 0xCD:
        CALL(mem, pc, sp);
        break;
    case 0xC4:
        if (!flag[6])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xCC:
        if (flag[6])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xD4:
        if (!flag[0])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xDC:
        if (flag[0])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xE4:
        if (!flag[2])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xEC:
        if (flag[2])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xF4:
        if (!flag[7])
            CALL(mem, pc, sp);
        else pc += 2;
        break;
    case 0xFC:
        if (flag[7])
            CALL(mem, pc, sp);
        else pc += 2;
        break;

    case 0xC9:
        RET(mem, pc, sp);
        break;
    case 0xC0:
        if (!flag[6])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xC8:
        if (flag[6])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xD0:
        if (!flag[0])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xD8:
        if (flag[0])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xE0:
        if (!flag[2])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xE8:
        if (flag[2])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xF0:
        if (!flag[7])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    case 0xF8:
        if (flag[7])
            RET(mem, pc, sp);
        else pc += 2;
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    // cout << pc << "debug" << endl;
    pc++;
}