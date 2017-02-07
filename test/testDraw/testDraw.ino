#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include "drawLib.h"
#include "mapLib.h"
#define SPEED_MS 100




void setup() {
  Serial.begin(9600);
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();

}

/*
void loop(){
//  int xco, yco;
//  xco = 125;
//  yco = 3;

//  moveObject(125, 6, -5, 0);
//  delay(SPEED_MS);
//  moveObject(125, 13, -5, 0);
//  moveObject(125, 17, -5, 0);
//  delay(SPEED_MS);
//  moveObject(125, 21, -5, 0);

  int testMap[128][32] = {0};
  for(int i = 0; i < 32; i++) {
    testMap[0][i] = 1;
  }

  drawMap(testMap, 128, 32);
  
}

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

void moveObject(int xco, int yco, int moveBy, int stopco){
  while(xco > stopco) {
    drawSquare(xco, yco);
    xco += moveBy;
    OrbitOledClear();
  }
}
void drawMap(int bmap[128][32], int mlength, int width) {
  int mapx, mapy, onscreenL, drawxco;
  for(mapx = 0; mapx < mlength; mapx++) {
    for(mapy = 0; mapy < width  ; mapy++) {
      if(mapx > SCREENLENGTH) {
        drawxco = ULCORNERX - mapx + 32;
      }
      else {
        drawxco = ULCORNERX - mapx;
      }
      if(bmap[mapx][mapy] == 1) {
        OrbitOledMoveTo(drawxco, mapy);
        OrbitOledDrawPixel();
      }
    }
    OrbitOledUpdate();
    delay(SPEED_MS);
    OrbitOledClear();
  }
}*/

