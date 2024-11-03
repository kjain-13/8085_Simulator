#include <iostream>
using namespace std;

void displayFlags(bool (&flag)[8]);
void display(bool (&flag)[8] , int (&reg)[7] , int pc , int sp);
void displayOnlyreg(bool (&flag)[8] , int (&reg)[7] ,string &regis , int& pc , int sp);
