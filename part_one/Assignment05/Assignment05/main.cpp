//
//  File: main.cpp
//  Project: Assignment05
//
//  Author:
//      Paulo Amaral on 2014-10-28
//      A00887758
//  Description:
//      Comp 2617 Assignment Code that reads in integers,
//      storing unique values between 10 and 100
//      and printing the unique values to the console
//

#include <iostream>
#include <array>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::setw;

// global constants for reuse
const char newline = '\n';
const char tab = '\t';
const int minimumValue = 10;
const int maximumValue = 100;
const size_t size = 20;

// function that prompts user for int input between 10 and 100
// and returns only valid value; accepts an int reference and
// uses the parameter to display the current number's count
int getUserInput(const int &count);

// function that accepts an array reference and an int
// reference and then iterates over array until
// reaching the index of the int parameter; during
// iteration, function prints each element in range in a 5 col table
void printResults(const array<int, size> &results, const int &lastInsertIndex);

int main() {
    
    array<int, size> uniqueIntegers; // hold unique ints
    int currentIndex = 0; // tracks the last insert position
    int count = 0; // tracks the number of values tested
    
    // algorithm for finding and storing unique values
    while (count < size) {
        int nextInt = getUserInput(count + 1);
        bool duplicate = false;
        for (int i = 0; i <= currentIndex; ++i) {
            if(uniqueIntegers[i] == nextInt) {
                duplicate = true;
                break;
            }
        }
        if(!duplicate) {
            cout << "The number: " << nextInt << " is unique" << endl;
            uniqueIntegers[currentIndex++] = nextInt;
        }
        cout << newline;
        ++count;
    }
    
    // show user the unique values
    printResults(uniqueIntegers, currentIndex);
    
    cout << newline;
    
    return 0;
} // end main

// function that prompts user for int input between 10 and 100
// and returns only valid value; accepts an int reference and
// uses the parameter to display the current number's count
int getUserInput(const int &count)
{
    int input = 0;
    cout << "Enter # " << count << " : ";
    cin >> input;

    while (cin.rdstate() || input < minimumValue || input > maximumValue) {
        cin.clear();
        cin.ignore(INT_MAX, newline);
        cout << "The number entered is not in the valid range of 10 to 100"
             << endl;
        cout << newline << "Enter # " << count << " : ";
        cin >> input;
    }
    return input;
} // end getUserInput

// function that accepts an array reference and an int
// reference and then iterates over array until
// reaching the index of the int parameter; during
// iteration, function prints each element in range in a 5 col table
void printResults(const array<int, size> &results, const int &lastInsertIndex)
{
    const int rowLen = 5;
    const int colWidth = 3;

    cout << "The unique numbers are: " << endl;
    for (int i = 0; i < lastInsertIndex; ++i) {
        if (i % rowLen == 0) {
            cout << newline << tab;
        }
        cout << setw(colWidth) << results[i] << setw(colWidth) << tab;
    }
} // end printResults
