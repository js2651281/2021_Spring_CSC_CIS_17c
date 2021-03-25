/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
using namespace std;
#include "Triangle.h"

//Function Implementations
Triangle::Triangle(int rows){
    //Initialize variables
    szRow = rows;
    
    //Allocate memory for **records
    records = new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szRow; j++){
            records[i] = new RowAray(szRow);
        }
    }
    
    //Fill Triangle
    fillTri();
}

Triangle::~Triangle(){
    delete records;
}

int Triangle::getData(int row, int col){
    return records[row]->getData(col);
}

void Triangle::fillTri(){
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szRow; j++){
            records[i]->fillRow();
        }
    }
}