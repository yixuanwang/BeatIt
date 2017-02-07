/*Name: mapLib.h
* Purpose: library of custom map function declarations
* 		   and constants
* Due date: Dec 1 2016
* Author(s): Jaxon Lin
 */

#ifndef MAPLIB_H
#define MAPLIB_H
#define SCREENLENGTH 128
#define SCREENWIDTH 32

#define ULCORNERX 0
#define ULCORNERY 0
#define URCORNERX 127
#define URCORNERY 0

#define LLCORNERX 0
#define LLCORNERY 31
#define LRCORNERX 127
#define LRCORNERY 31

/*int testMap[128][32] = {0};
for(int i = 0; i < 32; i++) {
	testMap[0][i] = 1;
}*/

typedef struct TrackMap {
	int mlength;
	char bmap[][SCREENWIDTH];
} TrackMap;

//draws map and moves it to the left
//**when have map include whitespace at end (128 x 32 of whitespace)
void drawMap(char bmap[][32], int mlength);
void drawGame(TrackMap *tmap, int mlength, int diff);

void drawInGameUI();

//creates map
void createMap(TrackMap *tmap, int mlength);

void createTestMap(TrackMap *tmap, int mlength);
void createTestBeatMap(TrackMap *tmap, int mlength);
void createTestMap3(TrackMap *tmap, int mlength);

void createDemoMap(TrackMap *tmap, int mlength);


#endif
