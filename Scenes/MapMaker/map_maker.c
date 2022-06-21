#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "../../main.h"

#include "../../scenes.h"
#include "../../UI/ui.h"

#include "../../utils.h"
#include "../../tiles.h"
#include "../../camera.h"
#include "../../mouse.h"

#include "../../player.h"

#include "pausemenu.h"


int TILE_H = 0; // HEIGHT / TILES_COUNT_R;	// each tile Height
int TILE_W = 0; // WIDTH / TILES_COUNT_C;		// each tile Width

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


// KEYPRESSMAP_t key_press_map = { 0, 0, 0, 0 };
Player_t main_player = {
	.pos={2, 3},	// x is the colNO and y is the rowNO, they start from 0
	.acceleration=2,
	.velocity={0,0},
	.width=1,
	.height=1
};

extern bool isPaused;

Element_t *pause_btn = 0;

void map_maker_setup()
{
	pause_btn = calloc(sizeof(Element_t), 1);
	*pause_btn = ui_create_button("Pause");
	pause_btn->onClick = &pause_menu_setup;
	pause_btn->x = 40;
	pause_btn->y = 40;
	pause_btn->w = 300;
	pause_btn->h = 100;
	pause_btn->bg_color = BLACK;
	pause_btn->color = RED;
	pause_btn->fs = 18;

	// setting according to camera
	TILE_H = HEIGHT / camera.draw_distance.y;	// each tile Height
	TILE_W = WIDTH / camera.draw_distance.x;		// each tile Width	

};

void map_maker_update()
{
	// tribber pause menu
	if (IsKeyPressed(KEY_BACKSPACE)) (isPaused) ? pause_menu_exit() : pause_menu_setup();
	if (isPaused) { pause_menu_update(); return; };

	// pause btn
	pause_btn->pollClick(pause_btn);

	p_update();
	// simple_move();
	// DrawRectangle(0, 0, TILE_W, TILE_H, (Color){32,255,343, 214});
	mouse_update();
	Camera_follow_entity(main_player);
};

void map_maker_render()
{
	if (isPaused) {
		// render pause menu
		pause_menu_render();
		return ;
	};
	ClearBackground(GRAY);
	drawTiles();
	p_render();
	pause_btn->render(pause_btn);
};

bool map_maker_exit()
{
	if (isPaused) pause_menu_exit();
	pause_btn->onFree(pause_btn);
	printf("leaving the MAP_MAKER scene !\n");
	return true;
};


SCENE MAP_MAKER_SCENE = {
	.setup=&map_maker_setup,
	.update=&map_maker_update,
	.render=&map_maker_render,
	.exit=&map_maker_exit
};
