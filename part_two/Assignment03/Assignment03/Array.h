//
//  Array.h
//  Assignment03
//
//  Created by Paulo Amaral on 2015-02-11.
//
//  Template Array class interface file
//  This class stores any data type in a fixed-size
//  container whose size is specified when instantiated.

#ifndef Assignment03_Array_h
#define Assignment03_Array_h

#include <iostream>
#include <stdexcept>

template<class T = int, int size = 5>
class Array
{
public:
    // default ctor; increments the obj count
    Array<T, size>();
    // dtor; decrements the obj count
    ~Array<T, size>();
    // returns the current number of specialized objects
    static int getArrayCount();
    // inputs elements into the array
    void inputArray();
    // outputs elements from the array
    void outputArray() const;
    // returns the size of the underlying
    // data structure
    int getSize() const;
    // tests two arrays for equality
    bool operator==(const Array<T, size> &op) const;
    // tests two arrays for inequality
    bool operator!=(const Array<T, size> &op) const;
    // returns value at index
    const T& operator[](const int &index) const;
    // returns value at index
    T& operator[](const int &index);
private:
    // the default word delimiter
    const static char delimiter = ' ';
    // the default line delimiter
    const static char lineBreak = '\n';
    // range error message for class
    const static std::string outOfRangeError;
    // the current number of specialized objects
    static int arrayCount;
    // the underlying data structure
    T data[size];
};

#include "Array_inc.h"

#endif
