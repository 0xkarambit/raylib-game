#pragma once

#include "types.h"

typedef struct Player_s
{
	int_vec2 pos;
	int width;
	int height;
	int acceleration;
	int_vec2 velocity;
	// sprite data, animation frame sequence data
} Player_t;

void p_render();
void p_update();
void simple_move();

// should i add isColliding and onResize functions ?
// nah widht and height should be defined in terms of TILE_W and TILE_H