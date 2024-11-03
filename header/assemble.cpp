#include <iostream>
#include <unordered_map>
#include "info.h"

using namespace std;

unordered_map<string, int> mp;
unordered_map<string, int> cycle;
unordered_map<int, string> decode;

void init_map(){

    mp["ADI"] = 0xC6; cycle["ADI"] = 2;
    mp["ACI"] = 0xCE; cycle["ACI"] = 2;
    mp["SBI"] = 0xDE; cycle["SBI"] = 2;
    mp["SUI"] = 0xD6; cycle["SUI"] = 2;
    mp["DAA"] = 0x27; cycle["DAA"] = 1;

    mp["ANI"] = 0xE6; cycle["ANI"] = 2;
    mp["XRI"] = 0xEE; cycle["XRI"] = 2;
    mp["ORI"] = 0xF6; cycle["ORI"] = 2;
    mp["CPI"] = 0xFE; cycle["CPI"] = 2;

    mp["RLC"] = 0x07; cycle["RLC"] = 1;
    mp["RAL"] = 0x17; cycle["RAL"] = 1;
    mp["RRC"] = 0x0F; cycle["RRC"] = 1;
    mp["RAR"] = 0x1F; cycle["RAR"] = 1;

    mp["CMA"] = 0x2F; cycle["CMA"] = 1;
    mp["CMC"] = 0x3F; cycle["CMC"] = 1;
    mp["STC"] = 0x37; cycle["STC"] = 1;

    mp["LDA"] = 0x3A; cycle["LDA"] = 3;
    mp["STA"] = 0x32; cycle["STA"] = 3;
    mp["LHLD"] = 0x2A; cycle["LHLD"] = 3;
    mp["SHLD"] = 0x22; cycle["SHLD"] = 3;
    mp["XCHG"] = 0xEB; cycle["XCHG"] = 1;
    mp["XTHL"] = 0xE3; cycle["XTHL"] = 1;
    mp["PCHL"] = 0xE9 ; cycle["PCHL"] = 1;
    mp["SPHL"] = 0xF9; cycle["SPHL"] = 1;

    mp["JMP"] = 0xC3; cycle["JMP"] = 3;
    mp["JNZ"] = 0xC2; cycle["JNZ"] = 3;
    mp["JZ"] = 0xCA; cycle["JZ"] = 3;
    mp["JNC"] = 0xD2; cycle["JNC"] = 3;
    mp["JC"] = 0xDA; cycle["JC"] = 3;
    mp["JPO"] = 0xE2; cycle["JPO"] = 3;
    mp["JPE"] = 0xEA; cycle["JPE"] = 3;
    mp["JP"] = 0xF2; cycle["JP"] = 3;
    mp["JM"] = 0xFA; cycle["JM"] = 3;

    mp["CALL"] = 0xCD ; cycle["CALL"] = 3;
    mp["CC"] = 0xDC ; cycle["CC"] = 3;
    mp["CNC"] = 0xD4 ; cycle["CNC"] = 3;
    mp["CZ"] = 0xCC ; cycle["CZ"] = 3;
    mp["CNZ"] = 0xC4 ; cycle["CNZ"] = 3;
    mp["CPE"] = 0xEC ; cycle["CPO"] = 3;
    mp["CPO"] = 0xE4 ; cycle["CPE"] = 3;
    mp["CM"] = 0xFC ; cycle["CM"] = 3;
    mp["CP"] = 0xF4 ; cycle["CP"] = 3;

    mp["RET"] = 0xC9 ; cycle["RET"] = 1;
    mp["RC"] = 0xD8 ; cycle["RC"] = 1;
    mp["RNC"] = 0xD0 ; cycle["RNC"] = 1;
    mp["RZ"] = 0xC8 ; cycle["RZ"] = 1;
    mp["RNZ"] = 0xC0 ; cycle["RNZ"] = 1;
    mp["RPE"] = 0xE8 ; cycle["RPO"] = 1;
    mp["RPO"] = 0xE0 ; cycle["RPE"] = 1;
    mp["RM"] = 0xF8 ; cycle["RM"] = 1;
    mp["RP"] = 0xF0 ; cycle["RP"] = 1;

    mp["NOP"] = 0x00; cycle["NOP"] = 1;
    mp["HLT"] = 0x76; cycle["HLT"] = 1;

    mp["MVI A"] = 0x3E ; cycle ["MVI A"] = 2;
    mp["MVI B"] = 0x06 ; cycle ["MVI B"] = 2;
    mp["MVI C"] = 0x0E ; cycle ["MVI C"] = 2;
    mp["MVI D"] = 0x16 ; cycle ["MVI D"] = 2;
    mp["MVI E"] = 0x1E ; cycle ["MVI E"] = 2;
    mp["MVI H"] = 0x26 ; cycle ["MVI H"] = 2;
    mp["MVI L"] = 0x2E ; cycle ["MVI L"] = 2;
    mp["MVI M"] = 0x36 ; cycle ["MVI M"] = 2;

    mp["MOV A,B"] = 0x78; cycle["MOV A,B"] = 1;
    mp["MOV A,C"] = 0x79; cycle["MOV A,C"] = 1;
    mp["MOV A,D"] = 0x7A; cycle["MOV A,D"] = 1;
    mp["MOV A,E"] = 0x7B; cycle["MOV A,E"] = 1;
    mp["MOV A,H"] = 0x7C; cycle["MOV A,H"] = 1;
    mp["MOV A,L"] = 0x7D; cycle["MOV A,L"] = 1;
    mp["MOV A,M"] = 0x7E; cycle["MOV A,M"] = 1;
    mp["MOV B,A"] = 0x47; cycle["MOV B,A"] = 1;
    mp["MOV B,C"] = 0x41; cycle["MOV B,C"] = 1;
    mp["MOV B,D"] = 0x42; cycle["MOV B,D"] = 1;
    mp["MOV B,E"] = 0x43; cycle["MOV B,E"] = 1;
    mp["MOV B,H"] = 0x44; cycle["MOV B,H"] = 1;
    mp["MOV B,L"] = 0x45; cycle["MOV B,L"] = 1;
    mp["MOV B,M"] = 0x46; cycle["MOV B,M"] = 1;
    mp["MOV C,A"] = 0x4F; cycle["MOV C,A"] = 1;
    mp["MOV C,B"] = 0x48; cycle["MOV C,B"] = 1;
    mp["MOV C,D"] = 0x4A; cycle["MOV C,D"] = 1;
    mp["MOV C,E"] = 0x4B; cycle["MOV C,E"] = 1;
    mp["MOV C,H"] = 0x4C; cycle["MOV C,H"] = 1;
    mp["MOV C,L"] = 0x4D; cycle["MOV C,L"] = 1;
    mp["MOV C,M"] = 0x4E; cycle["MOV C,M"] = 1;
    mp["MOV D,A"] = 0x57; cycle["MOV D,A"] = 1;
    mp["MOV D,B"] = 0x50; cycle["MOV D,B"] = 1;
    mp["MOV D,C"] = 0x51; cycle["MOV D,C"] = 1;
    mp["MOV D,E"] = 0x53; cycle["MOV D,E"] = 1;
    mp["MOV D,H"] = 0x54; cycle["MOV D,H"] = 1;
    mp["MOV D,L"] = 0x55; cycle["MOV D,L"] = 1;
    mp["MOV D,M"] = 0x56; cycle["MOV D,M"] = 1;
    mp["MOV E,A"] = 0x5F; cycle["MOV E,A"] = 1;
    mp["MOV E,B"] = 0x58; cycle["MOV E,B"] = 1;
    mp["MOV E,C"] = 0x59; cycle["MOV E,C"] = 1;
    mp["MOV E,D"] = 0x5A; cycle["MOV E,D"] = 1;
    mp["MOV E,H"] = 0x5C; cycle["MOV E,H"] = 1;
    mp["MOV E,L"] = 0x5D; cycle["MOV E,L"] = 1;
    mp["MOV E,M"] = 0x5E; cycle["MOV E,M"] = 1;
    mp["MOV H,A"] = 0x67; cycle["MOV H,A"] = 1;
    mp["MOV H,B"] = 0x60; cycle["MOV H,B"] = 1;
    mp["MOV H,C"] = 0x61; cycle["MOV H,C"] = 1;
    mp["MOV H,D"] = 0x62; cycle["MOV H,D"] = 1;
    mp["MOV H,E"] = 0x63; cycle["MOV H,E"] = 1;
    mp["MOV H,L"] = 0x65; cycle["MOV H,L"] = 1;
    mp["MOV H,M"] = 0x66; cycle["MOV H,M"] = 1;
    mp["MOV L,A"] = 0x6F; cycle["MOV L,A"] = 1;
    mp["MOV L,B"] = 0x68; cycle["MOV L,B"] = 1;
    mp["MOV L,C"] = 0x69; cycle["MOV L,C"] = 1;
    mp["MOV L,D"] = 0x6A; cycle["MOV L,D"] = 1;
    mp["MOV L,E"] = 0x6B; cycle["MOV L,E"] = 1;
    mp["MOV L,H"] = 0x6C; cycle["MOV L,H"] = 1;
    mp["MOV L,M"] = 0x6E; cycle["MOV L,M"] = 1;
    mp["MOV M,A"] = 0x77; cycle["MOV M,A"] = 1;
    mp["MOV M,B"] = 0x70; cycle["MOV M,B"] = 1;
    mp["MOV M,C"] = 0x71; cycle["MOV M,C"] = 1;
    mp["MOV M,D"] = 0x72; cycle["MOV M,D"] = 1;
    mp["MOV M,E"] = 0x73; cycle["MOV M,E"] = 1;
    mp["MOV M,H"] = 0x74; cycle["MOV M,H"] = 1;
    mp["MOV M,L"] = 0x75; cycle["MOV M,L"] = 1;

    mp["INR A"] = 0x3C; cycle["INR A"] = 1;
    mp["INR B"] = 0x04; cycle["INR B"] = 1;
    mp["INR C"] = 0x0C; cycle["INR C"] = 1;
    mp["INR D"] = 0x14; cycle["INR D"] = 1;
    mp["INR E"] = 0x1C; cycle["INR E"] = 1;
    mp["INR H"] = 0x24; cycle["INR H"] = 1;
    mp["INR L"] = 0x2C; cycle["INR L"] = 1;
    mp["INR M"] = 0x34; cycle["INR M"] = 1;

    mp["DCR A"] = 0x3D; cycle["DCR A"] = 1;
    mp["DCR B"] = 0x05; cycle["DCR B"] = 1;
    mp["DCR C"] = 0x0D; cycle["DCR C"] = 1;
    mp["DCR D"] = 0x15; cycle["DCR D"] = 1;
    mp["DCR E"] = 0x1D; cycle["DCR E"] = 1;
    mp["DCR H"] = 0x25; cycle["DCR H"] = 1;
    mp["DCR L"] = 0x2D; cycle["DCR L"] = 1;
    mp["DCR M"] = 0x35; cycle["DCR M"] = 1;

    mp["ORA A"] = 0xB7; cycle["ORA A"] = 1;
    mp["ORA B"] = 0xB0; cycle["ORA B"] = 1;
    mp["ORA C"] = 0xB1; cycle["ORA C"] = 1;
    mp["ORA D"] = 0xB2; cycle["ORA D"] = 1;
    mp["ORA E"] = 0xB3; cycle["ORA E"] = 1;
    mp["ORA H"] = 0xB4; cycle["ORA H"] = 1;
    mp["ORA L"] = 0xB5; cycle["ORA L"] = 1;
    mp["ORA M"] = 0xB6; cycle["ORA M"] = 1;

    mp["XRA A"] = 0xAF; cycle["XRA A"] = 1;
    mp["XRA B"] = 0xA8; cycle["XRA B"] = 1;
    mp["XRA C"] = 0xA9; cycle["XRA C"] = 1;
    mp["XRA D"] = 0xAA; cycle["XRA D"] = 1;
    mp["XRA E"] = 0xAB; cycle["XRA E"] = 1;
    mp["XRA H"] = 0xAC; cycle["XRA H"] = 1;
    mp["XRA L"] = 0xAD; cycle["XRA L"] = 1;
    mp["XRA M"] = 0xAE; cycle["XRA M"] = 1;

    mp["CMP A"] = 0xBF; cycle["CMP A"] = 1;
    mp["CMP B"] = 0xB8; cycle["CMP B"] = 1;
    mp["CMP C"] = 0xB9; cycle["CMP C"] = 1;
    mp["CMP D"] = 0xBA; cycle["CMP D"] = 1;
    mp["CMP E"] = 0xBB; cycle["CMP E"] = 1;
    mp["CMP H"] = 0xBC; cycle["CMP H"] = 1;
    mp["CMP L"] = 0xBD; cycle["CMP L"] = 1;
    mp["CMP M"] = 0xBE; cycle["CMP M"] = 1;

    mp["ANA A"] = 0xA7; cycle["ANA A"] = 1;
    mp["ANA B"] = 0xA0; cycle["ANA B"] = 1;
    mp["ANA C"] = 0xA1; cycle["ANA C"] = 1;
    mp["ANA D"] = 0xA2; cycle["ANA D"] = 1;
    mp["ANA E"] = 0xA3; cycle["ANA E"] = 1;
    mp["ANA H"] = 0xA4; cycle["ANA H"] = 1;
    mp["ANA L"] = 0xA5; cycle["ANA L"] = 1;
    mp["ANA M"] = 0xA6; cycle["ANA M"] = 1;

    mp["ADD A"] = 0x87; cycle["ADD A"] = 1;
    mp["ADD B"] = 0x80; cycle["ADD B"] = 1;
    mp["ADD C"] = 0x81; cycle["ADD C"] = 1;
    mp["ADD D"] = 0x82; cycle["ADD D"] = 1;
    mp["ADD E"] = 0x83; cycle["ADD E"] = 1;
    mp["ADD H"] = 0x84; cycle["ADD H"] = 1;
    mp["ADD L"] = 0x85; cycle["ADD L"] = 1;
    mp["ADD M"] = 0x86; cycle["ADD M"] = 1;

    mp["ADC A"] = 0x8F; cycle["ADC A"] = 1;
    mp["ADC B"] = 0x88; cycle["ADC B"] = 1;
    mp["ADC C"] = 0x89; cycle["ADC C"] = 1;
    mp["ADC D"] = 0x8A; cycle["ADC D"] = 1;
    mp["ADC E"] = 0x8B; cycle["ADC E"] = 1;
    mp["ADC H"] = 0x8C; cycle["ADC H"] = 1;
    mp["ADC L"] = 0x8D; cycle["ADC L"] = 1;
    mp["ADC M"] = 0x8E; cycle["ADC M"] = 1;


    mp["SUB A"] = 0x97; cycle["SUB A"] = 1;
    mp["SUB B"] = 0x90; cycle["SUB B"] = 1;
    mp["SUB C"] = 0x91; cycle["SUB C"] = 1;
    mp["SUB D"] = 0x92; cycle["SUB D"] = 1;
    mp["SUB E"] = 0x93; cycle["SUB E"] = 1;
    mp["SUB H"] = 0x94; cycle["SUB H"] = 1;
    mp["SUB L"] = 0x95; cycle["SUB L"] = 1;
    mp["SUB M"] = 0x96; cycle["SUB M"] = 1;

    mp["SBB A"] = 0x9F; cycle["SBB A"] = 1;
    mp["SBB B"] = 0x98; cycle["SBB B"] = 1;
    mp["SBB C"] = 0x99; cycle["SBB C"] = 1;
    mp["SBB D"] = 0x9A; cycle["SBB D"] = 1;
    mp["SBB E"] = 0x9B; cycle["SBB E"] = 1;
    mp["SBB H"] = 0x9C; cycle["SBB H"] = 1;
    mp["SBB L"] = 0x9D; cycle["SBB L"] = 1;
    mp["SBB M"] = 0x9E; cycle["SBB M"] = 1;


    mp["INX B"] = 0x03; cycle["INX B"] = 1;
    mp["INX D"] = 0x13; cycle["INX D"] = 1;
    mp["INX H"] = 0x23; cycle["INX H"] = 1;
    mp["INX SP"] = 0x33; cycle["INX SP"] = 1;

    mp["DCX B"] = 0x0B; cycle["DCX B"] = 1;
    mp["DCX D"] = 0x1B; cycle["DCX D"] = 1;
    mp["DCX H"] = 0x2B; cycle["DCX H"] = 1;
    mp["DCX SP"] = 0x3B; cycle["DCX SP"] = 1;

    mp["LXI B"] = 0x01;cycle["LXI B"] = 3;
    mp["LXI D"] = 0x11;cycle["LXI D"] = 3;
    mp["LXI H"] = 0x21;cycle["LXI H"] = 3;
    mp["LXI SP"] = 0x31;cycle["LXI SP"] = 3;

    mp["DAD B"] = 0x09 ; cycle["DAD B"] = 1;
    mp["DAD D"] = 0x19 ; cycle["DAD D"] = 1;
    mp["DAD H"] = 0x29 ; cycle["DAD H"] = 1;
    mp["DAD SP"] = 0x39 ; cycle["DAD SP"] = 1;

    mp["LDAX B"] = 0x0A ; cycle["LDAX B"] = 1;
    mp["LDAX D"] = 0x1A ; cycle["LDAX D"] = 1;
    mp["STAX B"] = 0x02 ; cycle["STAX B"] = 1;
    mp["STAX D"] = 0x12 ; cycle["STAX D"] = 1;

    mp["PUSH B"] = 0xC5 ; cycle["PUSH B"] = 1;
    mp["PUSH D"] = 0xD5 ; cycle["PUSH D"] = 1;
    mp["PUSH H"] = 0xE5 ; cycle["PUSH H"] = 1;
    mp["PUSH PSW"] = 0xF5 ; cycle["PUSH PSW"] = 1;

    mp["POP B"] = 0xC1 ; cycle["POP B"] = 1;
    mp["POP D"] = 0xD1 ; cycle["POP D"] = 1;
    mp["POP H"] = 0xE1 ; cycle["POP H"] = 1;
    mp["POP PSW"] = 0xF1 ; cycle["POP PSW"] = 1;
}

void init_decoder(){
decode[0x00] = "NOP";

// arithmetic operations 
decode[0xC6] = "ADI";
decode[0xCE] = "ACI";
decode[0xDE] = "SBI";
decode[0xD6] = "SUI";
decode[0x27] = "DAA";
decode[0xE6] = "ANI";
decode[0xEE] = "XRI";
decode[0xF6] = "ORI";
decode[0xFE] = "CPI";
decode[0x07] = "RLC";
decode[0x17] = "RAL";
decode[0x0F] = "RRC";
decode[0x1F] = "RAR";
decode[0x2F] = "CMA";
decode[0x3F] = "CMC";
decode[0x37] = "STC";

// data transfer codes
decode[0x3A] = "LDA";
decode[0x32] = "STA";
decode[0x2A] = "LHLD";
decode[0x22] = "SHLD";
decode[0xEB] = "XCHG";
decode[0xE3] = "XTHL";
decode[0xE9] = "PCHL";
decode[0xF9] = "SPHL";

// control transfer 
decode[0xC3] = "JMP";
decode[0xC2] = "JNZ";
decode[0xCA] = "JZ";
decode[0xD2] = "JNC";
decode[0xDA] = "JC";
decode[0xE2] = "JPO";
decode[0xEA] = "JPE";
decode[0xF2] = "JP";
decode[0xFA] = "JM";
decode[0x76] = "HLT";

decode[0xCD] = "CALL";
decode[0xDC] = "CC";
decode[0xD4] = "CNC";
decode[0xCC] = "CZ";
decode[0xC4] = "CNZ";
decode[0xEC] = "CPE";
decode[0xE4] = "CPO";
decode[0xFC] = "CM";
decode[0xF4] = "CP";

decode[0xC9] = "RET";
decode[0xD8] = "RC";
decode[0xD0] = "RNC";
decode[0xC8] = "RZ";
decode[0xC0] = "RNZ";
decode[0xE8] = "RPE";
decode[0xE0] = "RPO";
decode[0xF8] = "RM";
decode[0xF0] = "RP";

// move operations
decode[0x78] = "MOV A,B";
decode[0x79] = "MOV A,C";
decode[0x7A] = "MOV A,D";
decode[0x7B] = "MOV A,E";
decode[0x7C] = "MOV A,H";
decode[0x7D] = "MOV A,L";
decode[0x7E] = "MOV A,M";

decode[0x47] = "MOV B,A";
decode[0x41] = "MOV B,C";
decode[0x42] = "MOV B,D";
decode[0x43] = "MOV B,E";
decode[0x44] = "MOV B,H";
decode[0x45] = "MOV B,L";
decode[0x46] = "MOV B,M";

decode[0x4F] = "MOV C,A";
decode[0x48] = "MOV C,B";
decode[0x4A] = "MOV C,D";
decode[0x4B] = "MOV C,E";
decode[0x4C] = "MOV C,H";
decode[0x4D] = "MOV C,L";
decode[0x4E] = "MOV C,M";

decode[0x57] = "MOV D,A";
decode[0x50] = "MOV D,B";
decode[0x51] = "MOV D,C";
decode[0x53] = "MOV D,E";
decode[0x54] = "MOV D,H";
decode[0x55] = "MOV D,L";
decode[0x56] = "MOV D,M";

decode[0x5F] = "MOV E,A";
decode[0x58] = "MOV E,B";
decode[0x59] = "MOV E,C";
decode[0x5A] = "MOV E,D";
decode[0x5C] = "MOV E,H";
decode[0x5D] = "MOV E,L";
decode[0x5E] = "MOV E,M";

decode[0x67] = "MOV H,A";
decode[0x60] = "MOV H,B";
decode[0x61] = "MOV H,C";
decode[0x62] = "MOV H,D";
decode[0x63] = "MOV H,E";
decode[0x65] = "MOV H,L";
decode[0x66] = "MOV H,M";

decode[0x6F] = "MOV L,A";
decode[0x68] = "MOV L,B";
decode[0x69] = "MOV L,C";
decode[0x6A] = "MOV L,D";
decode[0x6B] = "MOV L,E";
decode[0x6C] = "MOV L,H";
decode[0x6E] = "MOV L,M";

decode[0x77] = "MOV M,A";
decode[0x70] = "MOV M,B";
decode[0x71] = "MOV M,C";
decode[0x72] = "MOV M,D";
decode[0x73] = "MOV M,E";
decode[0x74] = "MOV M,H";
decode[0x75] = "MOV M,L";

decode[0x3C] = "INR A";
decode[0x04] = "INR B";
decode[0x0C] = "INR C";
decode[0x14] = "INR D";
decode[0x1C] = "INR E";
decode[0x24] = "INR H";
decode[0x2C] = "INR L";
decode[0x3C] = "INR M";

decode[0x3D] = "DCR A";
decode[0x05] = "DCR B";
decode[0x0D] = "DCR C";
decode[0x15] = "DCR D";
decode[0x1D] = "DCR E";
decode[0x25] = "DCR H";
decode[0x2D] = "DCR L";
decode[0x3D] = "DCR M";

decode[0xB7] = "ORA A";
decode[0xB0] = "ORA B";
decode[0xB1] = "ORA C";
decode[0xB2] = "ORA D";
decode[0xB3] = "ORA E";
decode[0xB4] = "ORA H";
decode[0xB5] = "ORA L";
decode[0xB6] = "ORA M";

decode[0xAF] = "XRA A";
decode[0xA8] = "XRA B";
decode[0xA9] = "XRA C";
decode[0xAA] = "XRA D";
decode[0xAB] = "XRA E";
decode[0xAC] = "XRA H";
decode[0xAD] = "XRA L";
decode[0xAE] = "XRA M";

decode[0xBF] = "CMP A";
decode[0xB8] = "CMP B";
decode[0xB9] = "CMP C";
decode[0xBA] = "CMP D";
decode[0xBB] = "CMP E";
decode[0xBC] = "CMP H";
decode[0xBD] = "CMP L";
decode[0xBE] = "CMP M";

decode[0xA7] = "ANA A";
decode[0xA0] = "ANA B";
decode[0xA1] = "ANA C";
decode[0xA2] = "ANA D";
decode[0xA3] = "ANA E";
decode[0xA4] = "ANA H";
decode[0xA5] = "ANA L";
decode[0xA6] = "ANA M";

decode[0x87] = "ADD A";
decode[0x80] = "ADD B";
decode[0x81] = "ADD C";
decode[0x82] = "ADD D";
decode[0x83] = "ADD E";
decode[0x84] = "ADD H";
decode[0x85] = "ADD L";
decode[0x86] = "ADD M";

decode[0x8F] = "ADC A";
decode[0x88] = "ADC B";
decode[0x89] = "ADC C";
decode[0x8A] = "ADC D";
decode[0x8B] = "ADC E";
decode[0x8C] = "ADC H";
decode[0x8D] = "ADC L";
decode[0x8E] = "ADC M";

decode[0x97] = "SUB A";
decode[0x90] = "SUB B";
decode[0x91] = "SUB C";
decode[0x92] = "SUB D";
decode[0x93] = "SUB E";
decode[0x94] = "SUB H";
decode[0x95] = "SUB L";
decode[0x96] = "SUB M";

decode[0x9F] = "SBB A";
decode[0x98] = "SBB B";
decode[0x99] = "SBB C";
decode[0x9A] = "SBB D";
decode[0x9B] = "SBB E";
decode[0x9C] = "SBB H";
decode[0x9D] = "SBB L";
decode[0x9E] = "SBB M";

decode[0x3E] = "MVI A";
decode[0x06] = "MVI B";
decode[0x0E] = "MVI C";
decode[0x16] = "MVI D";
decode[0x1E] = "MVI E";
decode[0x26] = "MVI H";
decode[0x2E] = "MVI L";
decode[0x36] = "MVI M";

decode[0x03] = "INX B";
decode[0x13] = "INX D";
decode[0x23] = "INX H";
decode[0x33] = "INX SP";

decode[0x0B] = "DCX B";
decode[0x1B] = "DCX D";
decode[0x2B] = "DCX H";
decode[0x3B] = "DCX SP";

decode[0x01] = "LXI B";
decode[0x11] = "LXI D";
decode[0x21] = "LXI H";
decode[0x31] = "LXI SP";

decode[0x09] = "DAD B";
decode[0x19] = "DAD D";
decode[0x29] = "DAD H";
decode[0x39] = "DAD SP";

decode[0x0A] = "LDAX B";
decode[0x1A] = "LDAX D";
decode[0x02] = "STAX B";
decode[0x12] = "STAX D";

decode[0xC5] = "PUSH B";
decode[0xD5] = "PUSH D";
decode[0xE5] = "PUSH H";
decode[0xF5] = "PUSH PSW";

decode[0xC1] = "POP B";
decode[0xD1] = "POP D";
decode[0xE1] = "POP H";
decode[0xF1] = "POP PSW";


}


string Capitalize(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }
    return s;
}

bool spaced_code(string s)
{
    return (s == "MOV" || s == "INR" || s == "DCR" || s == "ADD" || s == "ADC" || s == "LXI" || s == "LDAX" ||
            s == "SUB" || s == "SBB" || s == "ANA" || s == "ORA" || s == "XRA" || s == "CMP" || s == "MVI" ||
            s == "INX" || s == "DCX" || s == "STAX" || s == "DAD" || s == "PUSH" || s == "POP");
}

void assemble(string &addr, int (&mem)[16][16][16] , int &pc)
{
    int code = -1;
    int semaphore = 0;
    init_map();  // map converting assembly to machiene code
    string assembly_code;

    int add_num = htod(addr[0]) * 256 + htod(addr[1]) * 16 + htod(addr[2]);
    cout << hex << add_num << " : ";
    while (true)
    {
        cin >> assembly_code; // could try get line operation to reduce cycle time and excess output print
        
        if(semaphore == 0){
            if (assembly_code == "q")
                break;

            assembly_code = Capitalize(assembly_code);

            // cout << assembly_code << endl;

            if (spaced_code(assembly_code))
            {
                string data;
                cin >> data;
                data = Capitalize(data);
                assembly_code = assembly_code + " " + data;
            }

            if (semaphore == 0 && mp.find(assembly_code) == mp.end())
            {
                cout << "^ERROR" << endl;
                cout << hex << add_num << " : ";
                continue;
            }
            if (mp.find(assembly_code) != mp.end())
            {
                semaphore = cycle[assembly_code];
                code = mp[assembly_code];
                // cout << semaphore << " --- " << code << endl;
            }
        }
        else
        {
            // simple conversion does not work due to difference in its input as decimal or hex
            code = htod(assembly_code[0]) * 16 + htod(assembly_code[1]) ;
        }

        mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16] = code;
        add_num++;
        semaphore--;
        if (semaphore == 0)
            cout << hex << add_num << " : ";

        // cout << assembly_code << "  " << code << " " << semaphore << " - " << add_num << endl;
    }
    pc = add_num;
}

void unassemble(string &addr, int (&mem)[16][16][16])
{
    string asm_code;
    init_map();
    init_decoder();
    int semaphore = 0;

    int add_num = htod(addr[0]) * 256 + htod(addr[1]) * 16 + htod(addr[2]);

    while (decode.find(mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16]) == decode.end())
    {
        add_num++;
    }
    for(int i = 0 ; i < 10 ; i++){
        asm_code = decode[mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16]];
        semaphore = cycle[asm_code];

        cout << hex << add_num << " : " << asm_code << " " ;

        while (semaphore > 1)
        {
            add_num++;
            if(mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16] < 16){
                cout << "0";
            }
            cout << hex << mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16];
            semaphore--;
            // cout <<semaphore << endl;
        }
        add_num++;
        semaphore--;
        cout << endl;
    }
}

void unassemble_next(int addr, int (&mem)[16][16][16])
{
    string asm_code;
    init_map();
    init_decoder();
    int semaphore = 0;

    int add_num = addr;

    while (decode.find(mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16]) == decode.end())
    {
        add_num++;
    }


    asm_code = decode[mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16]];
    semaphore = cycle[asm_code];

    cout << hex << add_num << " : " << asm_code << " " ;

    while (semaphore > 1)
    {
        add_num++;
        if(mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16] < 16){
            cout << "0";
        }
        cout << hex << mem[add_num / 256][(add_num % 256) / 16][(add_num % 256) % 16];
        semaphore--;
        // cout <<semaphore << endl;
    }
    add_num++;
    semaphore--;
    cout << endl;
}