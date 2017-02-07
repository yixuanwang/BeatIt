/*Name: inputLib.c
* Purpose: input lib function definitions
* Due date: Dec 1 2016
* Authors: Yixuan Wang, Jaxon Lin
 */

#include "inputLib.h"
#include "mapLib.h"
#include "drawLib.h"

int hasElemAtPixel(int xco, int yco) {
  OrbitOledMoveTo(xco, yco);
  return (OrbitOledGetPixel());
}

int hasElemAtLine(int xco) {
	int hasElem = 0;
	for(int i = 0; i < SCREENWIDTH; i++) {
		if(i == 6 || i == 14 || i == 22|| i == 30){
			i++;
			continue;
		}
		OrbitOledMoveTo(xco, i);
		/*if(OrbitOledGetPixel() == 1) {
			hasElem = 1;
			break;
		}*/
	}
	return hasElem;
}
//TODO: create welcome screen
//make maps 
//get switches to work

int isInGame() {
	//if not in game return 0
	return 1;
}

void readInput() {
	//potentio.value = analogRead(potentio.port);
  button1.state = digitalRead(button1.port);
  button2.state = digitalRead(button2.port);
  button3.state = digitalRead(button3.port);
  button4.state = digitalRead(button4.port);
  switch1.state = digitalRead(switch1.port);
  switch2.state = digitalRead(switch2.port);
}

int buttonPressed(){
  readInput();
  if( button1.state == HIGH){
    return 1;
  } else if (button2.state == HIGH){
    return 2;
  } else if (button3.state == LOW){
    return 3;
  } else if (button4.state == LOW){
    return 4;
  } else {
    return 0;
  }
}

void checkOutput(TrackMap *tmap, int lmx, int difficulty) {
  
  int speedms = difficulty * 10;
  
	if(! (hasElemAtPixel(TOPHITCENTREX, TOPHITCENTREY) &&
		    //hasElemAtPixel(MIDHITCENTREX, MIDHITCENTREY) &&
		    hasElemAtPixel(BOTHITCENTREX, BOTHITCENTREY))) {

		//if any button is pressed when nothing is there
		if(button1.state == HIGH || button2.state == HIGH ||
			 button3.state == LOW || button4.state == LOW) {
			digitalWrite(RLED, HIGH);
      		score -= 10;
		}
	}

  if(hasElemAtPixel(TOPHITCENTREX, TOPHITCENTREY)) {
    if(button1.state == HIGH || button2.state == HIGH) {
      digitalWrite(RLED, LOW);
      if(button1.state == HIGH && button2.state == HIGH){
      	digitalWrite(LD3, HIGH);
      	digitalWrite(LD4, HIGH);	
      }
      if(button1.state == HIGH){
      	digitalWrite(LD3, LOW);
      	digitalWrite(LD4, HIGH);	
      }
      if(button2.state == HIGH) {
      	digitalWrite(LD4, LOW);
      	digitalWrite(LD3, HIGH);
      }
      clearHit(tmap, lmx + TOPHITCENTREX, TOPHITCENTREY);
    }
    /*
    else {
    	digitalWrite(LD4, LOW);
  		digitalWrite(LD3, LOW);
  		digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);*/
  }
  else {
    if(button1.state == HIGH || button2.state == HIGH) {
      digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);
  }

  if(hasElemAtPixel(MIDHITCENTREX, MIDHITCENTREY) == 1) {
    if(switch1.state == HIGH || switch2.state == HIGH) {
    	digitalWrite(RLED, LOW);
      if(switch1.state == HIGH) {
      	digitalWrite(LD3, HIGH);
      	digitalWrite(LD4, HIGH);
      }
      if(switch2.state == HIGH) {
      	digitalWrite(LD1, HIGH);
      	digitalWrite(LD2, HIGH);
      }
      clearHit(tmap, lmx + MIDHITCENTREX, MIDHITCENTREY);
    }
    /*else {
    	digitalWrite(LD2, LOW);
  		digitalWrite(LD1, LOW);
  		digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);*/
    
  }
  else {
    if(switch1.state == HIGH || switch2.state == HIGH) {
    	digitalWrite(LD2, LOW);
  		digitalWrite(LD1, LOW);
  		digitalWrite(LD3, LOW);
  		digitalWrite(LD4, LOW);
      digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);
  }

  if(hasElemAtPixel(BOTHITCENTREX, BOTHITCENTREY) == 1) {
    if(button3.state == LOW || button4.state == LOW) {
    	digitalWrite(RLED, LOW);
      if(button3.state == LOW) {
      	digitalWrite(LD2, HIGH);
      }
      if(button4.state == LOW) {
      	digitalWrite(LD1, HIGH);
      }
      clearHit(tmap, lmx + BOTHITCENTREX, BOTHITCENTREY);
    }
    /*else {
    	digitalWrite(LD2, LOW);
  		digitalWrite(LD1, LOW);
  		digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);*/
    
  }
  else {
    if(button3.state == LOW || button4.state == LOW) {
    	digitalWrite(LD2, LOW);
  		digitalWrite(LD1, LOW);
      digitalWrite(RLED, HIGH);
      score -= 10;
    }
    //delay(SPEED_MS);
  }

  if(hasElemAtLine(1)) {
  	digitalWrite(LD4, LOW);
  	digitalWrite(LD3, LOW);
  	digitalWrite(LD2, LOW);
  	digitalWrite(LD1, LOW);
  	digitalWrite(RLED, HIGH);
  	combo += 2;//+= hasElemAtLine(1);
  }

  delay(speedms);
  digitalWrite(LD4, LOW);
	digitalWrite(LD3, LOW);
  digitalWrite(LD2, LOW);
	digitalWrite(LD1, LOW);
  digitalWrite(RLED, LOW);
}
