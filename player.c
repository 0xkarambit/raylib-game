#include <raylib.h>

#include "player.h"
#include "input.h"
#include "main.h"

extern Player_t main_player;
extern int TILE_H;
extern int TILE_W;
// extern KEYPRESSMAP_t key_press_map;

void p_render()
{
	// printf("called !\n");
	int x = main_player.pos.x;
	int y = main_player.pos.y;
	// DrawRectangle(100, 100, 30, 50, (Color){0,255,0});
	DrawRectangle(x, y, TILE_W, TILE_W, (Color){0,0,0, 255});
	
	// DrawRectangle(x, y, TILE_W * width ? , TILE_W * height ?, (Color){0,0,0, 255});
}


static const int DRAG = 2;
static const int MAX_VEL = 20;
static const int MIN_VEL = -20;

void p_update()
{

	// todo
	// middle mouse press to toggle max/min zoom
	// control to increase scrollSpeed

	// velocity x,y | checking all positions all the time ????? outside the if 
	// main_player.velocity.x += main_player.acceleration;
	// main_player.velocity.y += main_player.acceleration;

	// applying drag
	if (main_player.velocity.x != 0) {
		main_player.velocity.x += (main_player.velocity.x > 0) ? -DRAG : DRAG;
	}
	if (main_player.velocity.y != 0) {
		main_player.velocity.y += (main_player.velocity.y > 0) ? -DRAG : DRAG;
	}

	// adding velocity and subtracting drag as per laws of physics
	main_player.pos.x += main_player.velocity.x;
	main_player.pos.y += main_player.velocity.y;
	
	// should i allow velocity to have neg x,y values or add a direction prop ??? neg is better ig.


	// debugging stuff ! relocation on mouse click
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		main_player.pos.x = GetMouseX();
		main_player.pos.y = GetMouseY();
	}

	// check keypresses
	int acceleration = main_player.acceleration;
	if (IsKeyDown(KEY_LEFT))
	{
		//
		main_player.velocity.x = main_player.velocity.x <= MIN_VEL ? MIN_VEL : main_player.velocity.x - acceleration;

	}
	if (IsKeyDown(KEY_DOWN)) {
		// main_player.pos.y++; 
		main_player.velocity.y = main_player.velocity.y >= MAX_VEL ? MAX_VEL : main_player.velocity.y + acceleration;
		
	}
	if (IsKeyDown(KEY_UP)) {
		// main_player.pos.y--;
		main_player.velocity.y = main_player.velocity.y <= MIN_VEL ? MIN_VEL : main_player.velocity.y - acceleration;
		
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		// main_player.pos.x++;
		main_player.velocity.x = main_player.velocity.x >= MAX_VEL ? MAX_VEL : main_player.velocity.x + acceleration;
		
	}

	// checking if object is OUT OF BOUNDS !
	if (main_player.pos.x <= 0) {
		main_player.pos.x =  0;
	}
	// else {
	// 	 main_player.pos.x - acceleration;
	// }

	if (main_player.pos.y >= TILES_COUNT_C*TILE_H - 1)	 {
		main_player.pos.y =  TILES_COUNT_C*TILE_H -1;
	}
	// else {
	// 	 main_player.pos.y + acceleration;
	// }

	if (main_player.pos.y <= 0)	 {
		main_player.pos.y =  0;
	}
	// else {
	// 	 main_player.pos.y - acceleration;
	// }

	if (main_player.pos.x >= TILES_COUNT_R*TILE_W - 1)	 {
		main_player.pos.x =  TILES_COUNT_R*TILE_W -1;
	}
	// else {
	// 	 main_player.pos.x + acceleration;
	// }

}

// void P_render()
// {

// }


// // Level Editor
// // Pixel art engine
// // hmm a game with infinite world ! with coordinates and multiplayer !