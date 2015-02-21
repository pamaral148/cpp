//
//  PhoneNumber.h
//  Assignment04
//
//  Created by Paulo Amaral on 2015-02-18.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#ifndef Assignment04_PhoneNumber_h
#define Assignment04_PhoneNumber_h
#include <iostream>

class PhoneNumber
{
    // overloaded input and output operators
    friend std::ostream& operator<<( std::ostream&, const PhoneNumber& ) noexcept;
    friend std::istream& operator>>( std::istream&, PhoneNumber& ) noexcept;
    
public:
    PhoneNumber() noexcept; // default constructor
private:
    // char constants for validation and output
    const static char openBracket = '(',
                      closeBracket = ')',
                      space = ' ',
                      dash = '-',
                      zero = '0',
                      one = '1',
                      nullChar = '\0';
    // index constants
    const static short startBracketIndex = 0,
                       endBracketIndex = 4,
                       spaceIndex = 5,
                       dashIndex = 9,
                       exchangeStart = 6,
                       areaCodeMiddle = 2,
                       lineStart = 10,
                       areaCodeStart = 1;
    bool validateAreaCode() const noexcept; // validates area code input
    bool validateExchange() const noexcept; // validates exchange input
    void setAreaCode() noexcept; // sets the area code
    void setExchange() noexcept; // sets the exchange
    void setLine() noexcept; // sets the line
    char phone[ 15 ]; // holds phone number
    char areaCode[ 4 ]; // holds area code
    char exchange[ 4 ]; // holds exchange
    char line[ 5 ]; // holds line
}; // end class PhoneNumber

#endif
