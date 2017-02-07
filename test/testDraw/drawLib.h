/*Name: drawLib.h
* Purpose: library of custom draw function declarations
* Due date: Dec 1 2016
* Author(s): Jaxon Lin
*/
#ifndef DRAWLIB_H
#define DRAWLIB_H
//draws 5x5 pixel square at (xco, yco)
void drawSquare(int xco, int yco);

//moves object (for now only square) from xco, yco by moveBy until
//x hits stop coordinate
void moveSquare(int xco, int yco, int moveBy, int stopco);

#endif
