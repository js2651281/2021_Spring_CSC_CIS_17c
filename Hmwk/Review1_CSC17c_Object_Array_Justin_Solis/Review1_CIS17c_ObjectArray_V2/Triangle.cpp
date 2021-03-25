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
    
    //Allocate memory for *cols and *indx
    cols = new int(rand()%9+1);
    indx = new int(szRow);
    
    //Fill cols
    fillCols();
    
    //Fill index
    fillIndx();
    
    //Allocate memory for **records
    records = new RowAray*[szRow];
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szRow; j++){
            records[i] = new RowAray(cols[i]);
        }
    }
    
    //Fill Triangle
    fillTri();
    
    //Sort Triangle
    mrkSort();
}

Triangle::~Triangle(){
    delete cols;
    delete indx;
    delete records;
}

int Triangle::getData(int row, int col){
    return records[row]->getData(col);
}

void Triangle::fillTri(){
    //Fill triangle
    for(int i=0; i<szRow; i++){
        for(int j=0; j<cols[i]; j++){
            records[i]->fillRow();
        }
    }
}

void Triangle::fillIndx(){
    //Fill the index
    for(int i=0; i<szRow; i++){
        indx[i] = i;
    }
}

void Triangle::fillCols(){
    //Fill cols
    for(int i=0; i<szRow; i++){
        cols[i] = rand()%9+1;
    }
}

void Triangle::mrkSort(){
    for(int pos=0; pos<szRow-1; pos++){
        for(int first=pos+1; first<szRow; first++){
            if(cols[indx[pos]] > cols[indx[first]]){
                indx[pos] = indx[pos]^indx[first];
                indx[first] = indx[pos]^indx[first];
                indx[pos] = indx[pos]^indx[first];
            }
        }
    }
}