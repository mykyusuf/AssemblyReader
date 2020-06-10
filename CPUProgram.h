#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>

#include <fstream>

using namespace std;

class CPUProgram {
public:
        
    CPUProgram(string myk);
    CPUProgram(int option);
    CPUProgram();
    int size();
    int sayz;
    string getLine(int x);
    string &operator[](int i){
        
        return array[i-1];
        
    }
    
private:
    
    string array[250];
    int opt;
    void ReadFile(string myk);
    
};

#endif /* CPUPROGRAM_H */

