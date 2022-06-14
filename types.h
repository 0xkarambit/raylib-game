#pragma once

typedef struct int_vec2_s
{
	int x, y;
} int_vec2;


typedef struct SCENE_s {
	void (*setup)();
	void (*update)();
	void (*render)();
	void (*exit)();
}	SCENE;