//
//  PhoneNumber.cpp
//  Assignment04
//
//  Created by Paulo Amaral on 2015-02-18.
//  Implementation of PhoneNumber class
//

#include "PhoneNumber.h"

const int ERROR = 1;

// default ctor
PhoneNumber::PhoneNumber() noexcept
{
    // TODO ctor
}

// overloaded insertion operator
// inserts phone number to ostream in formatted output
std::ostream& operator<<( std::ostream& os, const PhoneNumber& phoneNumber ) noexcept
{
    std::cout << '(' << phoneNumber.areaCode << ") "
              << phoneNumber.exchange
              << '-' << phoneNumber.line;
    return os;
}

// overloaded extraction operator
std::istream& operator>>( std::istream& is, PhoneNumber& phoneNumber ) noexcept
{
    // char location constants
    const int size = 15,
              openBracket = 0,
              closeBracket = 4,
              space = 5,
              dash = 9;
    
    is.get(phoneNumber.phone, size, '\n');
    
    if(phoneNumber.phone[openBracket] != '('  ||
       phoneNumber.phone[closeBracket] != ')' ||
       phoneNumber.phone[space] != ' '        ||
       phoneNumber.phone[dash] != '-'
    ) {
        std::cerr << "Invalid phone number entered...\n";
        exit(ERROR);
    } else {
        for (int i = 1, j = 0, k = 6; i < 4; ++i, ++j, ++k) {
            phoneNumber.areaCode[j] = phoneNumber.phone[i];
            phoneNumber.exchange[j] = phoneNumber.phone[k];
        }
        for (int i = 10, j = 0; i < 15; ++i, ++j) {
            phoneNumber.line[j] = phoneNumber.phone[i];
        }
        phoneNumber.areaCode[3] = '\0';
        phoneNumber.exchange[3] = '\0';
        phoneNumber.line[4] = '\0';
    }
    return is;
}