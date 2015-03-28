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
    Hangman() noexcept;
    void display_word() const noexcept;
    bool guess(const char letter) noexcept;
    int get_guess_count() const noexcept { return guess_count; }
    // updates has_won if player has won
    bool is_winner() noexcept;
private:
    // returns true if the player has already guessed this char
    bool has_guessed(const char letter) const noexcept;
    // the size of the string pool for the game
    const static int string_count = 10;
    // the number of guesses allowed
    const static int max_guesses = 7;
    // the placeholder for unguessed chars
    const static char placeholder = 'X';
    // the container that holds all possible strings for the game
    const static std::array<std::string, string_count> strings;
    // the prompt before displaying the word
    const static std::string prompt;
    // the current string the player must guess
    std::string mystery_string;
    // the number of guesses the player has taken
    int guess_count;
    // the collection of chars the user has guessed
    std::vector<char> guesses;
    // has the user won?
    bool has_won;
};

#endif /* defined(__Assignment08__Hangman__) */
