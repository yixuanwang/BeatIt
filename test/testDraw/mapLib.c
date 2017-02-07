/*Name: mapLib.c
* Purpose: library of custom map function
* 		   implementations
* Due date: Dec 1 2016
* Author(s): Jaxon Lin
*/

/*
		TODO:
				-make drawMap move whole map to end
				-create start screen ui
				-create song select ui
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
#include "mapLib.h"
#define SPEED_MS 100


void drawMap(char **bmap, int mlength) {
	OrbitOledClear();
	int mapx, mapy, onscreenL, leftmostxco, drawxco;
	for(onscreenL = 1; onscreenL <= mlength; onscreenL++) {
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

	for(int j = 0; j < mlength; j += 10) {
    for(int i = 0; i < 32; i++) {
      tmap -> bmap[j][i] = '1'; 
    }
  }
}


void createTestMap(TrackMap *tmap, int mlength) {
	tmap -> mlength = mlength;

	for(int j = 0; j < mlength; j += 10) {
    for(int i = 0; i < 32; i++) {
      tmap -> bmap[j][i] = '1'; 
    }
  }
}


/* trackMap -> int mlength;	int bmap[][32] */
