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

class Cylinder : public ThreeDimensionalShape
{
public:
    // constructor
    Cylinder(void);
    // destructor
    ~Cylinder();
    // set the radius
    void setRadius(const double &);
    // get the radius
    double getRadius() const;
    // calculate the area of the cylinder
    double Area (void) const;
    // calculate the Volume of the cylinder; overrides the
    // base pure virtual method
    virtual double Volume() const override;
};

#endif /* defined(__Assignment01__Cylinder__) */
