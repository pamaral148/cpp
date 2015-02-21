//
//  PhoneNumber.cpp
//  Assignment04
//
//  Created by Paulo Amaral on 2015-02-18.
//  Implementation of PhoneNumber class
//

#include "PhoneNumber.h"

const std::string PhoneNumber::errorMsg = "Invalid phone number entered...\n";
const std::string PhoneNumber::introMsg = "The phone number entered was... ";

// default ctor
PhoneNumber::PhoneNumber() noexcept
{ /* empty ctor */ }

// validates area code input
bool PhoneNumber::validateAreaCode() const noexcept
{
    const short start = 1;
    bool test;
    if(phone[startBracketIndex] != openBracket ||
       phone[endBracketIndex] != closeBracket  ||
       phone[spaceIndex] != space ||
       phone[dashIndex] != '-' ||
       phone[start] == zero ||
       phone[start] == one ||
      (phone[areaCodeMiddle] != zero &&
       phone[areaCodeMiddle] != one)
    ) {
        test = false;
    } else {
        test = true;
    }
    return test;
}

// validates exchange input
bool PhoneNumber::validateExchange() const noexcept
{
    bool test;
    if(phone[exchangeStart] == zero ||
       phone[exchangeStart] == one
    ) {
        test = false;
    } else {
        test = true;
    }
    return test;
}

// sets the area code
void PhoneNumber::setAreaCode() noexcept
{
    const short max = 4;
    short j = 0;
    for (short i = areaCodeStart; i < max; ++i, ++j) {
        areaCode[j] = phone[i];
    }
    areaCode[++j] = nullChar;
}

// sets the exchange
void PhoneNumber::setExchange() noexcept
{
    const short max = 9;
    short j = 0;
    for (short i = exchangeStart; i < max; ++i, ++j) {
        exchange[j] = phone[i];
    }
    exchange[++j] = nullChar;
}

void PhoneNumber::setLine() noexcept
{
    const short max = 15;
    short j = 0;
    for (short i = lineStart; i < max; ++i, ++j) {
        line[j] = phone[i];
    }
    line[++j] = nullChar;
}

// overloaded insertion operator
// inserts phone number to ostream in formatted output
std::ostream& operator<<( std::ostream& os, const PhoneNumber& phoneNumber ) noexcept
{
    std::cout << PhoneNumber::introMsg
              << phoneNumber.openBracket << phoneNumber.areaCode
              << phoneNumber.closeBracket << phoneNumber.space
              << phoneNumber.exchange << phoneNumber.dash
    << phoneNumber.line << std::endl;
    return os;
}

// overloaded extraction operator
std::istream& operator>>( std::istream& is, PhoneNumber& phoneNumber ) noexcept
{
    // char location constants
    const int size = 15,
              charCount = 14;
    
    is.get(phoneNumber.phone, size, '\n');
    
    if(is.gcount() != charCount ||
       !phoneNumber.validateAreaCode() ||
       !phoneNumber.validateExchange()
    ) {
        // set istream failbit
        is.clear(std::ios_base::failbit);
    }
    if(is.fail()) {
        std::cerr << PhoneNumber::errorMsg;
        exit(errno);
    } else {
        phoneNumber.setAreaCode();
        phoneNumber.setExchange();
        phoneNumber.setLine();
    }
    return is;
}

