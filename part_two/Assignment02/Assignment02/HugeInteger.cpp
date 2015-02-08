// Exercise 9.14 Solution: HugeInteger.cpp
// HugeInteger class implementation.
// Modified by: Paulo Amaral
// Last modified:

#include "HugeInteger.h"

#include <iostream>

using namespace std;

// ctor converts a long long into a HugeInteger
HugeInteger::HugeInteger( long long value )
{
    // set all MaxDigit digits to zero to start
    this->negative = false;
    if (value < 0LL){ // 0LL is constant literal 0 of type long long
        this->negative = true;
        value = - value; // make the value positive
    }
    
    for( unsigned int i = 0; i < hugeInt.size(); i++ )
    {
        this->hugeInt[i] = 0;
    }
    
    // convert individual digits of input value into a HugeInteger
    for( unsigned int j = hugeInt.size()-1; j >= 0 && value != 0LL; j-- )
    {
        this->hugeInt[j] = value % 10;
        value /= 10;
    }
    
    // test to make sure that HugeInteger was able to contain value
    
    if (value != 0LL){
        *this = 0LL; // set to -0, to signal overflow
        this->negative = true; //   Possibly should increase value assigned
    }                          //   to MaxDigit to fix this problem.
}

// converts string into a HugeInteger object
HugeInteger::HugeInteger( const char *str )
{
    this->input( str ); //See HugeInteger::input() method below
}

// adds a string (which will be converted into a HugeInteger) with LHS into a temp
// HugeInteger and returns result
HugeInteger HugeInteger::operator+( const char *str )
{
    return *this += str;
}

// adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
// and returns result
HugeInteger HugeInteger::operator+(long long op)
{
    return *this += op;
}

// adds RHS into LHS (the object pointed to by the "this" pointer)
// and returns result
HugeInteger & HugeInteger::operator+=( const HugeInteger &op )
{
    // if the signs of the 2 numbers are opposites, we need to do subtraction
    //     remember that x + y  ==  x - (-y)
    if ((this->negative && !(op.negative)) || (!(this->negative) && op.negative)){
        return *this -= -op;
    }
    
    // NOTE: From here on, we know the two operands are the same sign
    
    int carry = 0;
    for (int i = hugeInt.size() - 1; i >= 0; i-- )
    {
        this->hugeInt[i] = this->hugeInt[i] + op.hugeInt[i] + carry;
        if (this->hugeInt[i] > 9 ){
            this->hugeInt[i] -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
    
    // test for overflow
    if (carry == 1){
        *this = 0LL; // just set to -0 (LL is for type long long)
        this->negative = true;  // to signal that an overflow occurred
    }
    
    return *this;
}

// subtracts a string (which will be converted into a HugeInteger) from LHS
// and puts result into a temp HugeInteger and returns result
HugeInteger HugeInteger::operator-( const char * str )
{
    return *this -= str;
}

// subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger
// and returns result
HugeInteger HugeInteger::operator-( long long value )
{
    return *this -= value ;
}

// subtracts RHS from LHS (the object pointed to by the "this" pointer)
// and returns result
HugeInteger & HugeInteger::operator-=( const HugeInteger &op )
{
    // if the signs of the 2 numbers are opposites, we need to do addition
    //     remember that x - y  ==  x + (-y)
    if ((this->negative && !(op.negative)) || (!(this->negative) && op.negative)){
        return this->operator +=(-op);
    }
    
    // NOTE: From here on, we know the two operands are the same sign
    
    HugeInteger bigger, smaller; // used to make code easier to understand
    
    if ((*this) == op){ // Are the values equal ?
        *this = 0LL;             // then just return 0
        this->negative = false;
        return *this;
        
    } else if ( (~op) < (~(*this))){ // is magnitude of LHS > RHS
        
        bigger = *this;
        smaller = op;
        
    } else { // magnitude of RHS > LHS
        
        smaller = *this;
        bigger = op;
        *this = -(*this); // result needs to be negated
    }
    
    // subtract smaller (in magnitude) from biggger (in magnitude)
    int borrow = 0;
    short top, bottom, result;
    for ( int i = hugeInt.size()-1; i >= 0; i-- )
    {
        top = bigger.hugeInt[i];
        bottom = smaller.hugeInt[i];
        
        if (borrow == 1)
        {
            top -= 1;
            borrow = 0;
        }
        
        result  = top-bottom;
        if ( result < 0) //if true, we need to borrow
        {
            this->hugeInt[i] = (10+top)-bottom; // or result + 10;
            borrow = 1;
        }
        else
        {
            this->hugeInt[i] = result;
        }
    }
    
    return *this;
}

// calculates the negation of the object pointed
// to by the this pointer and returns result
HugeInteger HugeInteger::operator-() const
{
    HugeInteger temp = *this;
    temp.negative = !temp.negative;
    return temp;
}

// calculates the absolute value of the object pointed
// to by the this pointer and returns result
HugeInteger HugeInteger::operator~() const
{
    HugeInteger temp = *this;
    temp.negative = false;
    return temp;
}

// pre-increment object
HugeInteger & HugeInteger::operator++()
{
    long long inc = 1;
    *this += inc;
    return *this;
}

// post-increment object
HugeInteger HugeInteger::operator++(int)
{
    HugeInteger tmp = *this;
    long long inc = 1;
    *this += inc;
    return tmp;
}

// pre-decrement the value of the object
HugeInteger & HugeInteger::operator--()
{
    long long dec = 1;
    *this -= dec;
    return *this;
}

// post-decrement the value of the object
HugeInteger HugeInteger::operator--(int)
{
    HugeInteger tmp = *this;
    long long dec = 1;
    *this -= dec;
    return tmp;
}

// is the object pointed to by the "this" pointer equal to zero
bool HugeInteger::operator!() const
{
    for (int i = hugeInt.size()-1; i >= 0; --i)
    {
        if ( this->hugeInt[ i ] != 0 )
        {
            return false;
        }
    }
    return true;
}

// Convert a string into a HugeInteger
void HugeInteger::input( const char *str )
{
    // assume positive for now
    this->negative = false;
    
    // init. to all zeros first
    for( unsigned int i = 0; i < hugeInt.size(); i++ )
    {
        this->hugeInt[i] = 0;
    }
    
    int len = static_cast<int>(strlen( str ));
    int k = 0;
    
    // if sign part of string, we need to process
    // if + sign, we ignore since we start with assumption that
    //     input string represents a positive number
    if ((str[k] == '-') || (str[k] == '+')){
        if (str[k] == '-'){ // if negative, set negative member to true
            this->negative = true;
        }
        
        ++k; // go to next char in string "str"
        --len; // length of number is one less
    }
    
    for( unsigned int j = hugeInt.size() - len; j < hugeInt.size(); j++, k++ )
    {
        if (isdigit(str[k])){
            this->hugeInt[j] = str[k] - '0';
        }
        else  // a problem with the string input !!!
        {
            *this = 0LL; // just set to -0 (LL is for type long long)
            this->negative = true;  // to signal there was a problem
            break;     //   and go home
        }
    }
}

// overloaded insertion operator
std::istream & operator>>( std::istream &is, HugeInteger &obj )
{
    char input_string[1002];
    is >> input_string;
    obj.input(input_string);
    return is;
}

// overloaded extraction operator
std::ostream & operator<<(std::ostream &os, const HugeInteger &obj)
{
    // find first non-zero digit
    unsigned int i = 0;
    while(i < obj.hugeInt.size()){
        if(obj.hugeInt[i] != 0){
            break;
        }
        ++i;
    }
    
    // if all zeros, just output a single 0
    if (i == obj.hugeInt.size())
    {
        cout << "0";
        return os;
    }
    
    // check if we need to ouput a negative sign
    if (obj.negative){
        cout << '-';
    }
    
    // output remaining digits
    for( ; i < obj.hugeInt.size(); i++)
    {
        cout << static_cast<short>( obj.hugeInt[i]);
    }
    return os;
}

// overload typecast to double
HugeInteger::operator double() const
{
    double result = 1;
    string value = "";
    
    // find first non-zero digit
    unsigned int i = 0;
    while(i < this->hugeInt.size()){
        if(this->hugeInt[i] != 0){
            break;
        }
        ++i;
    }
    
    // get the power number is raised to
    unsigned long power = this->hugeInt.size() - i;
    
    // if all zeros, return 0 otherwise get the decimal
    // amount as a string so that we can raise it
    // to the correct power
    if(i == this->hugeInt.size()) {
        value += '0';
    } else if(i == this->hugeInt.size() - 1) {
        value += to_string(this->hugeInt[i]);
        value += ".0";
    } else {
        unsigned int count = 0;
        for( ; i < this->hugeInt.size(); ++i, ++count) {
            value += to_string(this->hugeInt[i]);
            if(count == 0) {
                value += '.';
            }
        }
        
        // raise the decimal value to the
        // appropriate power
        for (int j = 1; j < power; ++j) {
            result *= 10;
        }
    }
    
    if(this->negative) {
        return - (atof(value.c_str()) * result);
    } else {
        return atof(value.c_str()) * result;
    }
}

