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
    friend std::ostream& operator<<( std::ostream&, const PhoneNumber& );
    friend std::istream& operator>>( std::istream&, PhoneNumber& );
    
public:
    PhoneNumber(); // default constructor
private:
    char phone[ 15 ]; // holds phone number
    char areaCode[ 4 ]; // holds area code
    char exchange[ 4 ]; // holds exchange
    char line[ 5 ]; // holds line
}; // end class PhoneNumber

#endif
