//
//  ThreeDimensionalShape.h
//  Assignment01
//
//  Created by Paulo Amaral on 2015-01-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#ifndef __Assignment01__ThreeDimensionalShape__
#define __Assignment01__ThreeDimensionalShape__

#include <stdio.h>
#include "Shape.h"

class ThreeDimensionalShape: public Shape
{
public:
    
    explicit ThreeDimensionalShape(const double &);
    
    void setHeight(const double &); // set the height
    double getHeight() const; // get the height
    
    virtual double Area() const override;    // overrides Area() of Shape class
    virtual double Volume() const = 0;   // calculate and return volume

protected:
    
    double mHeight;  // member used to represent height
};

#endif /* defined(__Assignment01__ThreeDimensionalShape__) */
