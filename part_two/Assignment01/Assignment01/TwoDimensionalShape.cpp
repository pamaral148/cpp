//
//  TwoDimensionalShape.cpp
//  Assignment01
//
//  Created by Paulo Amaral on 2015-01-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#include "TwoDimensionalShape.h"

// the default no of sides for the object
const int TwoDimensionalShape::defaultNoSides = 1;

// constructor
TwoDimensionalShape::TwoDimensionalShape(const int &noOfSides)
:mRadius(0.0), Shape(noOfSides)
{
    this->setNoOfSides(this->defaultNoSides);
}

// destructor
TwoDimensionalShape::~TwoDimensionalShape()
{
    ; // empty dtor
}

