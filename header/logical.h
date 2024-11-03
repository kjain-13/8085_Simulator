
#include <iostream>
using namespace std;
// Logical and comparison operations
void ANI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void ANA(int &A, int b, bool (&flag)[8]);
void XRA(int &A, int b, bool (&flag)[8]);
void ORA(int &A, int b, bool (&flag)[8]);
void CMP(int &A, int b, bool (&flag)[8]);
void XRI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void ORI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void CPI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
// Logical and comparison with memory
void ANA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void XRA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void ORA_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void CMP_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);

// Rotate instructions
void RLC(int &A, bool &cy);
void RAL(int &A, bool &cy);
void RRC(int &A, bool &cy);
void RAR(int &A, bool &cy);
