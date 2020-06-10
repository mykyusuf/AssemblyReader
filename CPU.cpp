#include "CPU.h"
#include "Memory.h"

//Register ve pc initilizationları

CPU::CPU(string option) {
    
    R1=0;
    R2=0;
    R3=0;
    R4=0;
    R5=0;
    PC=1;
    size=0;
    opt=convert(option);
    
}
CPU::CPU(){}

//Register atama fonksiyonları (setter)
int CPU::convert( string arr ){
    
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

void CPU::setR1(const int deger){
    R1=deger;
}
void CPU::setR2(const int deger){
    R2=deger;
}
void CPU::setR3(const int deger){
    R3=deger;
}
void CPU::setR4(const int deger){
    R4=deger;
}
void CPU::setR5(const int deger){
    R5=deger;
}

//Register degerlerine ulasma fonksiyonları (getter)

int CPU::getR1(){
    return R1;
}
int CPU::getR2(){
    return R2;
}
int CPU::getR3(){
    return R3;
}
int CPU::getR4(){
    return R4;
}
int CPU::getR5(){
    return R5;
}

//Program Counter setter

void CPU::setPC(int deger){
    PC=deger;
}

//Program counter getter

int CPU::getPC(){
    return PC;
}

//Registerları ve PC degerini ekrana yazdıran fonksiyon

void CPU::print(){
    cout<<"CPU Register Values:"<<endl;
    cout<<"[1] ->"<<R1<<"\n[2] ->"<<R2<<"\n[3] ->"<<R3<<"\n[4] ->"<<R4<<"\n[5] ->"<<R5<<"\nPC ->"<<PC<<endl;
}

//HLT komutunun girilip girilmediğini kontrol eden fonksiyon

bool CPU::halted(){
    if(command=="HLT")
        return true;
    else
        return false;
    
}

//İnstruction komutlarını alıp gerekli işlemi yapan fonksiyon

void CPU::execute(string str, Memory& m){
    
    int x,y,z,t,r,p,wr=0,M,K,L,H;
    int top=0,i,j=1,k,minus=0;
    string yer,yer2,tutucu,strtut,strsay;
        
    strtut=str;
    
    if(str=="HLT")
        command="HLT", halted();
    
    x=str.find("MOV");
    y=str.find("ADD");
    z=str.find("SUB");
    t=str.find("JMP");
    r=str.find("PRN");
    p=str.find("JPN");
    
    
    // HW1 deki instruction işlemleri (yorumlarını tekrar yazmadım)
    
    if(x>=0){
        strtut.erase(x,3);
        x=str.find("R");
        
        if(x!=-1){
            
            yer=str[x];
            yer+=str[x+1];
            K=str.rfind("R");
            H=str.find("#");
            if(K>x){
                yer2=str[K];
                yer2+=str[K+1];

                if(yer=="R1"){
                    
                    M=strtut.find("R");
                    strtut.erase(M,2);
                    
                    L=strtut.rfind("R");                    
                    
                    if(yer2=="R1"){
                        setR1(getR1());
                        strtut.erase(L,2);
                    
                    }
                
                    else if(yer2=="R2"){
                        setR2(getR1());
                        strtut.erase(L,2);
                    }
                
                    else if(yer2=="R3"){
                        setR3(getR1());
                        strtut.erase(L,2);
                    }
                    
                    else if(yer2=="R4"){
                        setR4(getR1());
                        strtut.erase(L,2);
                    }

                    else if(yer2=="R5"){
                        setR5(getR1());
                        strtut.erase(L,2);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R2"){
                    
                    M=strtut.find("R");
                    strtut.erase(M,2);
                    
                    L=str.rfind("R");

                    
                    if(yer2=="R1"){
                        setR1(getR2());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R2"){
                        setR2(getR2());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R3"){
                        setR3(getR2());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R4"){
                        setR4(getR2());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R5"){
                        setR5(getR2());
                        strtut.erase(L,2);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R3"){
                    
                    M=strtut.find("R");
                    strtut.erase(M,2);
                    
                    L=str.rfind("R");

                    
                    if(yer2=="R1"){
                        setR1(getR3());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R2"){
                        setR2(getR3());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R3"){
                        setR3(getR3());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R4"){
                        setR4(getR3());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R5"){
                        setR5(getR3());
                        strtut.erase(L,2);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R4"){
                    
                    M=strtut.find("R");
                    strtut.erase(M,2);
                    
                    L=str.rfind("R");

                    if(yer2=="R1"){
                        setR1(getR4());
                        strtut.erase(L,2);
                    }
                
                    else if(yer2=="R2"){
                        setR2(getR4());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R3"){
                        setR3(getR4());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R4"){
                        setR4(getR4());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R5"){
                        setR5(getR4());
                        strtut.erase(L,2);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R5"){

                    M=strtut.find("R");
                    strtut.erase(M,2);
                    
                    L=strtut.rfind("R");

                    if(yer2=="R1"){
                        setR5(getR5());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R2"){
                        setR5(getR5());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R3"){
                        setR5(getR5());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R4"){
                        setR5(getR5());
                        strtut.erase(L,2);
                    }
                    else if(yer2=="R5"){
                        setR5(getR5());
                        strtut.erase(L,2);

                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else
                    cerr<<"Wrong Command\n";

                for (int i=0; i!=strtut.size(); i++) {
                    if(strtut[i]!=32 && strtut[i]!=44)
                        wr+=1;
                }
                if(wr!=0)
                    command="HLT",halted();
                
            }
            else if(H!=-1){
                for(i=H+1;(str[i]<=57 && str[i]>=48);i++){
                    strsay+=str[i];
                }
                HASH=convert(strsay);
                if(yer=="R1"){
                    if(x<H)
                        m.setMem(HASH,R1);
                    else
                        m.setMem2(R1,HASH);
                }
                else if(yer=="R2"){
                    if(x<H)
                        m.setMem(HASH,R2);
                    else
                        m.setMem2(R2,HASH);
                }
                else if(yer=="R3"){
                    if(x<H)
                        m.setMem(HASH,R3);
                    else
                        m.setMem2(R3,HASH);
                }
                else if(yer=="R4"){
                    if(x<H)
                        m.setMem(HASH,R4);
                    else
                        m.setMem2(R4,HASH);
                }
                else if(yer=="R5"){
                    if(x<H)
                        m.setMem(HASH,R5);
                    else
                        m.setMem2(R5,HASH);
                }
            }
            else{
                for(K=x+2; !(str[K]<=57 && str[K]>=48);K++);
                for(i=K;(str[i]<=57 && str[i]>=48);i++){
                    tutucu+=str[i];
                }
                if(str[K-1]==45)
                    minus=1;
                
                for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                for( j=i-1,k=0 ; j>=0; j--,k++){
        
                    top += ( (tutucu[k]-'0') * pow(10,j) );
                    
                }
                 
                if(minus==1)
                    top=(-top);
                                
                if(yer=="R1")
                    setR1(top);
                else if(yer=="R2")
                    setR2(top);
                else if(yer=="R3")
                    setR3(top);
                else if(yer=="R4")
                    setR4(top);
                else if(yer=="R5")
                    setR5(top);
                else
                    cerr<<"Wrong Command\n";
            }
               
            
        }
        else if(x==-1){
            
            H=str.find("#");
            strsay.clear();
            
            if(H!=-1){
                
                for(i=H+1;(str[i]<=57 && str[i]>=48);i++){
                    strsay+=str[i];
                }
                HASH=convert(strsay);
                
                for(j=i+2;!(str[j]<=57 && str[j]>=48);j++);
                for(i=j;(str[i]<=57 && str[i]>=48);i++){
                    
                    strsay+=str[i];
                    
                }
                
                if(str[j-1]==45)
                    top=(-top);
                
                top=convert(strsay);
                cout<<top;
                m.setMem(HASH,top);
               
            }
            else
                cerr<<"Wrong Command", command="HLT",halted();
            
        }
        
    }
        
    else if(y>=0){
        
        y=str.find("R");
        
        if(y!=-1){
            
            yer=str[y];
            yer+=str[y+1];
            K=str.rfind("R");
            H=str.find("#");
            if(K>y){
                yer2=str[K];
                yer2+=str[K+1];
                
                if(yer=="R1"){
                    
                    if(yer2=="R1"){
                        k=R1+R1;
                        setR1(k);
                    }
                    else if(yer2=="R2"){
                        k=R1+R2;
                        setR1(k);
                    }
                    else if(yer2=="R3"){
                        k=R1+R3;
                        setR1(k);
                    }
                    else if(yer2=="R4"){
                        k=R1+R4;
                        setR1(k);
                    }
                    else if(yer2=="R5"){
                        k=R1+R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R2"){
                    
                    if(yer2=="R1"){
                        k=R2+R1;
                        setR1(k);
                    }
                        
                    else if(yer2=="R2"){
                        k=R2+R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R2+R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R2+R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R2+R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R3"){
                    
                    if(yer2=="R1"){
                        k=R3+R1;
                        setR1(k);
                    }
                        
                    else if(yer2=="R2"){
                        k=R3+R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R3+R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R3+R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R3+R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R4"){
                    
                    if(yer2=="R1"){
                        k=R4+R1;
                        setR1(k);
                    }
                
                    else if(yer2=="R2"){
                        k=R4+R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R4+R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R4+R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R4+R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R5"){
                    
                    if(yer2=="R1"){
                        k=R5+R1;
                        setR1(k);
                    }
                
                    else if(yer2=="R2"){
                        k=R5+R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R5+R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R5+R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R5+R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else
                    cerr<<"Wrong Command\n";

                
                
            }
            else if(H!=-1){
                for(i=H+1;(str[i]<=57 && str[i]>=48);i++){
                    strsay+=str[i];
                }
                HASH=convert(strsay);
                if(yer=="R1"){
                    if(x<H)
                        m.setMem5(R1,HASH);
                   
                }
                else if(yer=="R2"){
                    if(x<H)
                        m.setMem5(R2,HASH);
                   
                }
                else if(yer=="R3"){
                    if(x<H)
                        m.setMem5(R3,HASH);
                   
                }
                else if(yer=="R4"){
                    if(x<H)
                        m.setMem5(R4,HASH);
                   
                }
                else if(yer=="R5"){
                    if(x<H)
                        m.setMem5(R5,HASH);
                   
                }
            }
            
            else{
                for(K=y+2; !(str[K]<=57 && str[K]>=48);K++);
                for(i=K;(str[i]<=57 && str[i]>=48);i++){
                    tutucu+=str[i];
                }
                for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                for( j=i-1,k=0 ; j>=0; j--,k++){
        
                    top += ( (tutucu[k]-'0') * pow(10,j) );
        
                }
                 
                if(yer=="R1")
                    k=R1+top, setR1(k);
                else if(yer=="R2")
                    k=R2+top, setR2(k);
                else if(yer=="R3")
                    k=R3+top, setR3(k);
                else if(yer=="R4")
                    k=R4+top, setR4(k);
                else if(yer=="R5")
                    k=R5+top, setR5(k);
                else
                    cerr<<"Wrong Command\n";
            }
               
            
        }
        
    }     
       
    else if(t>=0){
        
        t=str.find("R");
        if(t!=-1){
            tutucu.clear();
            yer=str[t];
            yer+=str[t+1];
            
            if(yer=="R1"){
                if(R1==0){
                    for(i=t+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }  
            else if(yer=="R2"){
                if(R2==0){
                    for(i=t+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }  
            else if(yer=="R3"){
                if(R3==0){
                    for(i=t+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }  
            else if(yer=="R4"){
                if(R4==0){
                    for(i=t+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }  
            else if(yer=="R5"){
                if(R5==0){
                    for(i=t+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }  
           
            
            
        }
        else{
            
            for(i=r+2;!(str[i]>=48 && str[i]<=57);i++);
                    
            for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                    tutucu+=str[j];
                        
            }
            for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
  
            for( j=i-1,k=0 ; j>=0; j--,k++){
        
                    top += ( (tutucu[k]-'0') * pow(10,j) );
        
            }
                 
            setPC(top-1);
            
            
        }
        
        
        
    }
    else if(r>=0){
        r=str.rfind("R");
        if(r!=-1){
            
            yer=str[r];
            yer+=str[r+1];
            
            if(yer=="R1")
                cout<<"R1="<<R1<<endl;
            else if(yer=="R2")
                cout<<"R2="<<R2<<endl;
            else if(yer=="R3")
                cout<<"R3="<<R3<<endl;
            else if(yer=="R4")
                cout<<"R4="<<R4<<endl;
            else if(yer=="R5")
                cout<<"R5="<<R5<<endl;
        }
        else
            cerr<<"Wrong Command\n";
    }
    else if(z>=0){
        
        z=str.find("R");
        H=str.find("#");
        if(z!=-1){
            
            yer=str[z];
            yer+=str[z+1];
            K=str.rfind("R");
            if(K>z){
                yer2=str[K];
                yer2+=str[K+1];
                
                if(yer=="R1"){
                    
                    if(yer2=="R1"){
                        k=R1-R1;
                        setR1(k);
                    }
                    else if(yer2=="R2"){
                        k=R1-R2;
                        setR1(k);
                    }
                    else if(yer2=="R3"){
                        k=R1-R3;
                        setR1(k);
                    }
                    else if(yer2=="R4"){
                        k=R1-R4;
                        setR1(k);
                    }
                    else if(yer2=="R5"){
                        k=R1-R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R2"){
                    
                    if(yer2=="R1"){
                        k=R2-R1;
                        setR1(k);
                    }
                        
                    else if(yer2=="R2"){
                        k=R2-R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R2-R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R2-R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R2-R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R3"){
                    
                    if(yer2=="R1"){
                        k=R3-R1;
                        setR1(k);
                    }
                        
                    else if(yer2=="R2"){
                        k=R3-R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R3-R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R3-R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R3-R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else if(yer=="R4"){
                    
                    if(yer2=="R1"){
                        k=R4-R1;
                        setR1(k);
                    }
                
                    else if(yer2=="R2"){
                        k=R4-R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R4-R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R4-R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R4-R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                   
                    
                }
                else if(yer=="R5"){
                    
                    if(yer2=="R1"){
                        k=R5-R1;
                        setR1(k);
                    }
                
                    else if(yer2=="R2"){
                        k=R5-R2;
                        setR1(k);
                    }
                
                    else if(yer2=="R3"){
                        k=R5-R3;
                        setR1(k);
                    }
                    
                    else if(yer2=="R4"){
                        k=R5-R4;
                        setR1(k);
                    }

                    else if(yer2=="R5"){
                        k=R5-R5;
                        setR1(k);
                    }
                    else
                        cerr<<"Wrong Command\n";
                    
                }
                else
                    cerr<<"Wrong Command\n";

                
                
            }
            else if(H!=-1){
                
                for(i=H+1;(str[i]<=57 && str[i]>=48);i++){
                    strsay+=str[i];
                }
                HASH=convert(strsay);
                if(yer=="R1"){
                    if(z<H)
                        m.setMem4(R1,HASH);
                }
                else if(yer=="R2"){
                    if(z<H)
                        m.setMem4(R2,HASH);

                }
                else if(yer=="R3"){
                    if(z<H)
                        m.setMem4(R3,HASH);
                }
                else if(yer=="R4"){
                    if(z<H)
                        m.setMem4(R4,HASH);

                }
                else if(yer=="R5"){
                    if(z<H)
                        m.setMem4(R5,HASH);

                }
                              
                
            }
            
            else{
                for(K=z+2; !(str[K]<=57 && str[K]>=48);K++);
                for(i=K;(str[i]<=57 && str[i]>=48);i++){
                    tutucu+=str[i];
                }
                for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                for( j=i-1,k=0 ; j>=0; j--,k++){
        
                    top += ( (tutucu[k]-'0') * pow(10,j) );
        
                }
                 
                if(yer=="R1")
                    k=R1-top, setR1(k);
                else if(yer=="R2")
                    k=R2-top, setR2(k);
                else if(yer=="R3")
                    k=R3-top, setR3(k);
                else if(yer=="R4")
                    k=R4-top, setR4(k);
                else if(yer=="R5")
                    k=R5-top, setR5(k);
                else
                    cerr<<"Wrong Command\n";
            }
               
            
        }
        
    }
    else if(p>=0){
        
        y=str.find("R");
        
        if(y!=-1){
            
            yer=str[y];
            yer+=str[y+1];
            
            if(yer=="R1"){
                if(R1<=0){
                    
                    for(i=y+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }
            else if(yer=="R2"){
                if(R2<=0){
                    
                    for(i=y+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }
            else if(yer=="R3"){
                if(R3<=0){
                    
                    for(i=y+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }
            else if(yer=="R4"){
                if(R4<=0){
                    
                    for(i=y+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }
            else if(yer=="R5"){
                if(R5<=0){
                    
                    for(i=y+2;!(str[i]>=48 && str[i]<=57);i++);
                    
                    for(j=i;(str[j]<=57 && str[j]>=48);j++){
                        
                        tutucu+=str[j];
                        
                    }
                    for( i=0 ; tutucu[i]>=48 && tutucu[i]<=57 ; i++);
    
                    for( j=i-1,k=0 ; j>=0; j--,k++){
        
                       top += ( (tutucu[k]-'0') * pow(10,j) );
        
                    }
                    setPC(top-1);
                }
            }
        }
        
    }
    PC+=1;

}
