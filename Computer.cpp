/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Computer.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2016 Pazar, 18:47
 */

#include "Computer.h"

Computer::Computer(CPU a, CPUProgram b, Memory m, string option){

    y=a;
    x=b;
    memo=m;
    opt= convert(option);

}
Computer::Computer(string option){
    
    opt=convert(option);
    
}
int Computer::convert(string arr){
        
    int k,i,top=0,j,minus=0;
    
    if(arr[0]==45){
        arr.erase(0,1);
        minus=1;
    }
    for( i=0 ; arr[i]>=48 && arr[i]<=57 ; i++);
    
    for( j=i-1,k=0 ; j>=0; j--,k++){
        
        top += ( (arr[k]-'0') * pow(10,j) );
        
    }
    if(minus==1)
        top=(-top);
    
    return top;
    
}

CPU Computer::getCpu(){
    
    return y;
    
}

void Computer::setCpu(CPU c){
    
    y=c;
    
}
void Computer::setCpuProg(CPUProgram cp){
    
    x=cp;
    
}
CPUProgram Computer::getCpuProg(){
    
    return x;
    
}
void Computer::setMem(Memory mem){
    
    memo=mem;
    
}
Memory Computer::getMem(){
    
    return memo;
    
}