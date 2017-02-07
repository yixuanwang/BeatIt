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
#include "inputLib.h"
#define SPEED_MS 75

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

void drawSquareBmap(TrackMap *tmap, int xco, int yco) {
  for(int i = yco - 1; i <= yco + 1; i++) {
    for(int j = xco - 1; j <= xco + 1; j++) {
      tmap -> bmap[j][i] = '1';
    }
  }
}

void clearSquareBmap(TrackMap *tmap, int xco, int yco) {
  for(int i = yco - 2; i <= yco + 2; i++) {
    for(int j = xco - 2; j <= xco + 2; j++) {
      tmap -> bmap[j][i] = '0';
    }
  }
}

void clearHit(TrackMap *tmap, int xco, int yco) { //xco is lmx + xco
  clearSquareBmap(tmap, xco, yco);
  score += 10;
}

void drawLongHitBmap(TrackMap *tmap, int xco, int yco, int length) {
	for(int i = 0; i < length; i++) {
		drawSquareBmap(tmap, xco, yco);
		xco += 3;
	}
}

void moveSquare(int xco, int yco, int moveBy, int stopco){
  while(xco > stopco) {
    drawSquareB(xco, yco);
    xco += moveBy;
    OrbitOledClear();
  }
}

void drawWelcome() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    lightUpInOrder();
    lightOffInOrder();
  }
  readInput();
  OrbitOledClear();
  OrbitOledMoveTo(32,0);
  OrbitOledDrawString("Welcome!");
  OrbitOledMoveTo(0,20);
  OrbitOledDrawString("Press Any Button!");
  OrbitOledUpdate();
  
  lightUpAll();
  delay(SPEED_MS * 2);
  lightOffAll();
  delay(SPEED_MS * 2);
  lightUpAll();
  delay(SPEED_MS * 2);
  lightOffAll();
  delay(SPEED_MS* 2);
  lightUpInOrder();
  while(!buttonPressed()){
  }
  //delay(1000);
  lightApprove();
  
}

void drawScore(){
  OrbitOledClear();
  char scorestr[10];
  snprintf(scorestr, 10, "%d", score);
  OrbitOledMoveTo(5,0);
  OrbitOledDrawString("Score:");
  OrbitOledMoveTo(60,0);
  OrbitOledDrawString(scorestr);
  OrbitOledUpdate();
  lightUpInOrder();
  char combostr[10];
  snprintf(combostr, 10, "%d", combo);
  OrbitOledMoveTo(5,15);
  //OrbitOledDrawString("Missed:");
  OrbitOledDrawString("Good job!");
  OrbitOledMoveTo(68,15);
  //OrbitOledDrawString("lolstilltrying");
  delay(50);
  lightOffAll();
  delay(50);
  lightUpInOrder();
  OrbitOledUpdate();
  while(!buttonPressed()){
  }
  score = 0;
  combo = 0;
  lightApprove();
}

int drawDiff(){
  readInput();
  OrbitOledClear();
  int diff = 0;
  while(!buttonPressed()){
    readInput();
    potentio.value = analogRead(potentio.port);
    if(potentio.value<=1365){
      OrbitOledClearBuffer();
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(20,0);
      OrbitOledDrawString("Difficulty!");
      OrbitOledMoveTo(0,10);
      OrbitOledDrawString(" -> Easy");
      OrbitOledUpdate();
      diff = 10;
  

    } else if(potentio.value<=2730){
      OrbitOledClearBuffer();
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(20,0);
      OrbitOledDrawString("Difficulty!");
      OrbitOledMoveTo(0,15);
      OrbitOledDrawString(" -> Medium");
      OrbitOledUpdate();
      diff= 5;

    } else if(potentio.value<=4095){
      OrbitOledClearBuffer();
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(20,0);
      OrbitOledDrawString("Difficulty!");
      OrbitOledMoveTo(0,20);
      OrbitOledDrawString(" -> Hard");
      OrbitOledUpdate();
      diff = 1;

    } else {
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(0,10);
      OrbitOledDrawString("rip");
      OrbitOledUpdate();
    }
  }
  lightApprove();
  return diff;
}

int drawMenu(){
  readInput();
  OrbitOledClear();
  int tracknum = 0;
  while(!buttonPressed()){
    readInput();
    potentio.value = analogRead(potentio.port);
    if(potentio.value<=2047){
      OrbitOledClearBuffer();
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(46,0);
      OrbitOledDrawString("Menu!");
      OrbitOledMoveTo(0,10);
      OrbitOledDrawString(" -> Track 1");
      OrbitOledUpdate();
      tracknum = 1;
    } else if(potentio.value>2047){
      OrbitOledClearBuffer();
      OrbitOledMoveTo(46,0);
      OrbitOledDrawString("Menu!");
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(0,18);
      OrbitOledDrawString(" -> Track 2");
      OrbitOledUpdate();
      tracknum = 2;

    } else {
      potentio.value = analogRead(potentio.port);
      OrbitOledMoveTo(0,10);
      OrbitOledDrawString("rip");
      OrbitOledUpdate();
      tracknum = 0;
    }
  }
  lightApprove();
  return tracknum;
}

void drawLoading() {
	OrbitOledClear();
	OrbitOledMoveTo(24,10);
  OrbitOledDrawString("Loading...");
  OrbitOledUpdate();
  lightUpInOrderSlow();
  lightApprove();
  lightApprove();
  OrbitOledClearBuffer();
  OrbitOledMoveTo(40,13);
  OrbitOledDrawString("Ready!");
  /*OrbitOledMoveTo(0,23);
  OrbitOledDrawString("Press any button");*/
  OrbitOledUpdate();
  while(!buttonPressed()){
  }
  lightApprove();
  return;
}

void lightUpInOrder() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    digitalWrite(lights[i], HIGH);
    delay(SPEED_MS);
  }
}

void lightUpInOrderSlow() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    digitalWrite(lights[i], HIGH);
    delay(SPEED_MS * 2);
  }
}

void lightOffInOrder() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    digitalWrite(lights[i], LOW);
    delay(SPEED_MS);
  }
}

void lightUpAll() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    digitalWrite(lights[i], HIGH);
  }
}

void lightOffAll() {
  int lights[4] = {LD4, LD3, LD2, LD1};
  for(int i = 0; i < 4; i++) {
    digitalWrite(lights[i], LOW);
  }
}

void lightApprove() {
  lightOffAll();
  delay(SPEED_MS * 2);
  lightUpAll();
  delay(SPEED_MS * 2);
  lightOffAll();
}


