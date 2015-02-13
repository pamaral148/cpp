//
//  Array.h
//  Assignment03
//
//  Created by Paulo Amaral on 2015-02-11.
//  Template Array class interface file
//

#ifndef Assignment03_Array_h
#define Assignment03_Array_h

#include <iostream>

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
    // the current number of specialized objects
    static int arrayCount;
    // the underlying data structure
    T data[size];
};

// tracks the number of objects that currently
// exist in program
template<class T, int size>
int Array<T, size>::arrayCount = 0;

// returns the number of objects that
// currently exist in program
template<class T, int size>
int Array<T, size>::getArrayCount()
{
    return arrayCount;
}

// default ctor; increments the obj count
template<class T, int size>
Array<T, size>::Array()
{
    ++arrayCount;
}

// dtor; decrements the obj count
template<class T, int size>
Array<T, size>::~Array()
{
    --arrayCount;
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
        return this->data[0];
    }
}

// returns element at index
template<class T, int size>
T& Array<T, size>::operator[](const int &index)
{
    if(index >= 0 && index < size) {
        return this->data[index];
    } else {
        return this->data[0];
    }
}

// inputs elements into the array
template<class T, int size>
void Array<T, size>::inputArray()
{
    for (int i = 0; i < size; ++i) {
        T el;
        std::cin >> el;
        this->data[i] = el;
    }
}

// outputs elements from the array
template<class T, int size>
void Array<T, size>::outputArray() const
{
    for (int i = 0; i < size; ++i) {
        std::cout << this->data[i];
    }
}

#endif
