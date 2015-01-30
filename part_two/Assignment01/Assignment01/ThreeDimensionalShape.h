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
    virtual void setHeight(const double &);
    // get the height
    virtual double getHeight() const;
    // set the radius
    virtual void setRadius(const double &);
    // get the radius
    virtual double getRadius() const;
    // pure virtual: calculate and return volume
    virtual double Volume() const = 0;
protected:
    // sets height of object protected so no
    // client code calls this without derived
    // object
    ThreeDimensionalShape(const double &height, const int &noOfSides);
private:
    // member used to represent radius
    double mRadius;
    // member used to represent height
    double mHeight;
};

#endif /* defined(__Assignment01__ThreeDimensionalShape__) */
