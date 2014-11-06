//
//  TurtleGraphics.cpp
//  assignment06
//
//  Created by Paulo Amaral on 2014-11-06.
//  Copyright (c) 2014 a00887758. All rights reserved.
//

#include <iostream>
#include "TurtleGraphics.h"

using std::array;
using std::cout;
using std::cerr;
using std::string;

// error message to use in switch statements
const string TurtleGraphics::ERROR_MSG = "WARNING: Reached default case of switch";

// ctor will init. floor to all "false" values,
// as well as initialization of other data members
TurtleGraphics::TurtleGraphics()
: currentRow(STARTING_ROW),
  currentCol(STARTING_COL),
  penPosition(STARTING_PEN_POSITION),
  currentDirection(STARTING_DIRECTION)
{
    for (auto &row : m_Floor) {
        for (auto &col : row) {
            col = false;
        }
    }
}

// processes the commands contained in array "commands"
void TurtleGraphics::processTurtleMoves( const array< int, ARRAY_SIZE> commands )
{
    int index = 0;
    Cmds nextCommand = static_cast<Cmds>(commands[index]);
    while (nextCommand != Cmds::END_OF_DATA) {
        switch (nextCommand) {
            case Cmds::PEN_UP:
                penPosition = PEN_UP;
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            case Cmds::PEN_DWN:
                penPosition = PEN_DOWN;
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            case Cmds::TURN_RIGHT:
                switch (currentDirection) {
                    case UP:
                        currentDirection = RIGHT;
                        break;
                    case RIGHT:
                        currentDirection = DOWN;
                        break;
                    case DOWN:
                        currentDirection = LEFT;
                        break;
                    case LEFT:
                        currentDirection = UP;
                        break;
                    default:
                        cerr << ERROR_MSG;
                        break;
                }
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            case Cmds::TURN_LEFT:
                switch (currentDirection) {
                    case UP:
                        currentDirection = LEFT;
                        break;
                    case RIGHT:
                        currentDirection = UP;
                        break;
                    case DOWN:
                        currentDirection = RIGHT;
                        break;
                    case LEFT:
                        currentDirection = DOWN;
                        break;
                    default:
                        cerr << ERROR_MSG;
                        break;
                }
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            case Cmds::MOVE:
                // todo: implement movement and drawing
                cout << "Moving " << commands[index + 1] << " spaces\n";
                index += 2;
                nextCommand = static_cast<Cmds>(commands[index]);
                break;
            case Cmds::DISPLAY:
                displayFloor();
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            default:
                cerr << ERROR_MSG;
                break;
        }
    }
}

// displays floor on the screen
void TurtleGraphics::displayFloor() const
{
    for(auto row : m_Floor) {
        for(auto col : row) {
            if(col == true) {
                cout << FULL;
            } else {
                cout << EMPTY;
            }
        }
        cout << NEWLINE;
    }
}
