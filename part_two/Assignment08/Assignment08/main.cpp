//
//  main.cpp
//  Assignment08
//
//  Created by Paulo Amaral on 2015-03-28.
//  Hangman game driver created for
//  comp 2618 assignment 08
//

#include <iostream>
#include "Hangman.h"

int main() {
    
    bool play_again = true;
    const std::string yes = "y";
    const std::string no = "n";

    while (play_again) {
        Hangman game = Hangman();
        std::string answer;
        while (!game.is_winner() && !game.is_loser()) {
            char guess;
            game.display_word();
            std::cin >> guess;
            game.guess(guess);
        }
        do {
            std::cin >> answer;
        } while(!std::cin.fail() && answer != yes && answer != no);
            
        if(answer == yes) {
            play_again = true;
        } else if(answer == no) {
            play_again = false;
        }
    }
    
}
