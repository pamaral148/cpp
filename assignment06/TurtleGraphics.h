// Assignment 6 Solution: TurtleGraphics.h
// Declaration of class TurtleGraphics.
// Member functions are defined in TurtleGraphics.cpp.
// Author: Bob Langelaan 
// Date: Nov 7, 2013

#pragma once
#include <array>
#include <string>

class TurtleGraphics
{
private:
    
    const static std::string ERROR_MSG; // error message to use in switch statements
    const static size_t NROWS = 22;  // number of rows in floor
	const static size_t NCOLS = 70;  // number of colums in floor

	const static int STARTING_ROW = 0;    // row that turtle will start in
	const static int STARTING_COL = 0;    // column that turtle will start in
    const static int ARRAY_INDEX_OFFSET = 1; // value used to shift to 0-index of
    // array when bounds testing
    
    // direction constants using clock-face as notation
    const static unsigned short UP = 12;
    const static unsigned short RIGHT = 3;
    const static unsigned short DOWN = 6;
    const static unsigned short LEFT = 9;
    
    const static int STARTING_DIRECTION = DOWN; // direction that turtle
    // will be facing at the start
    // 6 as in 6 o'clock on an analog clock
    // The other 3 possible values are 3,9 and 12 o'clock
    
    const static bool STARTING_PEN_POSITION = false; // Pen will be up when
	                            // program starts
                                // false means pen up, true means pen down

	const static bool PEN_UP = false; // pen is up
	const static bool PEN_DOWN = true; // pen is down
    const static char EMPTY = ' '; // printed when pen up on col
    const static char FULL = '*'; // printed when pen down on col
    const static char NEWLINE = '\n'; // used for output formatting
    
    void displayFloor() const;  // will display floor on the screen

	// member data
    std::array <std::array <bool, NCOLS>, NROWS> m_Floor;   // floor on which turtle will draw
    int currentRow; // the current row position of the turtle
    int currentCol; // the current col position of the turtle
    bool penPosition; // whether the pen is down or not
    unsigned short currentDirection; // direction that the turtle is currently facing

public:
	const static int ARRAY_SIZE = 250;

	TurtleGraphics(void); //ctor will init. floor to all "false" values, 
	                      //     as well as initialization of other data members
	void processTurtleMoves( const std::array< int, ARRAY_SIZE> );  // will process
	                   // the commands contained in array "commands"	
};

// Define enum type that will be used in processTurtleMoves() switch statement

enum class Cmds : unsigned short { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9};
