// Optional Assignment 1 Solution: Circle.cpp
// Member-function definitions for class Circle.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

#include "Circle.h"

const double Circle::pi = 3.141592654;  // init. static member

// constructor
Circle::Circle(void)
:mRadius(0.0)
{
    this->setNoOfSides(1);  //  Why not init. this member in MIL ???
}

// used to set value for mRadius member
void Circle::setRadius(const double & setVal)
{
    if (setVal > 0.0) // Make sure input is a valid value
    {
        this->mRadius = setVal;
    }
    
    // otherwise just leave set to original value
}

// used to return current value of mRadius member
double Circle::getRadius (void) const
{
    return this->mRadius ;
}

// used top calculate and return area.
double Circle::Area (void) const
{
    return Circle::pi * this->mRadius * this->mRadius ;
}
