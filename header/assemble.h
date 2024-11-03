#include <iostream>
#include <unordered_map>
using namespace std;

void Capitalize(string s);
void init_map();
void init_decoder();
void assemble(string &name , int (&mem)[16][16][16] , int& pc);
void unassemble(string &addr , int (&mem)[16][16][16]);
void unassemble_next(int addr, int (&mem)[16][16][16]);
