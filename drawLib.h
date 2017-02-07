/*Name: drawLib.h
* Purpose: library of custom draw function declarations
* Due date: Dec 1 2016
* Author(s): Jaxon Lin
*/
#ifndef DRAWLIB_H
#define DRAWLIB_H
#include "mapLib.h"
static int score = 0;
static int combo = 0;

static long beatCountpx = 0;
static long beatRestpx = 0;
//draws 5x5 pixel square at (xco, yco)
void drawSquare(int xco, int yco);

void drawSquareBmap(TrackMap *tmap, int xco, int yco);
void drawLongHitBmap(TrackMap *tmap, int xco, int yco, int length);
void clearSquareBmap(TrackMap *tmap, int xco, int yco);
void clearHit(TrackMap *tmap, int xco, int yco);

//moves object (for now only square) from xco, yco by moveBy until
//x hits stop coordinate
void moveSquare(int xco, int yco, int moveBy, int stopco);

void drawWelcome();
int drawMenu();
int drawDiff();
void drawLoading();
void drawScore();
void lightUpAll(); // lights below switches all lights up
void lightOffAll(); // turns off
void lightUpInOrder();
void lightUpInOrderSlow();
void lightOffInOrder();
void lightApprove();
#endif
