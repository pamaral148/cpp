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
    // constructor
    Circle(void);
    // destructor
    virtual ~Circle();
    // set the radius
    void setRadius(const double &);
    // get the radius
    double getRadius() const;
    // overrides Area() method of Shape class
    virtual double Area() const override;
protected:
    // member used to represent radius
    double mRadius;
    // the default no of sides for the object
    const static int defaultNoSides;
};

#endif /* defined(__Assignment01__Circle__) */
