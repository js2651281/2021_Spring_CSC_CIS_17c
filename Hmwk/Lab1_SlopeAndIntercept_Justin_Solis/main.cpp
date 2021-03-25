/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Justin Solis
 *
 * Created on March 17, 2021, 1:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    float sX = 0, sX2 = 0;
    float sY = 0.0, sXsY = 0.0, sYX = 0.0;
    float nSYX, nSX2;
    
    int size = 37;
    float x[size];
    float y[size];
    fstream file;
    
    //Open Data1.txt
    file.open("Data1.txt", ios::in);
    
    //Output x's and y's
    int i = 0;
    cout<<"x     y"<<endl;
    while(file >> x[i] >> y[i])
    {
        cout<< x[i] << "    " << y[i] << endl;
        i++;
    }
    
    file.close();
    
    //Find S_x
    for(int i=0; i<size; i++){
        sX += x[i];
    }
    
    //Find S_Y
    for(int i=0; i<=size; i++){
        sY += y[i];
    }
    
    //Find S_x*S_y
    sXsY = sX*sY;

    //Find N*S_(yx)
    for(int i=0; i<size; i++){
        sYX += x[i]*y[i];
    }
    nSYX = size * sYX;

    //Find (S_x^2)
    for(int i=0; i<size; i++){
        sX2 += x[i]*x[i];
        //cout<<x[i]<<" * "<<y[i]<<endl;
    }
    
    //Find N*S_(x^2)
    nSX2 = size * sX2;

    //Find m and b
    float slope, intercept;
    
    slope = (sX*sY - nSYX)/(sX*sX - nSX2);
    intercept = (sY - slope*sX)/size;

    //Output results
    cout<<"\nsX: "<<sX<<"\nsY: "<<sY;
    cout<<"\nsXsY: "<<sXsY;
    cout<<"\nsYX: "<<sYX;
    cout<<"\nsX2: "<<sX2;
    cout<<"\n\nSlope: "<<slope<<endl;
    cout<<"Intercept: "<<intercept<<endl;
    return 0;
}

