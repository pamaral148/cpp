//
//  Hangman.cpp
//  Assignment08
//
//  Created by Paulo Amaral on 2015-03-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#include "Hangman.h"
#include <iostream>

const std::array<std::string, Hangman::string_count> Hangman::strings =
{
    "guess", "testing", "night", "floor", "house",
    "hangman", "school", "bottle", "clown", "library"
};

Hangman::Hangman() noexcept
: guess_count(0), has_won(false)
{
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<size_t> randomInt(0, (Hangman::string_count - 1));
    this->mystery_string = strings[randomInt(engine)];
}

const std::string Hangman::prompt = "Guess the word: ";

void Hangman::display_word() const noexcept
{
    std::cout << prompt;
    for(auto ch : this->mystery_string) {
        if(std::find(this->guesses.cbegin(), this->guesses.cend(), ch) != this->guesses.cend()) {
            std::cout << ch;
        } else {
            std::cout << placeholder;
        }
    }
    std::cout << std::endl;
}

bool Hangman::guess(const char letter) noexcept
{
    bool check = false;
    if(!has_guessed(letter)) {
        this->guesses.push_back(letter);
        ++this->guess_count;
        for(auto ch : mystery_string) {
            if(ch == letter) {
                return true;
            }
        }
    } else {
        std::cout << "Guessed already!\n";
        check = true;
    }
    return check;
}

bool Hangman::has_guessed(const char letter) const noexcept
{
    bool guessed = false;
    for(short i = 0; i < this->guesses.size(); ++i) {
        if(this->guesses.at(i) == letter) {
            guessed = true;
        }
    }
    return guessed;
}

bool Hangman::is_winner() noexcept
{
    this->has_won = true;
    for(auto ch : this->mystery_string) {
        if(std::find(this->guesses.cbegin(), this->guesses.cend(), ch) == this->guesses.cend()) {
            this->has_won = false;
        }
    }
    
    if(this->has_won) {
       std::cout << "Congratulations!!! You guessed my word. Play again? yes/no\n";
    }
    return this->has_won;
}
