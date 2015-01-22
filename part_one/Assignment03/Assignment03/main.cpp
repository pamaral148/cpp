//
//  main.cpp
//  Assignment03
//
//  Description:
//      Assignment 03 multiplication application that quizes user on times tables using random numbers
//
//  Created by Paulo Amaral on 2014-10-09.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

// constant values for message functions
const unsigned short SCALING_FACTOR = 4,
                     SHIFTING_VALUE = 1,
                     ONE = 1,
                     TWO = 2,
                     THREE = 3,
                     FOUR = 4;

// multiplication function declaration
// asks user for the product of two random factors until user guesses correctly
// user can enter -1 to exit
void multiplication();

// declaration for function that displays one of four responses to a correct answer
// messages are randomly displayed
void correctMessage();

// declaration for function that displays one of four responses to an incorrect answer
// messages are randomly displayed
void incorrectMessage();

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    multiplication();
    
    return 0;
} // end main

// multiplication function implementation
// asks user for the product of two random factors until user guesses correctly
// user can enter -1 to exit
void multiplication()
{
    // function constants
    const short EXIT_VALUE = -1,
                SCALING_FACTOR = 10;
    const string PROMPT = "Enter a number to play the game, or -1 to exit: ";
    
    short continueGame = 0; // user input
    
    cout << PROMPT;
    cin >> continueGame;
    while (cin.rdstate()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << PROMPT;
        cin >> continueGame;
    }
    
    while (continueGame != EXIT_VALUE) {
        
        // declare constant values for loop
        const unsigned short FACTOR_ONE = rand() % SCALING_FACTOR,
                             FACTOR_TWO = rand() % SCALING_FACTOR,
                             PRODUCT = FACTOR_ONE * FACTOR_TWO;
        const string QUESTION = "How much is " + to_string(FACTOR_ONE) + " times " + to_string(FACTOR_TWO) + "? ";
        
        unsigned short answer = 0; // the answer provided by user
        
        cout << QUESTION;
        cin >> answer;
        while (cin.rdstate() || answer != PRODUCT) {
            incorrectMessage();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << QUESTION;
            cin >> answer;
        }
    
        correctMessage();
        cout << PROMPT;
        cin >> continueGame;
        while (cin.rdstate()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << PROMPT;
            cin >> continueGame;
        }
    }
    
} // end multiplication

// implementation for function that displays one of four responses to a correct answer
// messages are randomly displayed
void correctMessage()
{
    const unsigned short KEY = SHIFTING_VALUE + (rand() % SCALING_FACTOR);
    switch (KEY) {
        case ONE:
            cout << "Very good!" << endl;
            break;
        case TWO:
            cout << "Excellent!" << endl;
            break;
        case THREE:
            cout << "Nice work!" << endl;
            break;
        case FOUR:
            cout << "Keep up the good work!" << endl;
            break;
        default:
            break;
    }
} // end correctMessage

// implementation for function that displays one of four responses to an incorrect answer
// messages are randomly displayed
void incorrectMessage()
{
    const unsigned short KEY = SHIFTING_VALUE + (rand() % SCALING_FACTOR);
    switch (KEY) {
        case ONE:
            cout << "No, please try again." << endl;
            break;
        case TWO:
            cout << "Wrong. Try once more." << endl;
            break;
        case THREE:
            cout << "Don't give up!" << endl;
            break;
        case FOUR:
            cout << "No. Keep trying." << endl;
            break;
        default:
            break;
    }
} // end incorrectMessage