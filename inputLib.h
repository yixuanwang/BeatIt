/*Name: inputLib.h
* Purpose: declare structs and input lib
* Due date: Dec 1 2016
* Authors: Yixuan Wang, Jaxon Lin
 */
#include <OrbitBoosterPackDefs.h>
#ifndef INPUTLIB_H
#define INPUTLIB_H
#include "mapLib.h"
#include "drawLib.h"

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

static const int GLED = 39;
static const int BLED = 40;
static const int RLED = 30;

static const int LD4 = 2;
static const int LD3 = 33;
static const int LD2 = 34;
static const int LD1 = 35;


#define BUTTON_NUM 2
#define SWITCH_NUM 2

#define TOPHITCENTREX 12
#define TOPHITCENTREY 10
#define MIDHITCENTREX 12
#define MIDHITCENTREY 18
#define BOTHITCENTREX 12
#define BOTHITCENTREY 26


int hasElemAtPixel(int xco, int yco);
int hasElemAtLine(int xco);
int hasElemNearPixel(int xco, int yco);
int isInGame();
void readInput();
void checkOutput(TrackMap *tmap, int lmx, int difficulty);
int buttonPressed();

#endif
