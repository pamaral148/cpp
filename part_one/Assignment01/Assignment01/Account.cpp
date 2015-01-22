//
//  Account.cpp
//  Comp 2617 Assignment01
//
//  Description:
//      Implementation file for Assigment01 Account class that stores a current balance and can credit or debit the account
//
//  Created by Paulo Amaral on 2014-09-25.
//

#include "Account.h"

using namespace std;

Account::Account(int amount)
    : balance(amount)
{
    // if amount is less than 0 set balance to 0 and log error, otherwise do nothing
    if (amount < 0) {
        balance = 0;
        cerr << "Balance cannot be less than 0, balance set to 0 (input=" << amount << ")" << endl;
    }
}

int Account::getBalance() const
{
    return balance;
}

void Account::credit(int amount)
{
    if (amount > 0) {
        balance += amount;
    } else {
        cerr << "Credit amount must be greater than 0 (input=" << amount << ")" << endl;
    }
}

void Account::debit(int amount)
{
    // validate each input condition (<= 0 | > balance) separately so that appropriate error message can be logged
    if (amount <= 0) {
        cerr << "Debit amount must be greater than 0 (input=" << amount << ")" << endl;
    } else if (amount > balance) {
        cerr << "Debit amount must be less than current balance (input=" << amount << ")" << endl;
    } else {
        balance -= amount;
    }
}
