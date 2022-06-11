#include <raylib.h>
#include <string.h>
#include <stdio.h>

#include "main.h"
#include "utils.h"
#include "tiles.h"
#include "camera.h"
#include "input.h"
#include "mouse.h"

#include "player.h"

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


KEYPRESSMAP_t key_press_map = { 0, 0, 0, 0 };
Player_t main_player = { .pos={2, 3}, .acceleration=2, .velocity={0,0}, .width=2, .height=2};

int main()
{
	// setting according to camera
	TILE_H = HEIGHT / camera.draw_distance.y;	// each tile Height
	TILE_W = WIDTH / camera.draw_distance.x;		// each tile Width
	
	InitWindow(WIDTH, HEIGHT, TITLE);
	// ToggleFullscreen();
	SetTargetFPS(TARGET_FPS);

	// Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
		BeginDrawing();
				// draw segment
				ClearBackground(GRAY);
				drawTiles();

				p_update();
				p_render();
				// DrawRectangle(0, 0, TILE_W, TILE_H, (Color){32,255,343, 214});
				mouse_update();

				
				DrawFPS(0,0);

		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

