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


/*void setup() {
  Serial.begin(9600);
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();

}*/

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

  TrackMap *testMap = malloc(sizeof(testMap));
  createTestMap(testMap, 128);
/*  for(int j = 0; j < 128; j += 10) {
    for(int i = 0; i < 32; i++) {
      testMap.bmap[j][i] = '1'; 
    }
  }*/
  //drawMap(testMap.mlength, testMap.bmap);
  char test2Map[128][32] = {0};
  for(int j = 0; j < 128; j += 10) {
    for(int i = 0; i < 32; i++) {
      test2Map[j][i] = '1'; 
    }
  }
  drawMap(test2Map, 128);


  drawInGameUI();
  
  OrbitOledUpdate();
  delay(SPEED_MS * 100);
  
}