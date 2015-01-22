//
//  Account.h
//  Comp 2617 Assignment01
//
//  Description:
//      Interface file for Assigment01 Account class that stores a current balance and can credit or debit the account
//
//  Created by Paulo Amaral on 2014-09-25
//

#ifndef __Assignment01__Account__
#define __Assignment01__Account__

#include <iostream>

class Account
{

public:
    // Constructor that takes an initial balance amount and initializes the account with the new balance
    // The client must submit a parameter that is greater than or equal to 0
    // If input is invalid, 0 is used as the default and a message is logged to cerr
    explicit Account(int amount);
    
    // Returns the current balance on the account
    int getBalance() const;
    
    // Credits the account balance the amount passed in; client must submit a value greater than 0
    // If invalid input is used, a message is logged to cerr and the function does not change the balance
    void credit(int amount);
    
    // Debits the account balance the amount passed in; the client must submit a value between 0 and the current balance
    // If invalid input is used, a message is logged to cerr and the function does not change the balance
    void debit(int amount);

private:
    // The current balance on the account; cannot be less than 0
    // The value can be read by an accessor, but cannot be directly set; to update the balance, clients must
    // use the debit or credit functions
    int balance;

};

#endif /* defined(__Assignment01__Account__) */
