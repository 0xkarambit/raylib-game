#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "tiles.h"


extern TILE_T TILEMAP[TILES_COUNT_C][TILES_COUNT_R];
extern const Color TILE_COLORS[];
extern int TILE_W;
extern int TILE_H;

#include "camera.h"
extern CAMERA_t camera;

void populateTiles()
{
	// if we somehow know where the stack frame for this function starts can be figure out where the args are ???
	// and can we use any no of args then ????? UB SURE, 
	for (int i = 0; i < TILES_COUNT_C; i++) {
		for (int ii = 0; ii < TILES_COUNT_R; ii++) {
			// TILE_T tile = TILEMAP[i][ii];
			TILEMAP[i][ii] = WATER;
		}
	}
};


void drawTiles()
{
	int pos_x = 0;
	int pos_y = 0;

	// debugging stuff
	char coor[10] = {0};

	for (int i = camera.pos.y; i < camera.draw_distance.y + camera.pos.y; i++) {
		for (int ii = camera.pos.x; ii < camera.draw_distance.x + camera.pos.x; ii++) {
			TILE_T tile = TILEMAP[i][ii];

			// printf("INFO:: {%d, %d} %d %d \n", pos_x, pos_y, i , ii);
			Color color = TILE_COLORS[tile];

			DrawRectangle(pos_x, pos_y, TILE_W, TILE_H, color);

			// debugging stuff
			sprintf(coor, "%d, %d", ii, i);
			DrawText(coor, pos_x, pos_y, 12, (Color){0, 0, 0, 255});
			pos_x += TILE_W;
		}
		pos_y += TILE_H;
		pos_x = 0;

	}
}

void updateTiles()
{
	// for transforming the map !
}

void saveTiles()
{
	// save TILEMAP to disk !
}