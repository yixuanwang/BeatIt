#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include "inputLib.h"
#include "drawLib.h"
#include "mapLib.h"
#define SPEED_MS 100

void loop(){
  
  drawWelcome();
  while(isInGame()) {
  	
    
    int track = drawMenu();
    int difficulty = drawDiff();

    TrackMap *testMap = malloc(sizeof(testMap));
    switch(track){
      case 1:
        createTestMap3(testMap, 712);
        break;
      case 2:
        createDemoMap(testMap, 360);
        break;
      default:
        break;
    }
  	drawLoading();
    drawGame(testMap, testMap -> mlength, difficulty);
    drawScore();
    
  
    free(testMap);
  }
  
}
