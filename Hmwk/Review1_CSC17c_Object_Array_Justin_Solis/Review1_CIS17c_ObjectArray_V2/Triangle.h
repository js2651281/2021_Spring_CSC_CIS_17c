/* 
 * File:   Triangle.h
 * Author: Dr. Mark E. Lehr
 * Created on January 22nd, 2020, 8:36 PM
 * Purpose:  Specification of a Triangular array from a Row Array
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "RowAray.h"

class Triangle{
    private:
        int szRow;
        int *cols;
        int *indx;
        RowAray **records;
        
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getCol(int i){return cols[i];}
        int getData(int,int);
        int getIndx(int curIndx){return indx[curIndx];}
        void fillIndx();
        void fillCols();
        void fillTri();
        void mrkSort();
};


#endif	/* TRIANGLE_H */

