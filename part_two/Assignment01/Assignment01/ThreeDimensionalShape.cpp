//
//  ThreeDimensionalShape.cpp
//  Assignment01
//
//  Created by Paulo Amaral on 2015-01-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#include "ThreeDimensionalShape.h"

ThreeDimensionalShape::ThreeDimensionalShape(const double &height)
: mHeight(0.0)
{
    this->setHeight(height);
}

ThreeDimensionalShape::~ThreeDimensionalShape()
{
    ; // empty dtor
}

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