// Optional Assignment 1 Solution: Shape.h
// Declaration of class Shape.
// Member functions are defined in Shape.cpp.
// Author: Bob Langelaan
// Date: Sept. 9, 2006

#ifndef __Assignment01__Shape__
#define __Assignment01__Shape__

#include <stdio.h>

class Shape
{
public:
    // destructor
    virtual ~Shape(void);
    // set the # of sides
    void setNoOfSides(const int &);
    // get the # of sides
    int getNoOfSides() const;
    // get the object count
    static int getObjectCount();
    // pure virtual: calculate and return area
    virtual double Area() const = 0;
protected:
    // constructor
    explicit Shape(const int &noOfSides = 0);
    // represents # of sides in Shape object
    int mNoOfSides;
    // a static member - counts the # of Shape
    // objects currently instantiated
    // Only one of these instantiated for the whole class!
    static int mObjectCount;
    // Static member used in calculations
    const static double pi;
};

#endif /* defined(__Assignment01__Shape__) */
