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
    while (nextCommand != Cmds::END_OF_DATA && index < ARRAY_SIZE) {
        short numberOfSteps = 0;
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
                        cerr << ERROR_MSG << " TURNING RIGHT";
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
                        cerr << ERROR_MSG << " TURNING LEFT";
                        break;
                }
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            case Cmds::MOVE:
                numberOfSteps = commands[index + 1];
                switch (currentDirection) {
                    case UP:
                        if((currentRow - numberOfSteps) < 0) {
                            numberOfSteps = currentRow;
                        }
                        if (penPosition == PEN_DOWN) {
                            for (int i = currentRow, j = 0; j < numberOfSteps; --i, ++j) {
                                m_Floor[i][currentCol] = PEN_DOWN;
                            }
                        }
                        currentRow -= numberOfSteps;
                        break;
                    case RIGHT:
                        if ((currentCol + numberOfSteps) >= NCOLS) {
                            numberOfSteps = (NCOLS - currentCol) - ARRAY_INDEX_OFFSET;
                        }
                        if (penPosition == PEN_DOWN) {
                            for (int i = currentCol, j  = 0; j < numberOfSteps; ++i, ++j) {
                               m_Floor[currentRow][i] = PEN_DOWN;
                            }
                        }
                        currentCol += numberOfSteps;
                        break;
                    case DOWN:
                        if ((currentRow + numberOfSteps) >= NROWS) {
                            numberOfSteps = (NROWS - currentRow) - ARRAY_INDEX_OFFSET;
                        }
                        if (penPosition == PEN_DOWN) {
                            for (int i = currentRow, j = 0; j < numberOfSteps; ++i, ++j) {
                                m_Floor[i][currentCol] = PEN_DOWN;
                            }
                        }
                        currentRow += numberOfSteps;
                        break;
                    case LEFT:
                        if ((currentCol - numberOfSteps) < 0) {
                            numberOfSteps = currentCol;
                        }
                        if (penPosition == PEN_DOWN) {
                            for (int i = currentCol, j = 0; j < numberOfSteps; --i, ++j) {
                               m_Floor[currentRow][i] = PEN_DOWN;
                            }
                        }
                        currentCol -= numberOfSteps;
                        break;
                    default:
                        break;
                }
                index += 2;
                nextCommand = static_cast<Cmds>(commands[index]);
                break;
            case Cmds::DISPLAY:
                displayFloor();
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
            default:
                cerr << ERROR_MSG << " PROCESSING CMD:" << static_cast<unsigned int>(nextCommand) << "\n";
                nextCommand = static_cast<Cmds>(commands[++index]);
                break;
        }
    }
}

// displays floor on the screen
void TurtleGraphics::displayFloor() const
{
    for(auto row : m_Floor) {
        for(auto col : row) {
            if(col == PEN_DOWN) {
                cout << FULL;
            } else {
                cout << EMPTY;
            }
        }
        cout << NEWLINE;
    }
}
