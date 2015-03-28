//
//  main.cpp
//  Assignment08
//
//  Created by Paulo Amaral on 2015-03-28.
//  Hangman game created for comp 2618 assignment 08
//

#include <iostream>
#include "Hangman.h"

int main() {
    
    Hangman game = Hangman();
    
    while (!game.is_winner()) {
        char guess;
        game.display_word();
        std::cin >> guess;
        game.guess(guess);
    }
    
    if(game.is_winner()) {
        
    }
}
