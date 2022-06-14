#include <stdio.h>

#include <raylib.h>

#include "player.h"
#include "camera.h"
#include "main.h"

extern Player_t main_player;
extern int TILE_H;
extern int TILE_W;
extern CAMERA_t camera;
// extern KEYPRESSMAP_t key_press_map;

void p_render()
{
	// printf("called !\n");
	int_vec2 coors = Camera_get_relative_coors(main_player.pos);
	int x = coors.x;
	int y = coors.y;

	int width = main_player.width;
	int height = main_player.height;
	
	DrawRectangle(x*TILE_W, y*TILE_H, TILE_W*width, TILE_H*height, (Color){0,0,0, 255});
	
	// printing coorinates debug stuff !
	char coor[10] = {0};
	sprintf(coor, "%d, %d", x, y);{
	DrawText(coor, x*TILE_W, y*TILE_H, 12, (Color){255, 255, 255, 255});}
	// DrawText(coor, x*TILE_W, y*TILE_H, 12, (Color){255, 255, 255, 255});}
	// DrawRectangle(x, y, TILE_W * width ? , TILE_W * height ?, (Color){0,0,0, 255});
}


static const int DRAG = 1;
static const int MAX_VEL = 2;
static const int MIN_VEL = -2;

void p_update()
{

	// todo
	// make the C include errors detector / graph visualiser tool !
	// make a cli logging thing to update the values in place in output
	// we need an entity OOP based system !
	// make the camera follow the player and add a scenes system ??

	// applying drag in the opposite direction !!
	if (main_player.velocity.x != 0) {
		main_player.velocity.x += (main_player.velocity.x > 0) ? -DRAG : DRAG;
	}
	if (main_player.velocity.y != 0) {
		main_player.velocity.y += (main_player.velocity.y > 0) ? -DRAG : DRAG;
	}

	// adding velocity
	main_player.pos.x += main_player.velocity.x;
	main_player.pos.y += main_player.velocity.y;

	// debugging stuff ! relocation on mouse click

	// if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	// TODO; NEED BETTER LOGIC HERE
	// 	main_player.pos.x = GetMouseX();
	// 	main_player.pos.y = GetMouseY();
	// }

	// check keypresses
	int acceleration = main_player.acceleration;
	int_vec2 *velocity = &main_player.velocity;

	if (IsKeyDown(KEY_LEFT))
	{
		//
		velocity->x = velocity->x <= MIN_VEL ? MIN_VEL : velocity->x - acceleration;

	}
	if (IsKeyDown(KEY_DOWN)) {
		// main_player.pos.y++; 
		velocity->y = velocity->y >= MAX_VEL ? MAX_VEL : velocity->y + acceleration;
		
	}
	if (IsKeyDown(KEY_UP)) {
		// main_player.pos.y--;
		velocity->y = velocity->y <= MIN_VEL ? MIN_VEL : velocity->y - acceleration;
		
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		// main_player.pos.x++;
		velocity->x = velocity->x >= MAX_VEL ? MAX_VEL : velocity->x + acceleration;
		
	}

	// checking if object is OUT OF BOUNDS !
	// TODO: REFACTOR !
	if (main_player.pos.x <= 0) {
		main_player.pos.x =  0;
	}

	if (main_player.pos.y*TILE_H + main_player.height >= (TILES_COUNT_C-1)*TILE_H)	 {
		// indexes start at 0 !
		main_player.pos.y =  TILES_COUNT_C - 1;
	}

	if (main_player.pos.y <= 0)	 {
		main_player.pos.y =  0;
	}

	if (main_player.pos.x*TILE_W + main_player.width >= (TILES_COUNT_R-1)*TILE_W)	 {
		// indexes start at 0 !
		main_player.pos.x =  TILES_COUNT_R - 1;
	}

}

void simple_move()
{
	if (IsKeyPressed(KEY_LEFT))
	{
		//
		main_player.pos.x -= main_player.acceleration;

	}
	if (IsKeyPressed(KEY_DOWN)) {
		// main_player.pos.pos.y++; 
		main_player.pos.y += main_player.acceleration;
		
	}
	if (IsKeyPressed(KEY_UP)) {
		// main_player.pos.pos.y--;
		main_player.pos.y -= main_player.acceleration;
		
	}
	if (IsKeyPressed(KEY_RIGHT))
	{
		// main_player.pos.pos.x++;
		main_player.pos.x += main_player.acceleration;
	}
}

// void P_render()
// {

// }


// // Level Editor
// // Pixel art engine
// // hmm a game with infinite world ! with coordinates and multiplayer !