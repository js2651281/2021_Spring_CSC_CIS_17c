/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Table.h"

//Function Implementations
Table::Table(int rows, int cols){
    //Initialize variables
    szRow = rows;
    szCol = cols;
    
    //Allocate memory for **records
    records = new RowAray*[cols];
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            records[i] = new RowAray(szCol);
        }
    }
    //Fill table
    fillTable();
}

Table::~Table(){
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            delete records[i];
        }
    }
    delete []records;
}

int Table::getData(int row, int col){
    return records[row]->getData(col);
}

void Table::fillTable(){
    //Fill the table with random #'s using RowAray's fillRow()
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            records[i]->fillRow();
        }
    }
}