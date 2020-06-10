#include "CPUProgram.h"

//Class constructerı çağrılınca readfile fonk çağırır

CPUProgram::CPUProgram(string myk) {

    ReadFile(myk);
    
}

//Dosya okuma fonksiyonu, okudugunu string arraye atar
CPUProgram::CPUProgram(int option) {

    opt=option;
    
}
CPUProgram::CPUProgram(){}
void CPUProgram::ReadFile(string myk){
    
    ifstream tut;
    
    tut.open(myk);
    
    for(int i=0;tut;i++){
        getline(tut,array[i]);
        sayz=i;
    }
    
    tut.close();
    
}

//İstenen satıra geri döner
   
string CPUProgram::getLine(int x){
    
    if(x>0)
        return array[x-1];
    else
        return "wrong command";
        
}

//Dosya boyutunu tutar

int CPUProgram::size(){

    return sayz;

}
