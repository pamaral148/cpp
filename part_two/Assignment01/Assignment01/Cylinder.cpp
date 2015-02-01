// Optional Assignment 1 Solution: Cylinder.cpp
// Member-function definitions for class Cylinder.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

#include "Cylinder.h"

// the default no of sides for the object
const int Cylinder::defaultNoSides = 3;

// constructor
Cylinder::Cylinder(void)
: ThreeDimensionalShape(defaultNoSides)
{ /* empty ctor */ }

// destructor
Cylinder::~Cylinder()
{ /* empty dtor */ }

// used to caluclate and return area
double Cylinder::Area (void) const
{
    double TwoPiR = 2.0 * Shape::pi * this->getRadius();
    return ( TwoPiR * this->getRadius() ) + ( TwoPiR * this->getHeight() );
}

// used to claculate and return volume
double Cylinder::Volume (void) const
{
    return Shape::pi * this->getRadius() * this->getRadius() * this->getHeight();
}

// sets the radius; must be > 0
void Cylinder::setRadius(const double & radius)
{
    if (radius > 0.0) // Make sure input is a valid value
    {
        this->mRadius = radius;
    }
    
    // otherwise just leave set to original value
}