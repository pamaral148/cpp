//
//  main.cpp
//  assignment07
//
//  Created by Paulo Amaral on 2014-11-13.
//  Main function for assignment06 application
//

#include <iostream>
#include <array>
#include <random>
#include <string>

const size_t SIZE = 70;
const short START_POSITION = 1;
const short OFFSET = 1;
const unsigned short FLOOR = 1;
const unsigned short CEILING = 10;

// accepts an array references and initializes
// track array with positions starting at 1
void initTrack(std::array<int, SIZE> &track);

// accepts a reference to the tortoise's current
// position on the track and moves it animal
// along the track
void moveTortoise(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track);

// accepts a reference to the hare's current
// position on the track and moves it
// animal along the track
void moveHare(int &currentPosition, const int &randomInt, const std::array<int, SIZE> &track);

bool isWinner(const int &currentPosition);

int main() {
    
    // initialize track and random engine
    std::default_random_engine engine( static_cast<int>( time(0) ) );
    std::uniform_int_distribution<int> randomInt(FLOOR, CEILING);
    std::array<int, SIZE> track; // the race track
    initTrack(track);
    
    int tortoisePosition = track.at(START_POSITION - OFFSET);
    int harePosition = track.at(START_POSITION - OFFSET);
    
    while (!isWinner(tortoisePosition) && !isWinner(harePosition)) {
        moveTortoise(tortoisePosition, randomInt(engine), track);
        moveHare(harePosition, randomInt(engine), track);
        std::cout << "Tortoise at: " << tortoisePosition << std::endl;
        std::cout << "Hare at: " << harePosition << std::endl;
    }
    
    if(isWinner(tortoisePosition)) {
        std::cout << "Tortoise wins!" << std::endl;
    } else if(isWinner(harePosition)) {
        std::cout << "Hare wins!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }
    
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

bool isWinner(const int &currentPosition)
{
    return currentPosition == SIZE;
}

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
            if (currentPosition + fastPlod > SIZE) {
                currentPosition = track.at(SIZE - OFFSET);
            } else {
                currentPosition = track.at((currentPosition - OFFSET) + fastPlod);
            }
            break;
        case 6:
        case 7:
            if(currentPosition - currentPosition - slip < START_POSITION) {
                currentPosition = track.at(START_POSITION - OFFSET);
            } else {
                currentPosition = track.at((currentPosition - OFFSET) - slip);
            }
            break;
        case 8:
        case 9:
        case 10:
            currentPosition = track.at((currentPosition - OFFSET) + slowPlod);
            break;
        default:
            std::cerr << error;
            break;
    }
}

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
            if (currentPosition + bigHop > SIZE) {
                currentPosition = track.at(SIZE - OFFSET);
            } else {
                currentPosition = track.at((currentPosition - OFFSET) + bigHop);
            }
            break;
        case 5:
            if(currentPosition - bigSlip < START_POSITION) {
                currentPosition = track.at(START_POSITION - OFFSET);
            } else {
                currentPosition = track.at((currentPosition - OFFSET) - bigSlip);
            }
            break;
        case 6:
        case 7:
        case 8:
            currentPosition = track.at((currentPosition - OFFSET) + smallHop);
            break;
        case 9:
        case 10:
            if(currentPosition - smallSlip < START_POSITION) {
                currentPosition = track.at(START_POSITION - OFFSET);
            } else {
                currentPosition = track.at((currentPosition - OFFSET) - smallSlip);
            }
            break;
        default:
            std::cerr << error;
            break;
    }
}