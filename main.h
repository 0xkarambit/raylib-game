
#pragma once

// config
#define HEIGHT 600
#define WIDTH 1200
#define TITLE "The Syndicate - Prototype run"
#define TARGET_FPS 30

// MUST DIVIDE WIDTH AND HEIGHT PREFECTLY REPECTIVELY, OK MAYBE NOT LMAO
#define TILES_COUNT_R 10					// tiles in each row,		basically no of columns ??
#define TILES_COUNT_C 10					// tiles in each col, 	basically no of rows ??

typedef enum TILE_S {
	WATER,
	GROUND,
	WALL,
	DOOR,
} TILE_T;
