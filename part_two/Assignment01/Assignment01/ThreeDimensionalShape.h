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
    // destructor
    virtual ~ThreeDimensionalShape();
    // set the height
    virtual void setHeight(const double &height);
    // get the height
    virtual double getHeight() const;
    // pure virtual: calculate and return volume
    virtual double Volume() const = 0;
    // pure virtual: set radius
    virtual void setRadius(const double &radius) = 0;
    // pure virtual: get radius
    virtual double getRadius() const = 0;
protected:
    // protected so no client code calls
    // this without derived object
    explicit ThreeDimensionalShape(const int &noOfSides);
protected:
    // member used to represent radius
    double mRadius;
private:
    // member used to represent height
    double mHeight;
};

#endif /* defined(__Assignment01__ThreeDimensionalShape__) */
