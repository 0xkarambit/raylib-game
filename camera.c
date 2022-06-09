#include "camera.h"


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

// shake camera function, add/sub some random value to the resulting `y * tileHeight, x * tileWidht` coordinates