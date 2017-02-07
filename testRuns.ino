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
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(LD1, OUTPUT);
  pinMode(LD2, OUTPUT);
  pinMode(LD3, OUTPUT);
  pinMode(LD4, OUTPUT);
}


