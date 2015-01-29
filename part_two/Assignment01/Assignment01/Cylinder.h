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
    Cylinder(void); // constructor
    
    void setRadius(const double &);  //set the radius
    double getRadius() const;  // get the radius
    
    double Area (void) const;
    virtual double Volume() const override;  // overrides Volume() method of Shape  class
private:
     double mRadius;  // member used to represent radius
};

#endif /* defined(__Assignment01__Cylinder__) */
