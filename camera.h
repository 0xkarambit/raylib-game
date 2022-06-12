#pragma once
#include <raylib.h>

#include "types.h"
#include "player.h"


#define CAMERA_ZOOM 10
#define MAX_WORLD_VIEW 200

// everything so far is tile based so the pos coor are tile based too
// but how can we move camera smoothly then
typedef struct CAMERA_s
{
	int_vec2 pos;					 // x = row , y = col | so | TILES[y][x] will be used to access a tile
																 // y points to the rowIndex and x points to the columnIndex in that row
	int_vec2 draw_distance; // can also be called the zoom level
} CAMERA_t;

enum DIRECTION {
	NONE,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
};

void Camera_set_pos(int x, int y);
// set camera zoom relative to currect draw_distance
void Camera_set_zoom(int percent);
void Camera_follow_entity(Player_t entity);
bool Camera_move(enum DIRECTION dir);

int_vec2 Camera_get_relative_coors(int_vec2 coors);