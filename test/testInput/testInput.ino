#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include "inputLib.h"



void setup(){
  Serial.begin(9600);
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();  
  pinMode(button1.port, INPUT_PULLDOWN);
  pinMode(button2.port, INPUT_PULLDOWN);
  pinMode(button3.port, INPUT_PULLUP);
  pinMode(button4.port, INPUT_PULLUP);
  pinMode(switch1.port, INPUT);
  pinMode(switch2.port, INPUT);

}


