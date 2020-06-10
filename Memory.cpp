/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memory.cpp
 * Author: MacbookPro
 * 
 * Created on 06 Kasım 2016 Pazar, 18:47
 */

#include "Memory.h"

Memory::Memory(){
    
    for(int i=0;i<50;i++)
        myk[i]=0;
    
}
Memory::Memory(int x){
    option=x;
}
int Memory::getMem(int x){
    
    return myk[x];
    
}
void Memory::setMem(int x, int y){
    
    myk[x]=y;
}
void Memory::setMem2(int& x, int y){
    
    x=myk[y];

}
void Memory::setMem3(int x, int y){
    
    myk[x]+=y;

}
void Memory::setMem4(int& x, int y){
    
    x-=myk[y];

}
void Memory::setMem5(int& x, int y){
    
    x+=myk[y];

}

void Memory::printAll(){
    
    cout<<"Memory Values:\n";
    
    for(int i=0;i<50;i++){
        
        cout<<"["<<i<<"] -> "<< myk[i]<<endl;
        
    }
    
    
}

