#include <iostream>
#include <conio.h>
#include "header/info.h"
#include "header/assemble.h"
#include "header/status.h"
#include "header/execution.h"

using namespace std;

int mem[16][16][16];
bool flag[8];
int reg[7];
int pc = 0,sp = 0x1000;


int main()
{
    char func;
    cout << "-";
    cin >> func;
    while (func != 'q')
    {
        if (func == '?')
        {
            help();
        }
        if (func == 'a')
        {
            string addr;
            getline(cin, addr);
            if (addr.empty())
            {
                addr = "000";
            }
            assemble(addr, mem , pc);
        }
        if (func == 'd')
        {
            string range;
            getline(cin, range);
            if (range.empty())
            {
                range = "000";
            }
            dump_mem(mem, range);
        }
        if (func == 'e')
        {
            string addr;
            cin >> addr;
            edit(mem, addr);
        }
        if (func == 'u')
        {
            string addr;
            getline(cin, addr);
            if (addr.empty())
            {
                addr = "000";
            }
            unassemble(addr, mem);
        }
        if(func == 'r'){
            string regis;
            getline(cin, regis);
            if (regis.empty())
            {
                display(flag,reg,pc,sp);
            }
            else{
                displayOnlyreg(flag,reg,regis,pc,sp);
            }
        }
        if(func == 't'){
            string addr,text;
            getline(cin,addr);
            if(!addr.empty() && addr.length() == 4){
                pc = htod(addr[1]) * 256 + htod(addr[2]) * 16 + htod(addr[3]);
                text = addr.substr(1,3);
            }
            execution(flag,reg,mem,pc,sp);
            unassemble_next(pc,mem);
            display(flag,reg,pc,sp);
        }
        if(func == 'g'){
            string addr,text;
            getline(cin,addr);
            pc = htod(addr[0]) * 256 + htod(addr[1]) * 16 + htod(addr[2]);
            while(mem_of_pc(mem,pc) != 0x76){
                execution(flag,reg,mem,pc,sp);
                // display(flag,reg,pc,sp);
            }
            display(flag,reg,pc,sp);
        }
        cout << "-";
        cin >> func;
    }
    return 0;
}
