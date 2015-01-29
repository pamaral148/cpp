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
    Shape(void);  //constructor
    virtual ~Shape(void); //destructor
    
    void setNoOfSides(const int &);  // set the # of sides
    int getNoOfSides() const;        // get the # of sides
    
    static int getObjectCount();     // get the object count
    
    virtual double Area() const;     // calculate and return area
    virtual double Volume() const;   // calculate and return volume
    
protected:
    int mNoOfSides; // represents # of sides in Shape object
    static int mObjectCount; // a static member - counts the # of Shape
    //          objects currently instantiated
    // Only one of these instantiated for the whole class!
};

#endif /* defined(__Assignment01__Shape__) */
