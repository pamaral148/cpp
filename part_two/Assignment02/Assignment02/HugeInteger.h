
// Exercise 9.14 Solution: HugeInteger.h
// HugeInteger class declaration.
// Modified by: Paulo Amaral
// Last modified:

#ifndef __Assignment02__HugeInteger__
#define __Assignment02__HugeInteger__

#include <array>

class HugeInteger
{
    // overloaded extraction operator
    friend std::ostream & operator<<(std::ostream &, const HugeInteger &);
    
    // overloaded insertion operator
    friend std::istream & operator>>( std::istream &, HugeInteger & );
    
    // is LHS equal to RHS
    inline friend bool operator==( const HugeInteger &LHS, const HugeInteger &RHS )
    {
        if (LHS.negative != RHS.negative){  // if not the same sign
            return false;                    //   they are not equal
        }
        
        for( unsigned int i = 0; i < LHS.hugeInt.size(); i++ )
        {
            if (LHS.hugeInt[i] != RHS.hugeInt[i])
            {
                return false;
            }
        }
        return true;
    }
    
    // is LHS less than RHS
    inline friend bool operator<( const HugeInteger &LHS, const HugeInteger &RHS )
    {
        if (LHS.negative && !(RHS.negative)){ // if LHS < 0, and RHS is not < 0
            return true;  // then LHS must be less than RHS
        }
        
        if (!(LHS.negative) && RHS.negative){ // if LHS >= 0, and RHS < 0
            return false;  // then LHS must NOT be less than RHS
        }
        
        // NOTE: From here on, we know the two operands are the same sign
        for(unsigned int i = 0; i < LHS.hugeInt.size(); i++ )
        {
            if (LHS.hugeInt[i] < RHS.hugeInt[i])
            {
                if ( !(LHS.negative)){ // if both numbers are positive
                    return true;
                }
                else { // if both numbers are negative
                    return false;
                }
            }
            else if (LHS.hugeInt[i] > RHS.hugeInt[i])
            {
                if ( !(LHS.negative)){ // if both numbers are positive
                    return false;
                }
                else { // if both numbers are negative
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    //ctor that converts a "long long" into a HugeInteger
    HugeInteger( long long value = 0LL ); //0LL is constant literal value 0
    //   of type long long
    //ctor that converts a string into a HugeInteger
    HugeInteger( const char *str );
    
    //adds RHS into LHS (the object pointed to by the "this" pointer) and returns result
    HugeInteger & operator+=( const HugeInteger & RHS );
    
    //adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
    //   and returns result
    HugeInteger operator+( long long RHS );
    
    //adds a string (which will be converted into a HugeInteger) with LHS into a temp
    //       HugeInteger and returns result
    HugeInteger operator+( const char * RHS );
    
    //subtracts RHS from LHS (the object pointed to by the "this" pointer) and returns result
    HugeInteger & operator-=( const HugeInteger & RHS );
    
    //subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger
    //    and returns result
    HugeInteger operator-( long long RHS );
    
    //subtracts a string (which will be converted into a HugeInteger) from LHS
    //    and puts result into a temp HugeInteger and returns result
    HugeInteger operator-( const char * RHS );
    
    //calculates the negation of the object pointed to by the this pointer and returns result
    HugeInteger operator-() const;
    
    //calculates the absolute value of the object pointed to by the this pointer and returns result
    HugeInteger operator~() const;
    
    // pre-increment the value of the object
    HugeInteger & operator++();
    
    // post-increment the value of the object
    HugeInteger operator++(int);
    
    // pre-decrement the value of the object
    HugeInteger & operator--();
    
    // post-decrement the value of the object
    HugeInteger operator--(int);
    
    // is the object pointed to by the "this" pointer equal to zero
    bool operator!() const;
    
    //Convert a string into a HugeInteger
    void input( const char *str );
    
    // overload typecast to double
    operator double(void) const;
    
private:
    bool negative;  // will be true if number is negative
    std::array<unsigned short,40> hugeInt; // each element in the array represents 
    //    one digit of the number
};

// is LHS not equal to RHS
inline bool operator!=( const HugeInteger &LHS, const HugeInteger &RHS )
{
    return !(LHS == RHS);
}

// is LHS greater than RHS
inline bool operator>( const HugeInteger &LHS, const HugeInteger &RHS )
{
    return !(LHS < RHS || LHS == RHS);
}

// is LHS greater than RHS or equal to RHS
inline bool operator>=( const HugeInteger &LHS, const HugeInteger &RHS )
{
    return (LHS > RHS || LHS == RHS);
}

// is LHS less than RHS or equal to RHS
inline bool operator<=( const HugeInteger &LHS, const HugeInteger &RHS )
{
    return (LHS < RHS || LHS == RHS);
}

// returns true if operand is not equal to zero
inline bool operator+( const HugeInteger &op)
{
    return !(!op);
}

#endif /* defined(__Assignment02__HugeInteger__) */
