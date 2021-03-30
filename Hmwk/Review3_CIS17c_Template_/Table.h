#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int rowSize, unsigned int colSize){
    //Set row & col size
    szRow = rowSize;
    szCol = colSize;
    
    //Allocate memory for **columns
    columns = new RowAray<T>*[szRow];
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i] = new RowAray<T>(szCol);
        }
    }
    
    //Set the table data
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i]->setData(j, rand()%99+1);
        }
    }
}

//Copy constructor
template<class T>
Table<T>::Table(const Table<T> &tab){
    //Set row & col size
    szRow = tab.getSzRow();
    szCol = tab.getSzCol();
    
    //Allocate memory for **columns
    columns = new RowAray<T>*[szRow];
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i] = new RowAray<T>(szCol);
        }
    }
    
    //Copy contents of &tab into columns
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            columns[i]->setData(j, tab.getData(i, j));
        }
    }
}

template<class T>
Table<T>::~Table(){
    for(int i=0; i<szRow; i++){
        delete columns[i];
    }
    delete columns;
}

template<class T>
T Table<T>::getData(int row, int col) const{
    return columns[row]->getData(col);
}

template<class T>
void Table<T>::setData(int curRow, int curCol, T num){
    columns[curRow]->setData(curCol, num);
}

template<class T>
Table<T> Table<T>::operator+(const Table<T> &tab){
    //Create a table to hold the added values
    Table addTab(szRow, szCol);
    
    //Cycle through the table and add each element original[i][j] + table[i][j]
    //Take result and put into addTab
    for(int i=0; i<szRow; i++){
        for(int j=0; j<szCol; j++){
            int add, n1, n2;
            n1 = columns[i]->getData(j);
            n2 = tab.getData(i, j);
            add = n1 + n2;
            
            addTab.setData(i, j, add);
        }
    }
    return addTab;
}