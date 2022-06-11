#pragma once
#include <raylib.h>

#define CAMERA_ZOOM 10
#define MAX_WORLD_VIEW 200

struct int_vec2
{
	int x, y;
};

// everything so far is tile based so the pos coor are tile based too
// but how can we move camera smoothly then
typedef struct CAMERA_s
{
	struct int_vec2 pos;					 // x = row , y = col | so | TILES[y][x] will be used to access a tile
																 // y points to the rowIndex and x points to the columnIndex in that row
	struct int_vec2 draw_distance; // can also be called the zoom level
} CAMERA_t;

void Camera_set_pos(int x, int y);
// set camera zoom relative to currect draw_distance
void Camera_set_zoom(int percent);
