//
//  TwoDimensionalShape.h
//  Assignment01
//
//  Created by Paulo Amaral on 2015-01-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#ifndef __Assignment01__TwoDimensionalShape__
#define __Assignment01__TwoDimensionalShape__

#include <stdio.h>
#include "Shape.h"

class TwoDimensionalShape: public Shape
{
public:
    virtual double Area() const override = 0;  // overrides Area() method of Shape class
    
};

#endif /* defined(__Assignment01__TwoDimensionalShape__) */
