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
    while (true) {
        PhoneNumber num;
        std::cout << "Enter a phone number in the form (123) 456-7890:\n";
        std::cin >> num;
        std::cout << num;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << std::endl;
    }
}
