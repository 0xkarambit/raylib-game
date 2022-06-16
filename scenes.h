#pragma once

#include <stdbool.h>


typedef void (*SCENE_function)(void);
typedef bool (*SCENE_exit_function)(void);

typedef struct SCENE_s
{
	SCENE_function setup;
	SCENE_function update;
	SCENE_function render;
	SCENE_exit_function exit;
} SCENE;

bool switch_scene(SCENE* next_scene);

// I remember now not adding a void keyword in args list means any no of args can be passed lmao