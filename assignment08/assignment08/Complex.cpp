//
//  Complex.cpp
//  assignment08
//
//  Created by Paulo Amaral on 2014-11-20.
//  Student #: a00887758
//
//  Class that represents complex numbers for comp2617 assignment08
//

#include "Complex.h"
#include <iostream>
#include <iomanip>

const double Complex::DEFAULT_REAL = 1;
const double Complex::DEFAULT_IMAGINARY = 0;
const int Complex::OUTPUT_PRECISION = 4;

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
    std::cout << std::fixed << std::setprecision(OUTPUT_PRECISION) <<
    "( " << getRealPart() << ", " << getImaginaryPart()
    << ")";
}

// takes a const reference to a Complex object and
// adds the real part to the Object's real part and
// then adds the imaginary part to the Object's
// imaginary part; returns a reference to the current
// object
Complex & Complex::plusEq(const Complex &term)
{
    setRealPart(getRealPart() + term.getRealPart()).
    setImaginaryPart(getImaginaryPart() + term.getImaginaryPart());
    return *this;
}

// takes a const reference to a Complex object and
// subtracts the real part from the Object's real part and
// then subtracts the imaginary part from the Object's
// imaginary part; returns a reference to the current
// object
Complex & Complex::minusEq(const Complex &term)
{
    setRealPart(getRealPart() - term.getRealPart()).
    setImaginaryPart(getImaginaryPart() - term.getImaginaryPart());
    return *this;
}