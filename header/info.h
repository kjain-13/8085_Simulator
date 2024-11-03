#include <iostream>
using namespace std;

void help();
int htod(char arg);
int stoh(string s);
void dump_mem(int (&mem)[16][16][16] , string& name );
void edit(int (&mem)[16][16][16] , string& addr);