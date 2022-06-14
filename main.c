#include <raylib.h>
#include <string.h>
#include <stdio.h>

#include "main.h"
#include "utils.h"
#include "scenes.h"
#include "tiles.h"
#include "camera.h"
// #include "input.h"
#include "mouse.h"

#include "player.h"
#include "./MainMenu/main_menu.h"


int TILE_H = 0; // HEIGHT / TILES_COUNT_R;	// each tile Height
int TILE_W = 0; // WIDTH / TILES_COUNT_C;		// each tile Width

// Tilemap count=10;
TILE_T TILEMAP[TILES_COUNT_C][TILES_COUNT_R] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 2, 0},
	{0, 3, 0, 1, 0, 0, 0, 0, 2, 0},
	{0, 2, 2, 1, 0, 0, 0, 0, 2, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 2, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 2, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

const Color TILE_COLORS[] = {
	[WATER] = BLUE,
	[GROUND] = BROWN,
	[WALL] = GRAY,
	[DOOR] = RED,
};

// camera
CAMERA_t camera = {
	.pos = {0, 0},
	.draw_distance = {CAMERA_ZOOM, CAMERA_ZOOM}
};
int cameraFullView = 0;


// KEYPRESSMAP_t key_press_map = { 0, 0, 0, 0 };
Player_t main_player = {
	.pos={2, 3},	// x is the colNO and y is the rowNO, they start from 0
	.acceleration=2,
	.velocity={0,0},
	.width=1,
	.height=1
};

// make an array of entities ?


extern SCENE MAIN_MENU_SCENE;

SCENE *current_scene = &MAIN_MENU_SCENE;

int main()
{	
	TILE_H = HEIGHT / camera.draw_distance.y;	// each tile Height
	TILE_W = WIDTH / camera.draw_distance.x;		// each tile Width
	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(TARGET_FPS);
	current_scene->setup();
	// Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
		BeginDrawing();

				current_scene->render();
				current_scene->update();
				DrawFPS(0,0);

		EndDrawing();
	}

	current_scene->exit();
	CloseWindow();        // Close window and OpenGL context

	return 0;
}

