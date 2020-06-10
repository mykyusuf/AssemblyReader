/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memory.h
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2016 Pazar, 18:47
 */

#ifndef MEMORY_H
#define MEMORY_H
#include <string>
#include <iostream>
using namespace std;


class Memory {
public:
    Memory();
    Memory(int x);
    void setMem(int x, int y);
    void setMem3(int x, int y);
    void setMem4(int& x, int y);
    void setMem2(int& x, int y);
    void setMem5(int& x, int y);
    int getMem(int x);
    void printAll();
    
private:
    unsigned int myk[50];
    int option;
};

#endif /* MEMORY_H */

