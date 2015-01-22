//
//  main.cpp
//  Assignment02 for Comp 2617
//
//  Created by Paulo Amaral on 2014-10-02.
//

#include <iostream>
#include <iomanip>

using namespace std;

const long double MIN_TERM = 1.0E-20; // minimum term result to kill loop in part 3 function

long long computeFactorial(int base); // factorial computing function for part 1

double computeConstantE(int termCount); // fuction that computes the constant e to the desired accuracy for part 2

long double computeConstantERaised(int power); // function that computes e raised to the specified power for part 3

int main() {
    
     /* Part I of Assignment 02
     ===============================
     */
     
    int base = 0; // stores user input for factorial calculation
    
    cout << "Enter an integer between 0 and 20: ";
    cin >> base;
    while (cin.rdstate() || base < 0 || base > 20) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter an integer between 0 and 20: ";
        cin >> base;
    }
    cout << base << "!: " << computeFactorial(base) << endl;
    
    /*
    Part II of Assignment 02
    ===============================
    */
    
    
    int termCount = 0; // the number of terms to include (the precision) in the calculation of e
    
    cout << "The number of terms to compute is (5 to 13 are valid values): ";
    cin >> termCount;
    while (cin.rdstate() || termCount < 5 || termCount > 13) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The number of terms to compute is (5 to 13 are valid values): ";
        cin >> termCount;
    }
    
    cout << setprecision(12);
    cout << "The value of e is: " << computeConstantE(termCount) << endl;
    
    /*
    Part III of Assignment 02
    ===============================
    */
    
    int power = 0; // the power to raise e to in function that calculates e raised to x
    
    cout << "Input a value for the power between 1 and 709: ";
    cin >> power;
    while (cin.rdstate() || power < 1 || power > 709) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Input a value for the power between 1 and 709: ";
        cin >> power;
    }
    
    cout << setprecision(12);
    cout << "e raised to the " << power << " power is " << computeConstantERaised(power) << endl;

    return 0;
    
} // end main

// factorial computing function implementation for part 1
// uses loop algorithm to calculate factorial for base parameter
// input must be between 0 and 20 to have meaningful output
long long computeFactorial(int base)
{
    long long factorial = base; // the factorial that is returned at the end of the function
    
    if (base == 0) {
        factorial = 1;
    } else {
        for (int i = base - 1; i > 0; --i) {
            factorial *= i;
        }
    }
    
    return factorial;
    
} // end computeFactorial function

// function that calculates the constant e for part 2
// client must provide the number of terms to use when approximating e
double computeConstantE(int termCount)
{
    double constantE = 1.0;
    long long nextFactorial = 1.0;
    
    for (int i = 0; i < termCount; ++i) {
        constantE += 1 / ((static_cast<double>(i) + 1) * nextFactorial);
        nextFactorial = (static_cast<double>(i) + 1) * nextFactorial;
    }
    
    return constantE;
    
} // end computeConstantE function

// function to compute e raised to power for part 3
// client must provide the power to raise e to
long double computeConstantERaised(int power)
{
    long double result = 0;
    long double term = 1.0;

    for (int i = 1; term >= MIN_TERM; ++i) {
        result += term;
        term = term * power / i;
    }
    
    return result;
    
} // end compute e to power of function
