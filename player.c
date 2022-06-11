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
	int width = main_player.width;
	int height = main_player.height;
	// DrawRectangle(100, 100, 30, 50, (Color){0,255,0});
	DrawRectangle(x*TILE_W, y*TILE_H, TILE_W*width, TILE_H*height, (Color){0,0,0, 255});
	
	// DrawRectangle(x, y, TILE_W * width ? , TILE_W * height ?, (Color){0,0,0, 255});
}


static const int DRAG = 1;
static const int MAX_VEL = 20;
static const int MIN_VEL = -20;

void p_update()
{

	// todo
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
	struct int_vec2 *velocity = &main_player.velocity;

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

	if (main_player.pos.y*TILE_H + main_player.height >= TILES_COUNT_C*TILE_H - 1)	 {
		// main_player.pos.y =  TILES_COUNT_C*TILE_H -1;
		main_player.pos.y =  TILES_COUNT_C;
	}

	if (main_player.pos.y <= 0)	 {
		main_player.pos.y =  0;
	}

	if (main_player.pos.x*TILE_W + main_player.width >= TILES_COUNT_R*TILE_W - 1)	 {
		// main_player.pos.x =  TILES_COUNT_R*TILE_W -1;
		main_player.pos.x =  TILES_COUNT_R;
	}

}

// void P_render()
// {

// }


// // Level Editor
// // Pixel art engine
// // hmm a game with infinite world ! with coordinates and multiplayer !