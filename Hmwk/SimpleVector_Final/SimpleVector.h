/*
* File:   SimpleVector.h
 * Author: rcc
 *
 * Created on September 16, 2020, 8:10 PM
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   // Push a value into the back of an array, i.e. Resize, Copy, and Add the value
   void push_back(T);
   void push_front(T);
   void pop_back();
   void pop_front();
   
   // Push a value into the beginning of an array
};

//***********************************************************
// push_back function. Creates a new array, copies the old  *
// array, adds a new value then deletes the old array.      *
//***********************************************************

template <class T>
void SimpleVector<T>::push_back(T val)
{
    
    //Create an array 1 size larger than the old array
    T *naptr;
    int nArraySize = 1 + this->arraySize;
    naptr = new T[nArraySize];
    //Copy the old array in to the new
    for(int i = 0; i<arraySize; i++)
        *(naptr + i) = *(aptr + i);
        
    //Place the new value at the end of the new array
    *(naptr + arraySize) = val;

    //Delete the old array
    delete []aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //the new array pointer
    arraySize = nArraySize;
    aptr = new T[nArraySize];
    aptr = naptr;
     
}

//***********************************************************
// push_front function. Creates new array, copies the old   *
// array, adds a new value then deletes the old array.      *
//***********************************************************

template <class T>
void SimpleVector<T>::push_front(T val)
{
    //Create an array 1 size larger than the old array
    T *naptr;
    int nArraySize = 1 + this->arraySize;
    naptr = new T[nArraySize];
    
    //Copy the old array in to the new, starting with i=1
    for(int i = 0; i<arraySize; i++)
        *(naptr + i+1) = *(aptr + i);
        
    //Place the new value at the beginning of the new array
    *(naptr + 0) = val;
    
    //Delete the old array
    delete []aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //the new array pointer
    arraySize = nArraySize;
    aptr = new T[nArraySize];
    aptr = naptr;
    
}

//***********************************************************
// pop_back function. Creates new array with size n-1,      *
// Copies the old array, excluding the value at n. Deletes  *
// the old array.
//***********************************************************
template <class T>
void SimpleVector<T>::pop_back()
{
    //Create an array 1 size smaller than the old array
    T *naptr;
    int nArraySize = this->arraySize - 1;
    naptr = new T[nArraySize];
    
    //Copy the old array in to the new, excluding the last value
    for(int i = 0; i<nArraySize; i++)
        *(naptr + i) = *(aptr + i);
    
    //Delete the old array
    delete []aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //the new array pointer
    arraySize = nArraySize;
    aptr = new T[nArraySize];
    aptr = naptr;
        
}

//***********************************************************
// pop_front function. Creates new array with size n-1,     *
// Copies the old array, excluding the value at 0. Deletes  *
// the old array.                                           *
//***********************************************************
template <class T>
void SimpleVector<T>::pop_front()
{
    //Create an array 1 size smaller than the old array
    T *naptr;
    int nArraySize = this->arraySize - 1;
    naptr = new T[nArraySize];
    
    //Copy the old array in to the new, excluding the first value
    for(int i = 0; i<nArraySize; i++)
        *(naptr + i) = *(aptr + i + 1);
    
    //Delete the old array
    delete []aptr;
    
    //Increment the array size by 1 and set the old pointer to 
    //the new array pointer
    arraySize = nArraySize;
    aptr = new T[nArraySize];
    aptr = naptr;
        
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif