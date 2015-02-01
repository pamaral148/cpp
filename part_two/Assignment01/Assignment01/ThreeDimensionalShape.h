// Assignment 1 Abstract Class: ThreeDimensionalShape.h
// Author: Paulo Amaral
// Date: 2015-02-01

#ifndef __Assignment01__ThreeDimensionalShape__
#define __Assignment01__ThreeDimensionalShape__

#include <stdio.h>
#include "Shape.h"

class ThreeDimensionalShape: public Shape
{
public:
    // destructor
    virtual ~ThreeDimensionalShape();
    // set the height
    virtual void setHeight(const double &height);
    // get the height
    virtual double getHeight() const;
    // pure virtual: calculate and return volume
    virtual double Volume() const = 0;
    // pure virtual: set radius
    virtual void setRadius(const double &radius) = 0;
    // get the radius
    double getRadius() const;
protected:
    // protected so no client code calls
    // this without derived object
    explicit ThreeDimensionalShape(const int &noOfSides);
protected:
    // member used to represent radius
    double mRadius;
private:
    // member used to represent height
    double mHeight;
};

#endif /* defined(__Assignment01__ThreeDimensionalShape__) */
