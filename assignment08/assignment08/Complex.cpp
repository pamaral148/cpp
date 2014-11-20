//
//  Complex.cpp
//  assignment08
//
//  Created by Paulo Amaral on 2014-11-20.
//  Copyright (c) 2014 a00887758. All rights reserved.
//

#include "Complex.h"

const double Complex::DEFAULT_REAL = 1;

const double Complex::DEFAULT_IMAGINARY = 0;

// single constructor that uses default values
// for each optional parameter
Complex::Complex(const double &realPart,
                 const double &imaginaryPart)
    :realPart(realPart), imaginaryPart(imaginaryPart)
{
    // TODO validation
}

// returns a const reference to the
// real part of the complex number
const double & Complex::getRealPart() const
{
    return realPart;
}

// returns a const reference to the
// imaginary part of the complex number
const double & Complex::getImaginaryPart() const
{
    return imaginaryPart;
}

// takes a const reference to a double and sets
// the realPart member; returns a reference to
// the object to allow cascading
Complex & Complex::setRealPart(const double &realPart)
{
    this->realPart = realPart;
    return *this;
}

// takes a const reference to a double and sets
// the imaginaryPart member; returns a reference to
// the object to allow cascading
Complex & Complex::setImaginaryPart(const double &imaginaryPart)
{
    this->imaginaryPart = imaginaryPart;
    return *this;
}

// prints object to console in the following
// format: "( realNumber, imaginaryNumber )"
// with 4 digits of precision
void Complex::display() const
{
    ; // TODO display
}