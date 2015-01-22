//
//  Fraction.cpp
//  Assignment04
//
//  Created by Paulo Amaral on 2014-10-16.
//  Fraction class implementation for comp 2617 Assignment 04
//

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>

using namespace std;

// default constructor that creates a fraction of 0/1
Fraction::Fraction()
: numerator(0), denominator(1)
{
    // empty function body
}

// non-default constructor that takes two parameters and uses a default argument of 1
// for the denominator; constructor calls simplify to reduce fraction and flip signs if
// necessary
Fraction::Fraction(long long num, long long denom)
: numerator(num), denominator(denom)
{
    simplify();
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
    numerator *= op.numerator;
    denominator *= op.denominator;
    
    simplify();  // will make sure that denominator is positive and
    //   will invoke gcd() function to reduce fraction
    //   as much as possible
    
    return (*this); // returns the object which invoked the method
}

// Divides RHS into the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::divideEq (const Fraction & RHS )
{
    numerator *= RHS.denominator;
    denominator *= RHS.numerator;
    
    simplify(); // will make sure that denominator is positive and
    //   will invoke gcd() function to reduce fraction
    //   as much as possible
    
    return (*this); // returns the object which invoked the method
}

// Adds RHS to the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::plusEq (const Fraction & RHS )
{
    numerator = (numerator * RHS.denominator) + (RHS.numerator * denominator);
    denominator *= RHS.denominator;
    
    simplify(); // will make sure that denominator is positive and
    //   will invoke gcd() function to reduce fraction
    //   as much as possible
    
    return (*this); // returns the object which invoked the method
}

// Subtracts RHS from the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::minusEq (const Fraction & RHS )
{
    numerator = (numerator * RHS.denominator) - (RHS.numerator * denominator);
    denominator *= RHS.denominator;
    
    simplify(); // will make sure that denominator is positive and
    //   will invoke gcd() function to reduce fraction
    //   as much as possible
    
    return (*this); // returns the object which invoked the method
}

// Returns the negation of the Fraction object invoked with the method but
// must NOT modify the actual Fraction object invoked with the method.
Fraction Fraction::negate (void)const
{
    return Fraction(-numerator, denominator);
}

// Returns numerator
long long Fraction::getNum(void)const
{
    return numerator;
}

// Returns denominator
long long Fraction::getDenom(void)const
{
    return denominator;
}

// Outputs to standard output stream the Fraction object
// in the format: numerator/denominator
void Fraction::display(void)const
{
    cout << getNum() << "/" << getDenom() << endl;
}

// this method reduces the Fraction objects as much as possible.
//It also ensures that the denominator is positive.
void Fraction::simplify (void)
{
    long divisor = gcd(numerator, denominator);
    // reduce fraction to smallest terms
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
    
    // negate values if - denominator
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}