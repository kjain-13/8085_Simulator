// Arithmetic operations
void ADI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void ACI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void ADD(int &A, int b, bool (&flag)[8]);
void ADC(int &A, int b, bool (&flag)[8]);
void SBI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void SUI(int &A, int &pc, int (&mem)[16][16][16], bool (&flag)[8]);
void SUB(int &A, int b, bool (&flag)[8]);
void SBB(int &A, int b, bool (&flag)[8]);
void ADD_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void ADC_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void SUB_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);
void SBB_M(int &A, int h, int l, int (&mem)[16][16][16], bool (&flag)[8]);