/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Computer.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2016 Pazar, 18:47
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include "CPU.h"
#include "CPUProgram.h"



class Computer {
public:
    void setCpu(CPU c);
    CPU getCpu();
    void setCpuProg(CPUProgram cp);
    CPUProgram getCpuProg();
    void setMem(Memory mem);
    Memory getMem();
    Computer(CPU a , CPUProgram b , Memory m , string option);
    Computer(string option);
    
    int convert(string arr);
    
    void execute(){
        while(!y.halted()){

    // İnstructionları alarak gerekli executionları yapar
        
        string instruction = x.getLine(y.getPC());
        cout<<instruction<<endl;
        y.execute(instruction,memo);
        
    // OPT 1 ise her execute sonunda register değerlerini yazdırır
      
     
            if(opt==1){
                y.print();
                memo.printAll();
            }
        }
    }
    
private:
    CPU y;
    Memory memo;
    CPUProgram x;
    int opt;

};

#endif /* COMPUTER_H */

