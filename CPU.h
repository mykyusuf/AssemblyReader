#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <math.h>
#include "Memory.h"


using namespace std;

class CPU {
public:
    CPU(string option);
    CPU();


    int size,HASH;
    string command;
    
    int convert( string arr );
    
    //Setterlar
    
    void setR1(int deger);
    void setR2(int deger);
    void setR3(int deger);
    void setR4(int deger);
    void setR5(int deger);
    void setPC(int deger);
    
    //getterlar
    
    int getR1();
    int getR2();
    int getR3();
    int getR4();
    int getR5();
    int getPC();
    
    void print();
    bool halted();
    void execute(string str, Memory& m);
    
private:
    
    int R1,R2,R3,R4,R5;
    int PC,opt;
    
};

#endif /* CPU_H */

