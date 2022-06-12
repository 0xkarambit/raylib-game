#include "camera.h"
#include "player.h"
#include "main.h"


extern CAMERA_t camera;

void Camera_set_pos(int x, int y)
{
	camera.pos.x = x;
	camera.pos.y = y;
}

void Camera_set_zoom(int percent)
{
	camera.draw_distance.x *= ((float)percent / 100.0f);		// float division is expensive iirc
	camera.draw_distance.y *= ((float)percent / 100.0f);		// float division is expensive iirc
}

bool Camera_move(enum DIRECTION dir)
{
	bool moved = false;
	switch (dir)
	{
		case LEFT:
			camera.pos.x -= (camera.pos.x <= 0) ? 0 : 1;
			moved = true;
			break;
		
		case RIGHT:
			camera.pos.x += (camera.pos.x >= TILES_COUNT_R) ? 0 : 1;
			moved = true;
			break;

		case TOP:
			camera.pos.y -= (camera.pos.y <= 0) ? 0 : 1;
			moved = true;
			break;

		case BOTTOM:
			camera.pos.y += (camera.pos.y >= TILES_COUNT_C) ? 0 : 1;
			moved = true;
			break;

		default:
			// NULL
			break;
	}
	return moved;
}

void Camera_follow_entity(Player_t entity)
{
	const int CAMERAMOVEDISTANCE = 2; // if the player is at least at this must distance from the camera frame borders the frame should move in the required direction
	

	// min 0, 0
	// max TILE_COUNT_R, TILE_COUNT_C
	// i guess move would only be in 2 directions at the same time ???
	// enum DIRECTION directions[2] = {0}; // would have to make a counter too .... too much code
	while (entity.pos.y > (camera.pos.y + camera.draw_distance.y - 1 - CAMERAMOVEDISTANCE))
	{
		// printf("moved %d\n", Camera_move(BOTTOM));
		if (!Camera_move(BOTTOM)) break;
		// camera.pos.y++;
	}
	while (entity.pos.x > (camera.pos.x + camera.draw_distance.x - 1 - CAMERAMOVEDISTANCE))
	{
		// printf("moved %d\n", Camera_move(RIGHT));
		if (!Camera_move(RIGHT)) break;
		// camera.pos.x++;
	}
	while (entity.pos.y < (camera.pos.y + camera.draw_distance.y + CAMERAMOVEDISTANCE))
	{
		// printf("moved %d\n", Camera_move(TOP));
		if (!Camera_move(TOP)) break;
		// camera.pos.y--;
	}
	while (entity.pos.x < (camera.pos.x + camera.draw_distance.x + CAMERAMOVEDISTANCE))
	{
		// printf("moved %d\n", Camera_move(LEFT));
		if (!Camera_move(LEFT)) break;
		// camera.pos.x--;
	}
}

// shake camera function, add/sub some random value to the resulting `y * tileHeight, x * tileWidht` coordinates

// 0, 0 zoom 10 ,10

// 2, 3

int_vec2 Camera_get_relative_coors(int_vec2 coors)
{
	// adjusting the coordinates to render relative to the camera postion
	return (int_vec2) {
		.x= coors.x - camera.pos.x,
		.y= coors.y - camera.pos.y
	};
}