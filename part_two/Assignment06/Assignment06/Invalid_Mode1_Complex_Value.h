//
//  Invalid_Mode1_Complex_Value.h
//  Assignment06
//
//  Created by Paulo Amaral on 2015-03-12.
//  Copyright (c) 2015 pamaral. All rights reserved.
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
    const static std::string MSG;
};

#endif /* defined(__Assignment06__Invalid_Mode1_Complex_Value__) */
