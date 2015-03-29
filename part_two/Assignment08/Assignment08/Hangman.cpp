//
//  Hangman.cpp
//  Assignment08
//
//  Created by Paulo Amaral on 2015-03-28.
//  Copyright (c) 2015 pamaral. All rights reserved.
//

#include "Hangman.h"
#include <iostream>
#include <algorithm>

Hangman::Hangman() noexcept
: guess_count(0), wrong_guesses(0),
  has_won(false), has_lost(false)
{
    std::default_random_engine engine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<size_t> randomInt(0, (Hangman::string_count - 1));
    this->mystery_string = strings[randomInt(engine)];
    std::cout << prompt;
    for (short i = 0; i < this->mystery_string.size(); ++i) {
        std::cout << placeholder;
    }
    std::cout << std::endl;
}

const std::array<std::string, Hangman::string_count> Hangman::strings =
{
    "guess", "testing", "night", "floor", "house",
    "hangman", "school", "bottle", "clown", "library"
};

const std::string Hangman::prompt = "\nGuess the word: ";

const std::string Hangman::prompt_2 = "\nGuess a letter: ";

const std::string Hangman::your_guesses = "\nYour guesses:\n";

const std::string Hangman::you_lose = "\nSorry - you have run out of guesses :-(\nThe correct answer was: ";

const std::array<std::string, Hangman::max_guesses> Hangman::hangman =
{
    "\n 0 \n", "/", "|", "\\\n", " | \n", "/ ", "\\\n"
};

void Hangman::display_word() const noexcept
{
    std::cout << prompt_2;
    for(auto ch : this->mystery_string) {
        if(std::find(this->guesses.cbegin(), this->guesses.cend(), ch) != this->guesses.cend()) {
            std::cout << ch;
        } else {
            std::cout << placeholder_2;
        }
    }
    std::cout << std::endl;
    std::cout << placeholder_2;
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
    if(!check) {
        ++wrong_guesses;
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
    this->drawHangman();
    this->display_guesses();
    if(wrong_guesses >= max_guesses && !(this->has_won)) {
        this->has_lost = true;
        std::cout << you_lose;
        std::transform(this->mystery_string.begin(), this->mystery_string.end(),this->mystery_string.begin(), ::toupper);
        std::cout << this->mystery_string << std::endl;
        std::cout << "\n...GAME OVER...\n\nPlay again? (y/n)";
    } else {
        this->has_won = true;
        for(auto ch : this->mystery_string) {
            if(std::find(this->guesses.cbegin(), this->guesses.cend(), ch) == this->guesses.cend()) {
                this->has_won = false;
            }
        }
    
        if(this->has_won) {
            std::cout << "\nCongratulations!!! You guessed my word.\n\nPlay again? (y/n)";
        }
    }
    return this->has_won;
}
    
void Hangman::drawHangman() const noexcept
{
    for(short i = 0; i < wrong_guesses; ++i) {
        std::cout << hangman[i];
    }
}
    
void Hangman::display_guesses() const noexcept
{
    std::cout << your_guesses;
    for(auto ch : this->guesses) {
        putchar(toupper(ch));
        std::cout << " ";
    }
    std::cout << std::endl;
}
