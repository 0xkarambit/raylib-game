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