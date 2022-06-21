#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "../../scenes.h"
#include "../../UI/ui.h"
#include "../../UI/UIGroup.h"

#include "main_menu.h"
#include "buttons.h"

// distinction between HUD ELEMENTS | absolutely positioned rendered elements !, stay still can be responsive if camera draw_distance is used
// and normal graphics ! elements  | camera relative graphics (x,y are affected by camera position),

#define ELEMENTS_COUNT 4
#define ELEMENTS_WIDTH 500
#define ELEMENTS_HEIGHT 100
#define TOP_PADDING 50

// Elements_data

extern bool should_exit;
extern SCENE WIP_SCENE;
extern SCENE MAP_MAKER_SCENE;

void change_to_wip()
{
	switch_scene(&WIP_SCENE);
}

void change_to_game()
{
	switch_scene(&MAP_MAKER_SCENE);
}
void exit_game()
{
	// MAIN_MENU_SCENE.exit();
	should_exit = true;
}

Element_data_t mm_elm_data[] = {
	{
		.text="Play Game",
		.onClick=&change_to_game,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT
	},
	{
		.text="Settings",
		.onClick=&btn_clicked,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT 
	},
	{
		.text="Design a Level",
		.onClick=&change_to_wip,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT 
	},
	{
		.text="Exit",
		.onClick=&exit_game,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT 
	},
};

UIGROUP_t *mm_uigrp = 0;

void mm_setup()
{
	// allocating space for ui_grp !;
	mm_uigrp = calloc(sizeof(UIGROUP_t), 1);

	int w  = GetScreenWidth();
	// int h  = GetScreenHeight();
	int x_coor = w/2 - ELEMENTS_WIDTH/2;
	int y_coor = 0 + TOP_PADDING;
	int offset = TOP_PADDING;

	// initialising all the menu buttons
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		mm_elm_data[i].bg_color = (Color){200, 23, 23, 255};
		mm_elm_data[i].color = (Color){255, 255, 255, 255};
		mm_elm_data[i].x = x_coor;
		mm_elm_data[i].y = y_coor;
		y_coor += (ELEMENTS_HEIGHT + offset);
	}

	UIGroup_setup(mm_uigrp, ELEMENTS_COUNT, &mm_elm_data[0]);
};

void mm_update()
{
	UIGroup_update(mm_uigrp);
};

void mm_render()
{
	ClearBackground((Color){255,255,255,255});
	UIGroup_render(mm_uigrp);
};

bool mm_exit()
{
	UIGroup_exit(mm_uigrp);
	free(mm_uigrp);
	printf("MAIN_MENU_SCENE Scene Over !\n");
	return true;
};


SCENE MAIN_MENU_SCENE = {
	.setup=&mm_setup,
	.update=&mm_update,
	.render=&mm_render,
	.exit=&mm_exit
};
