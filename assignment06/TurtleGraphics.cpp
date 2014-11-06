//
//  TurtleGraphics.cpp
//  assignment06
//
//  Created by Paulo Amaral on 2014-11-06.
//  Copyright (c) 2014 a00887758. All rights reserved.
//

#include <stdio.h>
#include "TurtleGraphics.h"

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
    };
}

