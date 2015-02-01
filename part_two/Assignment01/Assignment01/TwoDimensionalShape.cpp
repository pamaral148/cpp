// Assignment 1 Abstract Class: TwoDimensionalShape.cpp
// Author: Paulo Amaral
// Date: 2015-02-01

#include "TwoDimensionalShape.h"

// the default no of sides for the object
const int TwoDimensionalShape::defaultNoSides = 1;

// constructor; sets radius to 0 and sets the number of sides
TwoDimensionalShape::TwoDimensionalShape(const int &noOfSides)
: mRadius(0.0), Shape(noOfSides)
{ /* empty ctor */ }

// destructor
TwoDimensionalShape::~TwoDimensionalShape()
{ /* empty dtor */ }

// returns the radius
double TwoDimensionalShape::getRadius()
{
    return this->mRadius;
}
