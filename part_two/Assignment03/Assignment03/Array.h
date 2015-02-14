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

/******************************************************
 * The following code implements the member functions *
 * of the Array template class. This class stores any *
 * data type in a fixed-size container whose size is  *
 * specified when instantiated.                       *
 ******************************************************/

// tracks the number of objects that currently
// exist in program
template<class T, int size>
int Array<T, size>::arrayCount = 0;

// range error message for class
template<class T, int size>
const std::string Array<T, size>::outOfRangeError = "Error: index is out of range";

// returns the number of objects that
// currently exist in program
template<class T, int size>
int Array<T, size>::getArrayCount()
{
    return Array::arrayCount;
}

// default ctor; increments the obj count
template<class T, int size>
Array<T, size>::Array()
{
    ++Array::arrayCount;
}

// dtor; decrements the obj count
template<class T, int size>
Array<T, size>::~Array()
{
    --Array::arrayCount;
}

// returns the size of the underlying
// data structure
template<class T, int size>
int Array<T, size>::getSize() const
{
    return size;
}

// tests two arrays for equality
template<class T, int size>
bool Array<T, size>::operator==(const Array<T, size> &op) const
{
    bool test = false;
    for (int i = 0; i < size; ++i) {
        if (this->data[i] == op[i]) {
            test = true;
            break;
        }
    }
    return test;
}

// tests two arrays for inequality
template<class T, int size>
bool Array<T, size>::operator!=(const Array<T, size> &op) const
{
    return !(*this == op);
}

// returns element at index
template<class T, int size>
const T & Array<T, size>::operator[](const int &index) const
{
    if(index >= 0 && index < size) {
        return this->data[index];
    } else {
        throw std::out_of_range(Array<T, size>::outOfRangeError);
    }
}

// returns element at index
template<class T, int size>
T& Array<T, size>::operator[](const int &index)
{
    if(index >= 0 && index < size) {
        return this->data[index];
    } else {
        throw std::out_of_range(Array<T, size>::outOfRangeError);
    }
}

// inputs elements into the array
template<class T, int size>
void Array<T, size>::inputArray()
{
    for (int i = 0; i < size; ++i) {
        std::cin >> this->data[i];
    }
}

// outputs elements from the array
template<class T, int size>
void Array<T, size>::outputArray() const
{
    for (int i = 0; i < size; ++i) {
        std::cout << this->data[i] << Array::delimiter;
    }
    std::cout << Array::lineBreak;
}

#endif
