/*Name: inputLib.h
* Purpose: declare structs and input lib
* Due date: Dec 1 2016
* Authors: Yixuan Wang, Jaxon Lin
 */
#include <OrbitBoosterPackDefs.h>
#ifndef INPUTLIB_H
#define INPUTLIB_H

typedef struct input {
	const int port;
	int state;
	float value;
} input;

static input button1 = {18, 0, 0};
static input button2 = {25, 0, 0};

static input button3 = {31, 0, 0}; 
static input button4 = {17, 0, 0}; 

static input switch1 = {10, 0, 0};
static input switch2 = {9, 0, 0};

static input potentio = {29, 0, 0};

#define BUTTON_NUM 2
#define SWITCH_NUM 2
#define GLED GREEN_LED
#define BLED BLUE_LED
#define RLED RED_LED

#define TOPHITCENTREX 12
#define TOPHITCENTREY 10
#define MIDHITCENTREX 12
#define MIDHITCENTREY 18
#define BOTHITCENTREX 12
#define BOTHITCENTREY 22


int hasElemAtPixel(int xco, int yco);
int isInGame();

#endif