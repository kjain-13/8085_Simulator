#include <iostream>
#include <conio.h>
using namespace std;

void help(){
    cout << "asssemble       a[address]" << endl;
    cout << "quit            q" << endl;
    cout << "unassemble      u[range]" << endl;
    cout << "dump            d[range]" << endl;
    cout << "register        r[register]" << endl;
    cout << "trace           t[=address][value]" << endl;
    cout << "edit            e[address]" << endl;
    cout << "go              g[=address]" << endl;
}

int stoh(string s){
    int h,l;
    if(s[0] >= 'A' && s[0] <= 'F'){
        h = s[0]-'A'+10;
    }
    else if(s[0] >= 'a' && s[0] <= 'f'){
        h = s[0] - 'a' + 10;
    }
    else{
        h = s[0] - '0';
    }

    if(s[1] >= 'A' && s[1] <= 'F'){
        l = s[1]-'A'+10;
    }
    else if(s[1] >= 'a' && s[1] <= 'f'){
        l = s[1] - 'a' + 10;
    }
    else{
        l = s[1] - '0';
    }
    return h*16 + l;
}

int htod(char arg){
    if(arg >= '0' && arg <= '9'){
        return arg - '0';
    }
    if(arg >= 'A' && arg <= 'F'){
        return 10 + arg - 'A';
    }
    if(arg >= 'a' && arg <= 'f'){
        return 10 + arg - 'a';
    }
    return -1;
}

void dump_mem(int (&mem)[16][16][16] , string& name){
    for(int i = 0 ; i < name.size() ; i++){
        if(name[i] == ' '){
            name.erase(i,1);
            i--;
        }
    }
    if(name.length() > 3)return; // assuming only starting address given not a range
    int x,y,z;
    z = htod(name[0]);
    x = htod(name[1]);
    y = htod(name[2]);
    for(int i = 0 ; i <= 15 ; i++){
        for(int j = 0 ; j <= 15 ; j++){
            if(i > x || (j >= y && i == x)){
                if(mem[z][i][j] <= 15){
                    cout << "0"; // offset zero
                }
                cout << hex << mem[z][i][j] << " ";
                if(j == 7){
                    cout << "- ";
                }
            }
            else{
                cout << "__ "; // if we does not wish to see data
                if(j == 7){
                    cout << "- ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

void edit(int (&mem)[16][16][16] , string& addr){
    string input;
    int location = htod(addr[0])*256 + htod(addr[1])*16 + htod(addr[2]);
    cout << addr << " : " << mem[htod(addr[0])][htod(addr[1])][htod(addr[2])] << ".";
    cin >> input;
    if(input[0] == 34 ){
        for(int i = 1 ; i < input.size()-1 ; i++){
            mem[location/256][(location%256) / 16][(location%256)%16] = input[i]; 
            location++;
        }
    }
    else{
        mem[htod(addr[0])][htod(addr[1])][htod(addr[2])] = stoh(input);
    }
}