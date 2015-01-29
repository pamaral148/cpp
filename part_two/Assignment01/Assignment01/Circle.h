// Optional Assignment 1 Solution: Circle.h
// Declaration of class Circle.
// Member functions are defined in Circle.cpp.
// Author: Bob Langelaan
// Date: Sept. 9th, 2006

// Last Modified by: Paulo Amaral
// Last Modified Date: 2015-01-28

#ifndef __Assignment01__Circle__
#define __Assignment01__Circle__

#include <stdio.h>
#include "TwoDimensionalShape.h"

class Circle :public TwoDimensionalShape
{
public:
    Circle(void); // constructor
    
    void setRadius(const double &);  //set the radius
    double getRadius() const;  // get the radius
    
    virtual double Area() const override;  // overrides Area() method of Shape class
    
protected:
    const static double pi; // Static member used in calculations
    // Only one of these instantiated for the whole class!
    double mRadius;  // member used to represent radius
};

#endif /* defined(__Assignment01__Circle__) */
