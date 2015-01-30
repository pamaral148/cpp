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
    virtual ~TwoDimensionalShape(); // virtual destructor
protected:
    // constructor
    TwoDimensionalShape();
private:
    // the default no of sides for the object
    const static int defaultNoSides;
};

#endif /* defined(__Assignment01__TwoDimensionalShape__) */
