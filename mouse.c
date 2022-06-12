#pragma once

#include <raylib.h>
#include <stdbool.h>
#include <assert.h>

#include "main.h"
#include "mouse.h"
#include "camera.h"
#include "player.h"
#include "utils.h"

extern CAMERA_t camera;
extern int cameraFullView;
extern Player_t main_player;		// we wouldnt need to include this had its properties been relative to TILE_W and TILE_H (automatic reactive due to caluculation expression !)

extern int TILE_H;
extern int TILE_W;

#define DEFAULT_SCROLL_SPEED 1;
#define INCREASED_SCROLL_SPEED 10;

int ctrlPressed = false;
float scroll = 0;
int scrollSpeed = DEFAULT_SCROLL_SPEED;

void mouse_update() 
{

	// mouse update
	if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
	{
		if (cameraFullView) {
			cameraFullView = 0;
			camera.draw_distance = (int_vec2){CAMERA_ZOOM, CAMERA_ZOOM};
		}
		else {
			cameraFullView = 1;
			camera.draw_distance = (int_vec2){MAX_WORLD_VIEW, MAX_WORLD_VIEW};
		}
		reTargetGrid();
		// main_player.height = TILE_H;
		// main_player.width = TILE_W;
	}

	// determining scroll speed;
	if (!ctrlPressed && IsKeyDown(KEY_LEFT_CONTROL)) {
		ctrlPressed = true;
		scrollSpeed = INCREASED_SCROLL_SPEED;
	} else if (IsKeyUp(KEY_LEFT_CONTROL)) {
		ctrlPressed = false;
		scrollSpeed = DEFAULT_SCROLL_SPEED;
	}

	// #region
	// ZOOM WHEN SCROLLING !
	scroll = GetMouseWheelMove();
	if (scroll > 0)
	{
			// zoom has to be increased
			if (camera.draw_distance.x != 1)
			{
				// PROBABLY WENT BELOW 0
				// size is not already the max limit !
				camera.draw_distance.x -= scrollSpeed;			// zoom increase
				assert(camera.draw_distance.x > 0);
				camera.draw_distance.y -= scrollSpeed;
				assert(camera.draw_distance.y > 0);
				reTargetGrid();										// change the tileWidth and tileHeight
			}
	}
	else if (scroll < 0)
	{
			// zoom has to be decreased // ideally both x and y should be the same lol, but both are public, we really should have just a single number
			if (camera.draw_distance.x != TILES_COUNT_R)
			{
				// size is not already the max limit !
				camera.draw_distance.x += scrollSpeed;			// zoom decrease
				assert(camera.draw_distance.x > 0);
				camera.draw_distance.y += scrollSpeed;
				assert(camera.draw_distance.y > 0);
				reTargetGrid();										// change the tileWidth and tileHeight
			}
	}
	// #endregion ZOOM CODE ENDS
} 