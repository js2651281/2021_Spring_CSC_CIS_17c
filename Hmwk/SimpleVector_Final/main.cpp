/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 16, 2020, 7:50 PM
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<unsigned char> &);
void prntVec(SimpleVector<unsigned char> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned char size=200;
    unsigned int nPush=1;
    SimpleVector<unsigned char> sv(size);
    
    //Fill the Vector
    fillVec(sv);
    
    //Print the Vector
    cout<<"Original Vector:";
    prntVec(sv,10);
    
    //Push a random value into the back of the array
    for(int i=1;i<=nPush;i++){
        sv.push_back(rand()%26+65);
    }
    
    //Print the Vector
    cout<<"push_back:";
    prntVec(sv,10);
    
    //Push a random value into the front of the array
    for(int i=1;i<=nPush;i++){
        sv.push_front(rand()%26+65);
    }
    
    //Print the Vector
    cout<<"\npush_front:";
    prntVec(sv,10);
    
    //Pop the last value from the array
    sv.pop_back();
    
    //Print the Vector
    cout<<"\npop_back:";
    prntVec(sv,10);
    
    //Pop the first value from the array
    sv.pop_front();
    
    //Print the Vector
    cout<<"\npop_front:";
    prntVec(sv,10);
    
    //Copy the Vector
    SimpleVector<unsigned char> copysv(sv);
    
    //Print the Vector
    cout<<"Final Vector:";
    prntVec(copysv,10);

    return 0;
}

void prntVec(SimpleVector<unsigned char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<unsigned char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}

