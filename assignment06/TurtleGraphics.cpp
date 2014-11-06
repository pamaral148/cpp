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

// ctor will init. floor to all "false" values,
// as well as initialization of other data members
TurtleGraphics::TurtleGraphics()
: currentRow(STARTING_ROW),
  currentCol(STARTING_COL),
  penPosition(STARTING_PEN_POSITION),
  currentDirection(STARTING_DIRECTION)
{
    for (auto row : m_Floor) {
        for (auto col : row) {
            col = false;
        }
    }
}

// processes the commands contained in array "commands"
void TurtleGraphics::processTurtleMoves( const array< int, ARRAY_SIZE> )
{
    ;
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
