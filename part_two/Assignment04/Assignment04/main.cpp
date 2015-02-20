//
//  main.cpp
//  Assignment04
//
//  Created by Paulo Amaral on 2015-02-18.
//  Driver file for Comp2618 assignment 04
//

#include <iostream>
#include "PhoneNumber.h"

int main(int argc, const char * argv[])
{
    PhoneNumber num;
    
    std::cout << "enter a phone number: ";
    std::cin >> num;
    std::cout << "The number is " << num << "\n";
}
