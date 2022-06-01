#include <raylib.h>

#include "main.h"


extern TILE_T TILEMAP[TILES_COUNT_C][TILES_COUNT_R];
extern const Color TILE_COLORS[];
extern int TILE_W;
extern int TILE_H;

void populateTiles()
{
	// if we somehow know where the stack frame for this function starts can be figure out where the args are ???
	// and can we use any no of args then ????? UB SURE, 
	for (int i = 0; i < TILES_COUNT_R; i++) {
		for (int ii = 0; ii < TILES_COUNT_C; ii++) {
			// TILE_T tile = TILEMAP[i][ii];
			TILEMAP[i][ii] = WATER;
		}
	}
};


void drawTiles()
{
	for (int i = 0; i < TILES_COUNT_R; i++) {
		for (int ii = 0; ii < TILES_COUNT_C; ii++) {
			TILE_T tile = TILEMAP[i][ii];
			int pos_x = i * TILE_W;
			int pos_y = ii * TILE_H;
			Color color = TILE_COLORS[tile];

			DrawRectangle(pos_x, pos_y, TILE_W, TILE_H, color);
		}
	}
}