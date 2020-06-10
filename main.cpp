/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MacbookPro
 *
 * Created on 06 Kasım 2016 Pazar, 18:45
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include "CPU.h"
#include "CPUProgram.h"
#include "Memory.h"
#include "Computer.h"

using namespace std;

int main(int argc, char** argv) {

    //txt ve işlem tercihini parametre olarak stringe atadık
    
    string txt;
    string opt;
    
    txt=argv[1];
    opt=argv[2];
    
    Memory memo;
    
    CPUProgram x(txt);
    
    CPU y(opt);

    Computer com(y , x , memo , opt);
            
    com.execute();
    
    cout<<x[5];
    
    return 0;

}

