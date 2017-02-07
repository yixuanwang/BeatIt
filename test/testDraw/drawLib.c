/*Name: drawLib.c
* Purpose: library of custom draw function implementations
* Due date: Dec 1 2016
* Author(s): Jaxon Lin
*/

#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include "drawLib.h"
#define SPEED_MS 100

void drawSquare(int xco, int yco) {
  OrbitOledSetDrawMode(modOledSet);
  for(int i = yco - 2; i <= yco + 2; i++) {
    for(int j = xco - 2; j <= xco + 2; j++) {
      OrbitOledMoveTo(j, i);
      OrbitOledDrawPixel(); 
    }
  }
  OrbitOledUpdate();
  delay(SPEED_MS);
}

void moveSquare(int xco, int yco, int moveBy, int stopco){
  while(xco > stopco) {
    drawSquare(xco, yco);
    xco += moveBy;
    OrbitOledClear();
  }
}