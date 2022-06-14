#pragma once

#include <stdbool.h>

typedef struct SCENE_s
{
	void (*setup)();
	void (*update)();
	void (*render)();
	bool (*exit)();
} SCENE;

bool switch_scene(SCENE* next_scene);