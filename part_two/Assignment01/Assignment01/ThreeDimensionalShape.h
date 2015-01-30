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
    void setHeight(const double &);
    // get the height
    double getHeight() const;
    // pure virtual: calculate and return volume
    // set the radius
    virtual void setRadius(const double &) = 0;
    // get the radius
    virtual double getRadius() const = 0;
    // pure virtual: calculate and return radius
    virtual double Volume() const = 0;
protected:
    // explicit ctor that sets height of object
    // protected so no client code calls this without derived
    // object
    explicit ThreeDimensionalShape(const double &height);
    // member used to represent radius
    double mRadius;
private:
    double mHeight;  // member used to represent height
};

#endif /* defined(__Assignment01__ThreeDimensionalShape__) */
