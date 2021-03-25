/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RowAray.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

//Function Implementations
RowAray::RowAray(int cols){
    //Initialize variables
    size = cols;
    rowData = new int[size];
    
    //Fill rows
    fillRow();
}

RowAray::~RowAray(){
    delete rowData;
}

void RowAray::fillRow(){
    //Fill the row with random #'s
    for(int i=0; i<size; i++){
        rowData[i] = rand()%99+1; //2 digit #'s, up to 99
    }
}