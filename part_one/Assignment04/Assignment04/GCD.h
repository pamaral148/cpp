//
//  GCD.h
//  Assignment04
//
//  Created by Paulo Amaral on 2014-10-16.
//  Defines template function for finding the greatest common denominator
//

#ifndef Assignment04_GCD_h
#define Assignment04_GCD_h

// implementation of template function that returns the greatest common denomitor for two numbers
template <typename T>
T gcd(T numberOne, T numberTwo)
{
    const T MIN_GCD = 1;
    // protect against negative values by taking absolute of number arguments
    if (numberOne < 0) {
        numberOne = -numberOne;
    }
    
    if (numberTwo < 0) {
        numberTwo = -numberTwo;
    }
    
    // find GCD
    T gcd = MIN_GCD;
    for (int i = 1; i <= numberOne && i <= numberTwo; ++i) {
        if (numberOne % i == 0 && numberTwo % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

#endif
