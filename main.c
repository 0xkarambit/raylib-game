#include <raylib.h>
#include <string.h>
#include <stdio.h>

#include "main.h"
#include "utils.h"
#include "tiles.h"
#include "camera.h"
#include "input.h"

#include "player.h"

int TILE_H = HEIGHT / TILES_COUNT_R;	// each tile Height
int TILE_W = WIDTH / TILES_COUNT_C;		// each tile Width

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


KEYPRESSMAP_t key_press_map = { 0, 0, 0, 0 };
Player_t main_player = { .pos={2, 3}, .acceleration=10, .velocity={0,0}};

int main()
{
	// setting according to camera
	TILE_H = HEIGHT / camera.draw_distance.y;	// each tile Height
	TILE_W = WIDTH / camera.draw_distance.x;		// each tile Width
	
	InitWindow(WIDTH, HEIGHT, TITLE);
	// ToggleFullscreen();
	SetTargetFPS(TARGET_FPS);

	int pressCount = 0;
	char pressCountStr[5] = {0};
	float scroll;
	// Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
		BeginDrawing();

				DrawFPS(0,0);

				// update input map
				// key_press_map = (KEYPRESSMAP_t){
				// 	IsKeyPressed(KEY_LEFT),
				// 	IsKeyPressed(KEY_DOWN),
				// 	IsKeyPressed(KEY_UP),
				// 	IsKeyPressed(KEY_RIGHT),
				// };

				// update segment
				// if (IsKeyPressed(KEY_LEFT))
				// {
				// 	// printf("LOGGING::: KEYPRESSED\n");
				// 	// printf("%d %d\n", camera.pos.x, camera.pos.y);
				// 	// camera.pos.x = camera.pos.x == 0 ? 0 : camera.pos.x - 1;
				// }
				// if (IsKeyPressed(KEY_DOWN)) {
				// 	// printf("LOGGING::: KEYPRESSED\n");
				// 	// printf("%d %d\n", camera.pos.x, camera.pos.y);
				// 	// camera.pos.y++; 
				// 	// camera.pos.y = camera.pos.y == TILES_COUNT_R - 1 ? TILES_COUNT_R -1 : camera.pos.y + 1;
				// }
				// if (IsKeyPressed(KEY_UP)) {
				// 	// printf("LOGGING::: KEYPRESSED\n");
				// 	// printf("%d %d\n", camera.pos.x, camera.pos.y);
				// 	// camera.pos.y--;
				// 	// camera.pos.y = camera.pos.y == 0 ? 0 : camera.pos.y - 1;
				// }
				// if (IsKeyPressed(KEY_RIGHT))
				// {
				// 	// printf("LOGGING::: KEYPRESSED\n");
				// 	// printf("%d %d\n", camera.pos.x, camera.pos.y);
				// 	// camera.pos.x++;
				// 	// camera.pos.x = camera.pos.x == TILES_COUNT_C - 1 ? TILES_COUNT_C -1 : camera.pos.x + 1;
				// }
				// if (IsKeyPressed(KEY_A))
				// 	populateTiles();

				// draw segment
				ClearBackground(GRAY);
				drawTiles();
				DrawText("Smokin !", 190, 200, 20, RED);
                
				sprintf(pressCountStr, "%d", pressCount);
				DrawText(pressCountStr, 300, 400, 30, (Color){23,23,45, 233});

				p_update();
				p_render();
				// DrawRectangle(0, 0, TILE_W, TILE_H, (Color){32,255,343, 214});


				// #region
				// ZOOM WHEN SCROLLING !
				scroll = GetMouseWheelMove();
				if (scroll > 0)
				{
						// zoom has to be increased
						if (camera.draw_distance.x != 1)
						{
							// size is not already the max limit !
							camera.draw_distance.x -= 1;			// zoom increase
							camera.draw_distance.y -= 1;
							reTargetGrid();										// change the tileWidth and tileHeight
						}
				}
				else if (scroll < 0)
				{
						// zoom has to be decreased // ideally both x and y should be the same lol, but both are public, we really should have just a single number
						if (camera.draw_distance.x != TILES_COUNT_R)
						{
							// size is not already the max limit !
							camera.draw_distance.x += 1;			// zoom decrease
							camera.draw_distance.y += 1;
							reTargetGrid();										// change the tileWidth and tileHeight
						}
				}
				// #endregion ZOOM CODE ENDS
		
		EndDrawing();
	}

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

