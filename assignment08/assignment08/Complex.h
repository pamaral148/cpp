//
//  Complex.h
//  assignment08
//
//  Created by Paulo Amaral on 2014-11-20.
//  Class that represents complex numbers for comp2617 assignment08
//

#ifndef __assignment08__Complex__
#define __assignment08__Complex__

#include <stdio.h>

class Complex
{
public:
    // static constant default values
    static const double DEFAULT_REAL;
    static const double DEFAULT_IMAGINARY;
    static const int OUTPUT_PRECISION;
    
    // single constructor that uses default values
    // for each optional parameter
    Complex(const double &realPart = DEFAULT_REAL,
            const double &imaginaryPart = DEFAULT_IMAGINARY);
    
    // accessor functions for reading private data
    // members; each returns a const reference to
    // the data member
    const double & getRealPart() const;
    const double & getImaginaryPart() const;
    
    // mutator functions for modifying private data
    // members; each returns a reference to the
    // object to allow for cascading
    Complex & setRealPart(const double & realPart);
    Complex & setImaginaryPart(const double & imaginaryPart);
    
    // prints object to console in the following
    // format: "( realNumber, imaginaryNumber )"
    // with 4 digits of precision
    void display() const;
    
    // arithmetic functions that perform
    // += and -= operrations for Complex
    // numbers and return a reference to
    // the modified object
    Complex & plusEq(const Complex &term);
    Complex & minusEq(const Complex &term);

private:
    double realPart;
    double imaginaryPart;
};

#endif /* defined(__assignment08__Complex__) */
