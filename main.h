
#pragma once

// config
#define HEIGHT 600
#define WIDTH 1200
#define TITLE "The Syndicate - Prototype run"
#define TARGET_FPS 30

// todo: hmm why do we see grey boxes after a certain limit ???
#define TILES_COUNT_R 100					// tiles in each row,		basically no of columns ??
#define TILES_COUNT_C 100					// tiles in each col, 	basically no of rows ??

typedef enum TILE_S {
	WATER,
	GROUND,
	WALL,
	DOOR,
} TILE_T;
