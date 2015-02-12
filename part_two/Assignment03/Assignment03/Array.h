//
//  Array.h
//  Assignment03
//
//  Created by Paulo Amaral on 2015-02-11.
//  Template Array class interface file
//

#ifndef Assignment03_Array_h
#define Assignment03_Array_h

template<class T = int, int size = 5>
class Array
{
public:
    // returns the current number of specialized objects
    static int getArrayCount();
private:
    // the current number of specialized objects
    static int arrayCount;
    // the underlying data structure
    T data[size];
};
#endif
