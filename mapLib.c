/*Name: mapLib.c
* Purpose: library of custom map function
* 		   implementations
* Due date: Dec 1 2016
* Author(s): Yixuan Wang, Jaxon Lin
*/

/*
	TODO:
				-create trackmaps
 */

#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include <time.h>
#include "mapLib.h"
#include "inputLib.h"
#include "drawLib.h"
#define SPEED_MS 10
//#define tick 0

void drawMap(char bmap[][32], int mlength) {
	OrbitOledClear();
	int mapx, mapy, onscreenL, leftmostxco, drawxco;
	for(onscreenL = 1; onscreenL <= mlength; onscreenL++) {
    OrbitOledClear();
    drawInGameUI();
    leftmostxco = (onscreenL - SCREENLENGTH <= 0)? 0 : (onscreenL - SCREENLENGTH);
    for(mapx = onscreenL - 1; mapx >= leftmostxco; mapx--) {
      for(mapy = 0; mapy < SCREENWIDTH; mapy++) {
        if(bmap[mapx][mapy] == '1') {
          drawxco = SCREENLENGTH - (onscreenL - mapx);
          OrbitOledMoveTo(drawxco, mapy);
          OrbitOledDrawPixel();
        }
      }
    }
    OrbitOledUpdate();
    delay(SPEED_MS);
  }
}


//does not update (shouldn't, because other fcts are updating)
void drawInGameUI() {
	//hitlines
	OrbitOledMoveTo(9, 6);
	OrbitOledLineTo(9, 30);
	OrbitOledMoveTo(15, 6);
	OrbitOledLineTo(15, 30);

	//3 beat tracklines
	OrbitOledMoveTo(0, 6);
	OrbitOledLineTo(127, 6);
	OrbitOledMoveTo(0, 14);
	OrbitOledLineTo(127, 14);
	OrbitOledMoveTo(0, 22);
	OrbitOledLineTo(127, 22);
	OrbitOledMoveTo(0, 30);
	OrbitOledLineTo(127, 30);

}

void createMap(TrackMap *tmap, int mlength) {
	tmap -> mlength = mlength;
}
//TODO
void createTestBeatMap(TrackMap *tmap, int mlength) {
	tmap -> mlength = mlength;
  for(int j = 0; j < mlength; j++) {
    for(int i = 0; i < 32; i++) {
      tmap -> bmap[j][i] = '0';
    }
  }

  for(int i = 8; i < mlength - 128 - 5; i+= 20) {
    drawSquareBmap(tmap, i, 10);
  }
}

void createTestMap(TrackMap *tmap, int mlength) {
	tmap -> mlength = mlength;
	for(int j = 0; j < mlength; j++) {
		for(int i = 0; i < 32; i++) {
			tmap -> bmap[j][i] = '0';
		}
	}
	for(int j = 0; j < 128; j += 10) {
    for(int i = 6; i < 31; i++) {
      tmap -> bmap[j][i] = '1'; 
    }
  }
}


void createTestMap3(TrackMap *tmap, int mlength) {
  tmap -> mlength = mlength;
  for(int j = 0; j < mlength; j++) {
    for(int i = 0; i < 32; i++) {
      tmap -> bmap[j][i] = '0';
    }
  }
  for(int i = 13; i < mlength - 128 - 5; i+= 20) {
    drawSquareBmap(tmap, i, 10);
  }

  for(int i = 23; i < mlength - 128 - 5; i+= 40) {
    drawLongHitBmap(tmap, i, MIDHITCENTREY, 4);
  }
  for(int i = 33; i < mlength - 128 - 5; i+= 20) {
    drawSquareBmap(tmap, i, BOTHITCENTREY);
  }
}



/* trackMap -> int mlength;	int bmap[][32] */

void drawGame(TrackMap *tmap, int mlength, int diff) {
  OrbitOledClear();
  int mapx, mapy, onscreenL, leftmostxco, drawxco;

  for(onscreenL = 1; onscreenL <= mlength; onscreenL++) {
    /*time_t lastFrameUpdate = 0;
    time_t currentFrameTime;
    time(&currentFrameTime);
    double frameDifferenceMS = difftime(currentFrameTime, lastFrameUpdate) / 1000.0;*/
    //unsigned long lastFrameUpdate = 0;
    //if(frameDifferenceMS >= 100) {
      leftmostxco = (onscreenL - SCREENLENGTH <= 0)? 0 : (onscreenL - SCREENLENGTH);
      OrbitOledClearBuffer();
      drawInGameUI();
    	for(mapx = onscreenL - 1; mapx >= leftmostxco; mapx--) {
        for(mapy = 0; mapy < SCREENWIDTH; mapy++) {
          if(tmap -> bmap[mapx][mapy] == '1') {
            drawxco = SCREENLENGTH - (onscreenL - mapx);
            OrbitOledMoveTo(drawxco, mapy);
            OrbitOledDrawPixel();
          }
        }
      }
      OrbitOledUpdate();
      readInput();
      checkOutput(tmap, leftmostxco, diff);
      //delay(SPEED_MS);
    //}
  }
}


void createDemoMap(TrackMap *tmap, int mlength) {
  tmap -> mlength = mlength;
  int cxco = 13;


  for(int j = 0; j < mlength; j++) {
    for(int i = 0; i < 32; i++) {
      tmap -> bmap[j][i] = '0';
    }
  }
  // (** **)
  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  cxco += 5;

  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  cxco += 20;

  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  cxco += 5;

  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  //(** ** )end
  cxco += 10;
  //(=======)
  drawLongHitBmap(tmap, cxco, MIDHITCENTREY, 10);
  cxco += 50;
  //. ' . ' .
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  cxco += 5;
  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  cxco += 5;
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);
  cxco += 5;
  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  cxco += 5;
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);

  cxco += 15;

  drawLongHitBmap(tmap, cxco, TOPHITCENTREY, 7);
  drawLongHitBmap(tmap, cxco, BOTHITCENTREY, 7);

  cxco += 38;

  drawSquareBmap(tmap, cxco, TOPHITCENTREY);
  drawSquareBmap(tmap, cxco, BOTHITCENTREY);

  cxco += 15;

  

  /*for(int i = 13; i < mlength - 128 - 5; i+= 20) {
    drawSquareBmap(tmap, i, 10);
  }

  for(int i = 23; i < mlength - 128 - 5; i+= 40) {
    drawLongHitBmap(tmap, i, MIDHITCENTREY, 4);
  }
  for(int i = 33; i < mlength - 128 - 5; i+= 20) {
    drawSquareBmap(tmap, i, BOTHITCENTREY);
  }*/
}
