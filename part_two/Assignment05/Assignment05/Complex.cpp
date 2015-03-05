// Assignment 5 Starting Point: Complex.cpp
// Member-function definitions for class Complex.
// Author: Bob Langelaan
// Date: Feb 19, 2014

#include "Complex.h"
#include <iomanip>
using namespace std;

//ctor
Complex::Complex ( double real, double imag )
{
    this->real_part = real;
    this->imaginary_part = imag;
}

// overload the "+=" operator
Complex & Complex::operator += (const Complex & op )
{
    this->real_part += op.real_part;
    this->imaginary_part += op.imaginary_part;
    
    return (*this);
}

// overload the "-=" operator
Complex & Complex::operator -= (const Complex & op )
{
    this->real_part -= op.real_part;
    this->imaginary_part -= op.imaginary_part;
    
    return (*this);
}

// overload the "==" operator
bool Complex::operator == (const Complex & RHS) const
{
    if (this->real_part != RHS.real_part)
    {
        return false;
    }
    else if (this->imaginary_part != RHS.imaginary_part)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// return the real part of the complex #
double Complex::getReal(void)
{
    return this->real_part;
}

// return the imaginary part of the complex #
double Complex::getImaginary(void)
{
    return this->imaginary_part;
}

// display the complex #
void Complex::display (void)
{
    // set floating-point number format
    cout << fixed << setprecision(3);
    
    cout << "( " << this->getReal() << " , " << this->getImaginary() << " )";
}

// overloads the binary '+' operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS )
{
    Complex temp = LHS;
    temp += RHS; // uses the overloaded "+=" operator
    return temp;
}

// overloads the binary '-' operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS )
{
    Complex temp = LHS;
    temp -= RHS; // uses the overloaded "-=" operator
    return temp;
}

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS)
{
    return !(LHS == RHS); // uses overloaded "==" operator
}

// overloads the binary "<<" operator through a global friend function
//   Complex object will be formatted in the following format:
//   ( -125.00, 23.44 )
ostream & operator << (ostream & dest, const Complex & obj)
{
    dest << "( " << obj.real_part << ", " << obj.imaginary_part << " )";
    return dest; // enables  cout << a << b << c
}

// overloads the binary ">>" operator through a global friend function
//   Complex object will be input by the user in the following format:
//   ( -125.00, 23.44 )
istream & operator >> (istream & input, Complex & obj)
{
    input.ignore(2,'('); // skip over '('
    input >> obj.real_part; // read the real component of the Complex #
    input.ignore(2,','); // skip over ','
    input >> obj.imaginary_part; // read the real component of the Complex #
    input.ignore(2,')'); // skip over ')'
    
    return input; // enables  cin >> a >> b >> c
}


