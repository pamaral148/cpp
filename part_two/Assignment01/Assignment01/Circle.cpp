// Optional Assignment 1 Solution: Circle.cpp
// Member-function definitions for class Circle.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

// Modified by: Paulo Amaral
// Modified: 2015-02-01

#include "Circle.h"

// the default no of sides for the object
const int Circle::defaultNoSides = 1;

// constructor
Circle::Circle(void)
: TwoDimensionalShape(this->defaultNoSides)
{ /* empty ctor */ }

// destructor
Circle::~Circle()
{ /* empty dtor */ }

// used to set value for mRadius member
void Circle::setRadius(const double & setVal)
{
    if (setVal > 0.0) // Make sure input is a valid value
    {
        this->mRadius = setVal;
    }
    
    // otherwise just leave set to original value
}

// used top calculate and return area.
double Circle::Area (void) const
{
    return Shape::pi * this->mRadius * this->mRadius ;
}
