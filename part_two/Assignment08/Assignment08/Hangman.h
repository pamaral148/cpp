//
//  Hangman.h
//  Assignment08
//
//  Created by Paulo Amaral on 2015-03-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#ifndef __Assignment08__Hangman__
#define __Assignment08__Hangman__

#include <stdio.h>
#include <string>
#include <array>
#include <random>
#include <vector>

class Hangman
{
public:
    
    // default ctor that sets game object to valid state
    Hangman() noexcept;
    // displays the mystery word on the console
    void display_word() const noexcept;
    // prompts player for a guess and evaluates the guess
    bool guess(const char letter) noexcept;
    // updates has_won if player has won
    bool is_winner() noexcept;
    // updates has_won if player has lost
    bool is_loser() const noexcept { return this->has_lost; }
    
private:
    
    /*
     const static classwide data
     */
    // the size of the string pool for the game
    const static int string_count = 10;
    // the number of guesses allowed
    const static int max_guesses = 7;
    // a placeholder for unguessed chars
    const static char placeholder = 'X';
    // a placeholder for unguessed chars
    const static char placeholder_2 = '?';
    // the container that holds all possible strings for the game
    const static std::array<std::string, string_count> strings;
    // the array of hangman chars
    const static std::array<std::string, max_guesses> hangman;
    // the prompt before displaying the word
    const static std::string prompt;
    // the prompt before displaying the word
    const static std::string prompt_2;
    // the prompt before displaying the guesses
    const static std::string your_guesses;
    // the message when player loses
    const static std::string you_lose;
    
    /*
     object data and methods
     */
    // draws the hangman figure
    void drawHangman() const noexcept;
    // displays guesses in console
    void display_guesses() const noexcept;
    // returns true if the player has already guessed this char
    bool has_guessed(const char letter) const noexcept;
    // the current string the player must guess
    std::string mystery_string;
    // the total number of guesses the player has taken
    int guess_count;
    // the number of incorrect guesses
    int wrong_guesses;
    // the collection of chars the user has guessed
    std::vector<char> guesses;
    // has the user won?
    bool has_won;
    // has the user lost?
    bool has_lost;
};

#endif /* defined(__Assignment08__Hangman__) */
