//
//  main.cpp
//  assignment07
//
//  Created by Paulo Amaral on 2014-11-13.
//  Main function for assignment06 application
//
//  Runs a race between a tortoise and hare by
//  moving each animal along a track at one second
//  intervals until one of the animals raeches the
//  end; track is slippery so animals may move
//  forward or back depending on chance

#include <iostream>
#include <array>
#include <random>
#include <string>
#include <unistd.h>

const size_t SIZE = 70;
const short START_POSITION = 1;
const unsigned short FLOOR = 1;
const unsigned short CEILING = 10;
const std::string START_TEXT = "ON YOUR MARK, GET SET\nBANG\t\t\t   !!!!\nAND THEY'RE OFF\t   !!!!";
const char TORTOISE = 'T';
const char HARE = 'H';
const char BLANK = ' ';
const std::string HIT = "OUCH!!!";
const std::string HARE_WINS = "\nHare Wins. Yuch.";
const std::string TORTOISE_WINS = "\nTORTOISE WINS!!! YAY!!!";
const std::string TIE = "\nTie!";
const int DELAY_MICROSECONDS = 1000000;

// accepts an array references and initializes
// track array with positions starting at 1
void initTrack(std::array<int, SIZE> &track);

// accepts a reference to the tortoise's current
// position on the track and moves it along
// the track accroding to the random int
void moveTortoise(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track);

// accepts a reference to the hare's current
// position on the track and moves it
// along the track accroding to the random int
void moveHare(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track);

// checks if the runner has reached the
// finish line and returns true if yes
bool isWinner(const int &currentPosition);

int main() {
    
    // initialize track and random engine
    std::default_random_engine engine( static_cast<int>( time(0) ) );
    std::uniform_int_distribution<int> randomInt(FLOOR, CEILING);
    std::array<int, SIZE> track; // the race track
    initTrack(track);
    
    int tortoisePosition = track.front();
    int harePosition = track.front();
    
    std::cout << START_TEXT << std::endl;
    int numSeconds = 0;
    while (!isWinner(tortoisePosition) && !isWinner(harePosition)) {
        int random = randomInt(engine);
        moveTortoise(tortoisePosition, random, track);
        moveHare(harePosition, random, track);
        for(auto step : track) {
            if (step == tortoisePosition || step == harePosition) {
                if (tortoisePosition == harePosition) {
                    std::cout << HIT;
                } else {
                    if(step == tortoisePosition) {
                        std::cout << TORTOISE;
                    }
                    if(step == harePosition) {
                        std::cout << HARE;
                    }
                }
            } else {
                std::cout << BLANK;
            }
        }
        std::cout << std::endl;
        usleep(DELAY_MICROSECONDS);
        ++numSeconds;
    }
    
    if(isWinner(tortoisePosition)) {
        std::cout << TORTOISE_WINS << std::endl;
    } else if(isWinner(harePosition)) {
        std::cout << HARE_WINS << std::endl;
    } else {
        std::cout << TIE << std::endl;
    }
    std::cout << "\nTIME ELAPSED = " << numSeconds << " seconds" << std::endl;
    return 0;
}

// accepts an array references and initializes
// track array with positions starting at 1
void initTrack(std::array<int, SIZE> &track)
{
    int position = START_POSITION;
    for (int &i : track) {
        i = position++;
    }
}

// checks if the runner has reached the
// finish line and returns true if yes
bool isWinner(const int &currentPosition)
{
    return currentPosition == SIZE;
}

// accepts a reference to the tortoise's current
// position on the track and moves it along
// the track accroding to the random int
void moveTortoise(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track)
{
    const short slowPlod = 1;
    const short fastPlod = 3;
    const short slip = 6;
    const std::string error = "Error: reached the default case of the tortoise's switch";
    
    switch (randomInt) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (currentPosition + fastPlod > track.size()) {
                currentPosition = track.back();
            } else {
                currentPosition = track.at(--currentPosition + fastPlod);
            }
            break;
        case 6:
        case 7:
            if(currentPosition - slip < track.front()) {
                currentPosition = track.front();
            } else {
                currentPosition = track.at(--currentPosition - slip);
            }
            break;
        case 8:
        case 9:
        case 10:
            currentPosition += slowPlod;
            break;
        default:
            std::cerr << error;
            break;
    }
}

// accepts a reference to the hare's current
// position on the track and moves it
// along the track accroding to the random int
void moveHare(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track)
{
    const short bigHop = 9;
    const short bigSlip = 12;
    const short smallHop = 1;
    const short smallSlip = 2;
    const std::string error = "Error: reached the default case of the hare's switch";
    
    switch (randomInt) {
        case 1:
        case 2:
            // sleeping
            break;
        case 3:
        case 4:
            if (currentPosition + bigHop > track.size()) {
                currentPosition = track.back();
            } else {
                currentPosition = track.at(--currentPosition + bigHop);
            }
            break;
        case 5:
            if(currentPosition - bigSlip < track.front()) {
                currentPosition = track.front();
            } else {
                currentPosition = track.at(--currentPosition - bigSlip);
            }
            break;
        case 6:
        case 7:
        case 8:
            currentPosition += smallHop;
            break;
        case 9:
        case 10:
            if(currentPosition - smallSlip < track.front()) {
                currentPosition = track.front();
            } else {
                currentPosition = track.at(--currentPosition - smallSlip);
            }
            break;
        default:
            std::cerr << error;
            break;
    }
}