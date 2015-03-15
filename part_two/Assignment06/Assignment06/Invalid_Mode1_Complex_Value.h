//
//  Invalid_Mode1_Complex_Value.h
//  Assignment06
//
//  Created by Paulo Amaral on 2015-03-12.
//  Custom exception class interface for comp2618
//  assignment 06
//
//  Used for handling invalid mode 1 input
//

#ifndef __Assignment06__Invalid_Mode1_Complex_Value__
#define __Assignment06__Invalid_Mode1_Complex_Value__

#include <iostream>
#include <stdexcept>

class Invalid_Mode1_Complex_Value : public std::invalid_argument
{
public:
    Invalid_Mode1_Complex_Value()
    : std::invalid_argument(MSG) {};
private:
    const static char* MSG;
};

#endif /* defined(__Assignment06__Invalid_Mode1_Complex_Value__) */
