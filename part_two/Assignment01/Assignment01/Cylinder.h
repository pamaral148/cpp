// Optional Assignment 1 Solution: Cylinder.h
// Declaration of class Cylinder.
// Member functions are defined in Cylinder.cpp.
// Author: Bob Langelaan
// Date: Sept. 9th, 2006

// Last Modified by: Paulo Amaral
// Last Modified Date: 2015-01-28

#ifndef __Assignment01__Cylinder__
#define __Assignment01__Cylinder__

#include <stdio.h>
#include "ThreeDimensionalShape.h"

class Cylinder :public ThreeDimensionalShape
{
public:
    Cylinder(void); // constructor
    
    void setHeight(const double &); // set the height
    double getHeight() const; // get the height
    
    virtual double Area() const override;    // overrides Area()   method of Circle class
    virtual double Volume() const override;  // overrides Volume() method of Shape  class
    
protected:
    double mHeight;  // member used to represent height
};

#endif /* defined(__Assignment01__Cylinder__) */
