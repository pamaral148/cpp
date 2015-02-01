// Assignment 1 Abstract Class: ThreeDimensionalShape.cpp
// Author: Paulo Amaral
// Date: 2015-02-01

#include "ThreeDimensionalShape.h"

// constructor
ThreeDimensionalShape::ThreeDimensionalShape(const int &noOfSides)
: mHeight(0.0), mRadius(0.0), Shape(noOfSides)
{ /* empty ctor */ }

// desctructor
ThreeDimensionalShape::~ThreeDimensionalShape()
{ /* empty dtor */ }

// used to set mHeight member
void ThreeDimensionalShape::setHeight(const double & setVal)
{
    if (setVal > 0.0 )  // Make sure input is a valid value
    {
        this->mHeight = setVal;
    }
    
    // otherwise just leave set to original value
}

// used to return current value of mHeight member
double ThreeDimensionalShape::getHeight (void) const
{
    return this->mHeight;
}

// returns the radius
double ThreeDimensionalShape::getRadius() const
{
    return mRadius;
}