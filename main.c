#include <raylib.h>
#include <string.h>
#include <stdio.h>

#include "main.h"
#include "utils.h"
#include "tiles.h"

int TILE_H = HEIGHT / TILES_COUNT_R;	// each tile Height
int TILE_W = WIDTH / TILES_COUNT_C;		// each tile Width

// Tilemap
TILE_T TILEMAP[TILES_COUNT_C][TILES_COUNT_R] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 1, 0},
	{0, 3, 0, 1, 0},
	{0, 2, 2, 1, 0},
	{0, 0, 0, 0, 0},
};

const Color TILE_COLORS[] = {
	[WATER] = BLUE,
	[GROUND] = BROWN,
	[WALL] = GRAY,
	[DOOR] = RED,
};

// todo: Implement camera !

int main() {
	
	InitWindow(WIDTH, HEIGHT, TITLE);
	// ToggleFullscreen();
	SetTargetFPS(TARGET_FPS);

	int pressCount = 0;
	char pressCountStr[30] = {0};
	// Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
		BeginDrawing();

				// update segment
				if (IsKeyPressed(KEY_LEFT))
				{
						toggleFullscreen();
						reTargetGrid();
						pressCount++;
				}
				if (IsKeyPressed(KEY_RIGHT))
				{
					populateTiles();
				}

				// draw segment
				ClearBackground(GRAY);
				drawTiles();
				DrawText("Smokin !", 190, 200, 20, RED);
                
				sprintf(pressCountStr, "%d", pressCount);
				DrawText(pressCountStr, 300, 400, 30, (Color){23,23,45, 233});
		

		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

