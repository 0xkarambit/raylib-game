#pragma once

#include "camera.h"

typedef struct Player_s
{
	struct int_vec2 pos;
	int width;
	int height;
	int acceleration;
	struct int_vec2 velocity;
	// sprite data, animation frame sequence data
} Player_t;

void p_render();
void p_update();

// should i add isColliding and onResize functions ?
// nah widht and height should be defined in terms of TILE_W and TILE_H