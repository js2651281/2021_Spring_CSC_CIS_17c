template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template <class T>
RowAray<T>::RowAray(int szRow){
    //Set size and allocate memory for *rowData
    size = szRow;
    rowData = new T(size);
    
    //Set data for row
    for(int i=0; i<size; i++){
        setData(i, rand()%99+1);
    }
}

template <class T>
RowAray<T>::~RowAray(){
    delete rowData;
}

template <class T>
void RowAray<T>::setData(int col, T num){
    rowData[col] = num;
}
