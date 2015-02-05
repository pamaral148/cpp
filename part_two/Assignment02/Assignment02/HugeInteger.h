
// Exercise 9.14 Solution: HugeInteger.h
// HugeInteger class declaration.
// Modified by: Paulo Amaral
// Last modified:

#ifndef __Assignment02__HugeInteger__
#define __Assignment02__HugeInteger__

#include <array>

class HugeInteger
{
public:
    //ctor that converts a "long long" into a HugeInteger
    HugeInteger( long long value = 0LL ); //0LL is constant literal value 0
    //   of type long long
    //ctor that converts a string into a HugeInteger
    HugeInteger( const char *str );
    
    //adds RHS into LHS (the object pointed to by the "this" pointer) and returns result
    /* REMOVE: HugeInteger & addInto( const HugeInteger & RHS); */
    HugeInteger & operator+=( const HugeInteger & RHS );
    
    //adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
    //   and returns result
    /* REMOVE: HugeInteger add( long long RHS); */
    HugeInteger operator+( long long RHS );
    
    //adds a string (which will be converted into a HugeInteger) with LHS into a temp
    //       HugeInteger and returns result
    /* REMOVE: HugeInteger add( const char * RHS); */
    HugeInteger operator+( const char * RHS );
    
    //subtracts RHS from LHS (the object pointed to by the "this" pointer) and returns result
    /* REMOVE: HugeInteger & subInto( const HugeInteger & RHS); */
    HugeInteger & operator-=( const HugeInteger & RHS );
    
    //subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger
    //    and returns result
    HugeInteger subtract( long long RHS);
    
    //subtracts a string (which will be converted into a HugeInteger) from LHS
    //    and puts result into a temp HugeInteger and returns result
    HugeInteger subtract( const char * RHS);
    
    //calculates the negation of the object pointed to by the this pointer and returns result
    HugeInteger negate(void)const;
    
    //calculates the absolute value of the object pointed to by the this pointer and returns result
    HugeInteger abs(void)const;
    
    //Is LHS (the object pointed to by the "this" pointer) equal to RHS
    bool isEqualTo( const HugeInteger & RHS)const;
    
    //Is LHS (the object pointed to by the "this" pointer) less than RHS
    bool isLessThan( const HugeInteger & RHS)const;
    
    //Is the object pointed to by the "this" pointer equal to zero
    bool isZero(void)const;
    
    //Is LHS (the object pointed to by the "this" pointer) not equal to RHS
    bool isNotEqualTo( const HugeInteger & )const;
    
    //Is LHS (the object pointed to by the "this" pointer) greater than RHS
    bool isGreaterThan( const HugeInteger & )const;
    
    //Is LHS (the object pointed to by the "this" pointer) greater than or equal to RHS
    bool isGreaterThanOrEqualTo( const HugeInteger & )const;
    
    //Is LHS (the object pointed to by the "this" pointer) less than or equal to RHS
    bool isLessThanOrEqualTo( const HugeInteger & )const;
    
    //Convert a string into a HugeInteger
    void input( const char *str );
    
    //Output a HugInteger
    void output()const;
    
private:
    bool negative;  // will be true if number is negative
    std::array<unsigned short,40> hugeInt; // each element in the array represents 
    //    one digit of the number
};


#endif /* defined(__Assignment02__HugeInteger__) */
