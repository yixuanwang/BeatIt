#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include "inputLib.h"
#define SPEED_MS 100

void loop(){
  testing();
  // delay(1000);
}

void testing(){
  OrbitOledClear();
  /*potentio.value = analogRead(potentio.port);
  char output[20];
  snprintf(output, 20, "%f", potentio.value);
  OrbitOledMoveTo(0,0);
  OrbitOledDrawString("Potentio value");
  OrbitOledMoveTo(0, 10);
  OrbitOledDrawString(output);*/
  button1.state = digitalRead(button1.port);
  button2.state = digitalRead(button2.port);
  button3.state = digitalRead(button3.port);
  button4.state = digitalRead(button4.port);
  switch1.state = digitalRead(switch1.port);
  switch2.state = digitalRead(switch2.port);
	if(button2.state == HIGH){
    OrbitOledMoveTo(0, 9);
    OrbitOledDrawString("Button2 Pressed");
    OrbitOledUpdate();
  } else {
    OrbitOledMoveTo(0, 9);
    OrbitOledDrawString("Button2 Not Pressed");
    OrbitOledUpdate();
  }

  if(button1.state == HIGH){
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString("Button1 Pressed");
    OrbitOledUpdate();
  } else {
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString("Button1 Not Pressed");
    OrbitOledUpdate();
  }

  if(button4.state == LOW){
    OrbitOledMoveTo(0, 25);
    OrbitOledDrawString("Button4 Pressed");
    OrbitOledUpdate();
  } else {
    OrbitOledMoveTo(0, 25);
    OrbitOledDrawString("Button4 Not Pressed");
    OrbitOledUpdate();
  }

  if(button3.state == LOW){
    OrbitOledMoveTo(0, 17);
    OrbitOledDrawString("Button3 Pressed");
    OrbitOledUpdate();
  } else {
    OrbitOledMoveTo(0, 17);
    OrbitOledDrawString("Button3 Not Pressed");
    OrbitOledUpdate();
  }

  /*if(switch1.state == HIGH){
    OrbitOledMoveTo(0, 18);
    OrbitOledDrawString("Switch 1 up");
  } else {
    OrbitOledMoveTo(0, 18);
    OrbitOledDrawString("Switch 1 down");
  }

  if(switch2.state == HIGH){
    OrbitOledMoveTo(0, 26);
    OrbitOledDrawString("Switch 2 up");
  } else {
    OrbitOledMoveTo(0, 26);
    OrbitOledDrawString("Switch 2 down");
  }*/
}

void inputLoop(){
  OrbitOledClear();
  potentio.value = analogRead(potentio.port);
  button1.state = digitalRead(button1.port);
  button2.state = digitalRead(button2.port);
  button3.state = digitalRead(button3.port);
  button4.state = digitalRead(button4.port);
  switch1.state = digitalRead(switch1.port);
  switch2.state = digitalRead(switch2.port);

  //while(isInGame()) {
		if(button1.state == HIGH || button2.state == HIGH) {
	    if(hasElemAtPixel(TOPHITCENTREX, TOPHITCENTREY)) {
	    	OrbitOledMoveTo(0, 0);
	   	 	OrbitOledDrawString("top btn right press");
	    }
	    else {
	    	OrbitOledMoveTo(0, 0);
	   		OrbitOledDrawString("top btn wrong press");
	    }
	    OrbitOledUpdate();
	  }
	  else {
	    OrbitOledMoveTo(0, 0);
	    OrbitOledDrawString("top btns no press");
	    OrbitOledUpdate();
	  }

/*	  if(switch1.state == HIGH){
	    OrbitOledMoveTo(0, 18);
	    OrbitOledDrawString("Switch 1 up");
	  }
	  else {
	    OrbitOledMoveTo(0, 18);
	    OrbitOledDrawString("Switch 1 down");
	  }

	  if(switch2.state == HIGH){
	    OrbitOledMoveTo(0, 26);
	    OrbitOledDrawString("Switch 2 up");
	  }
	  else {
	    OrbitOledMoveTo(0, 26);
	    OrbitOledDrawString("Switch 2 down");
	  }*/

	  if(button3.state == LOW || button4.state == LOW){
	    if(hasElemAtPixel(BOTHITCENTREX, BOTHITCENTREY)) {
	    	OrbitOledMoveTo(0, 22);
	   	 	OrbitOledDrawString("bot btn right press");
	    }
	    else {
	    	OrbitOledMoveTo(0, 22);
	   		OrbitOledDrawString("bot btn wrong press");
	    }
	    OrbitOledUpdate();
	  }
	  else {
	    OrbitOledMoveTo(0, 22);
	    OrbitOledDrawString("bot btns no press");
	    OrbitOledUpdate();
	  }

	//}
}

int hasElemAtPixel(int xco, int yco) {
  OrbitOledMoveTo(xco, yco);
  return (OrbitOledGetPixel());
}

int isInGame() {
	//if not in game return 0
	return 1;
}