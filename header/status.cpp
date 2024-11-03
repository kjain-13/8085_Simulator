#include <iostream>
using namespace std;

void displayFlags(bool (&flag)[8]){
    (flag[7])? cout << "NG " : cout << "PL " ;
    (flag[6])? cout << "Z " : cout << "NZ " ;
    (flag[4])? cout << "AC " : cout << "NA " ;
    (flag[2])? cout << "PE " : cout << "PO " ;
    (flag[0])? cout << "C " : cout << "NC " ;
}

void display(bool (&flag)[8] , int (&reg)[7] , int pc , int sp){
    cout << "A=" << reg[0]  << " B=" << reg[1] << " C=" << reg[2] << " D=" << reg[3] << " E=" << reg[4] << " H=" << reg[5] << " L=" << reg[6] << " PC=" << hex << pc  << " SP=" << hex << sp << endl;
    displayFlags(flag);  
    cout << endl;
} 
void displayOnlyreg(bool (&flag)[8] , int (&reg)[7] ,string& s ,int& prg , int sp){
    if(s == "a" || s == "A"){
        cout << hex << reg[0] << ".";
        cin >> hex >> reg[0];
    }
    if(s == "b" || s == "B"){
        cout << hex << reg[1] << ".";
        cin >> hex >> reg[1];
    }
    if(s == "c" || s == "C"){
        cout << hex << reg[2] << ".";
        cin >> hex >> reg[2];
    }
    if(s == "d" || s == "D"){
        cout << hex << reg[3] << ".";
        cin >> hex >> reg[3];
    }
    if(s == "e" || s == "E"){
        cout << hex << reg[4] << ".";
        cin >> hex >> reg[4];
    }
    if(s == "h" || s == "H"){
        cout << hex << reg[5] << ".";
        cin >> hex >> reg[5];
    }
    if(s == "l" || s == "L"){
        cout << hex << reg[6] << ".";
        cin >> hex >> reg[6];
    }
    if(s == "pc" || s == "PC"){
        cout << hex << prg << "."; 
        cin >> hex >> prg;
    }
    if(s == "sp" || s == "SP"){
        cout << hex << sp;
    }
    if(s == "f" || s == "F"){
        displayFlags(flag);
        cout << "-";
        cin >> flag[7];
        cin >> flag[6];
        cin >> flag[4];
        cin >> flag[2];
        cin >> flag[0];
    }
}
