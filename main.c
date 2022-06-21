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
#include "./Scenes/MainMenu/main_menu.h"


extern SCENE MAIN_MENU_SCENE;

SCENE *current_scene = &MAIN_MENU_SCENE;
SCENE *next_scene = NULL;

int main()
{	
	// TILE_H = HEIGHT / camera.draw_distance.y;	// each tile Height
	// TILE_W = WIDTH / camera.draw_distance.x;		// each tile Width
	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(TARGET_FPS);
	current_scene->setup();
	// Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
		BeginDrawing();

				current_scene->render();
				current_scene->update();
				swap_scenes();
				DrawFPS(0,0);

		EndDrawing();
	}

	current_scene->exit();
	CloseWindow();        // Close window and OpenGL context

	return 0;
}

