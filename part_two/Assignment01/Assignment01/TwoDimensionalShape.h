// Assignment 1 Abstract Class: TwoDimensionalShape.h
// Author: Paulo Amaral
// Date: 2015-02-01

#ifndef __Assignment01__TwoDimensionalShape__
#define __Assignment01__TwoDimensionalShape__

#include <stdio.h>
#include "Shape.h"

class TwoDimensionalShape: public Shape
{
public:
    // virtual destructor
    virtual ~TwoDimensionalShape();
    // pure virtual: set radius
    virtual void setRadius(const double &radius) = 0;
    // return the radius
    double getRadius();
protected:
    // constructor
    explicit TwoDimensionalShape(const int &noOfSides);
    // member used to represent radius
    double mRadius;
private:
    // the default no of sides for the object
    const static int defaultNoSides;
};

#endif /* defined(__Assignment01__TwoDimensionalShape__) */
