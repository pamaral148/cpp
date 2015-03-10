// Assignment 5 Starting Point: Complex.cpp
// Member-function definitions for class Complex.
// Author: Bob Langelaan
// Date: Feb 19, 2014

// Modified By: Paulo Amaral
// Modified Date: March 09, 2015

#include "Complex.h"
#include <iomanip>
#include <iostream>
#include <regex>
#include <cmath>

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
    
    dest << fixed;
    if((dest.flags() & std::ios::oct) != 0) {
        // mode 1
        dest << setprecision(2);
        dest << "(";
        obj.real_part > 0 ? dest << "+" : dest << "-";
        dest << setw(7) << abs(obj.real_part);
        dest << ",";
        obj.imaginary_part > 0 ? dest << "+" : dest << "-";
        dest << setw(7) << abs(obj.imaginary_part);
        dest << ")";
    } else {
        // mode 2
        dest << setprecision(4);
        dest << obj.real_part << " " << obj.imaginary_part << "i";
    }
    return dest; // enables  cout << a << b << c
}

// overloads the binary ">>" operator through a global friend function
//   Complex object will be input by the user in the following format:
//   ( -125.00, 23.44 )
istream & operator >> (istream & input, Complex & obj)
{
    if((input.flags() & std::ios::oct) != 0) {
        input.ignore(2,'('); // skip over '('
        input >> obj.real_part; // read the real component of the Complex #
        if(input.peek() != ',') {
            input.setstate(ios::failbit);
        }
        input.ignore(2,','); // skip over ','
        input >> obj.imaginary_part; // read the real component of the Complex #
        if(input.peek() != ')') {
            input.setstate(ios::failbit);
        }
        input.ignore(2,')'); // skip over ')'
        if(input.peek() == '\n') {
            input.ignore(256,'\n');
        }
    } else {
        std::string tokenA, tokenB;
        input >> tokenA;
        // is this an imaginary number in mode 2 (nnnn.nni)?
        if(std::regex_match(tokenA, std::regex("^-?\\d+\\.?\\d*i$"))) {
            tokenA.pop_back();
            obj.real_part = 0;
            obj.imaginary_part = stod(tokenA);
        // check that user input meets rqeuirements for mode 2 "nnnn.nn nnnn.nni"
        } else if(std::regex_match(tokenA, std::regex("^-?\\d+\\.?\\d*$"))) {
            input >> tokenB;
            if(std::regex_match(tokenB, std::regex("^-?\\d+\\.?\\d*i$"))) {
                obj.real_part = stod(tokenA);
                tokenB.pop_back();
                obj.imaginary_part = stod(tokenB);
            } else {
                input.setstate(ios::failbit);
            }
        // bad input so set error bit
        } else {
            input.setstate(ios::failbit);
        }
    }
    return input; // enables  cin >> a >> b >> c
}


