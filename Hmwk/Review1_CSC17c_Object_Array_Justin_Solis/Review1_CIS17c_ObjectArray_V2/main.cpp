/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22nd, 2020, 8:36 PM
 * Purpose:  Dynamic Object Arrays
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//User Libraries
#include "Table.h"
#include "Triangle.h"

//Global Constants

//Function Prototype

void prntRow(RowAray *,int);
void prntTab(Table *);
void prntTri(Triangle *);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(NULL)));
   
   //Declare Variables
   int rows=6,cols=8,perLine=cols/2;
   
   //Test out the RowAray
   RowAray row(cols);
    
   //Print the RowAray
   cout<<"The Row Array size = "<<row.getSize()
           <<" printed "<<perLine<<" per Line";
   
   prntRow(&row,perLine);
   
   //Test out the Table
   Table tab(rows,cols);
   
   //Print the Table
   cout<<"The table size is [row,col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab); 
   
   //Test out the Triangular Table
   Triangle tri(rows);
   
   //Print the Triangular Table
   cout<<"The triangular table row amount = "<<tri.getSzRow()<<endl;
   cout<<"The triangular table column array = [";
   for(int i=0; i<tri.getSzRow(); i++){
       cout<<tri.getCol(i);
       if(i != tri.getSzRow() - 1)
           cout<<", ";
       else
           cout<<"]\n";
   }
   cout<<"The sorted triangular table column array = [";
   for(int i=0; i<tri.getSzRow(); i++){
       cout<<tri.getCol(tri.getIndx(i));
       if(i != tri.getSzRow() -1)
           cout<<", ";
       else
           cout<<"]";
   }
   prntTri(&tri);
   
   //Exit Stage Right
   return 0;
}

void prntRow(RowAray *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getCol(a->getIndx(row));col++){
            cout<<a->getData(a->getIndx(row),col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}