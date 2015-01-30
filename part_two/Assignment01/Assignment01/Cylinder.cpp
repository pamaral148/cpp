// Optional Assignment 1 Solution: Cylinder.cpp
// Member-function definitions for class Cylinder.
// Author: Bob Langelaan
// Date: Sept. 20th, 2014

#include "Cylinder.h"

// constructor
Cylinder::Cylinder(void)
: ThreeDimensionalShape(0.0, 3)
{ }

// destructor
Cylinder::~Cylinder()
{
    ; // empty body
}

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