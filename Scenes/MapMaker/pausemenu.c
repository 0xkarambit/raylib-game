// Scene Template

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include <raylib.h>
#include "../../scenes.h"
#include "../../UI/ui.h"
#include "../../UI/UIGroup.h"

#include "pausemenu.h"

#define ELEMENTS_COUNT 3
#define ELEMENTS_WIDTH 500
#define ELEMENTS_HEIGHT 100
#define TOP_PADDING 50

bool isPaused = false;

// Elements_data
extern SCENE MAIN_MENU_SCENE;
void btn_clicked_new(Element_t *self) {
	printf("You clicked %s!\n", self->text);
};

void goto_main_menu(Element_t *self) {
	printf("You clicked %s!\n", self->text);
	switch_scene(&MAIN_MENU_SCENE);
};

void unpause(Element_t *self) {
	printf("You clicked %s!\n", self->text);
	isPaused = false;
	// pause_menu_exit(); // should i even be calling it here ? wouldnt it be better to keep the resources allocated as long as the parent scene is active and the game can be paused
};

Element_data_t pm_elm_data[] = {
	{
		.text="Continue",
		.onClick=&unpause,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT
	},
	{
		.text="Settings",
		.onClick=&btn_clicked_new,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT 
	},
	{
		.text="Exit to Main Menu",
		.onClick=&goto_main_menu,
		.fs=24,
		.w=ELEMENTS_WIDTH,
		.h=ELEMENTS_HEIGHT 
	},
};

UIGROUP_t *pm_uigrp = 0;

void pause_menu_setup()
{

	pm_uigrp = calloc(sizeof(UIGROUP_t), 1);

	isPaused = true;

	int w  = GetScreenWidth();	
	int x_coor = w/2 - ELEMENTS_WIDTH/2;
	int y_coor = 0 + TOP_PADDING;
	int offset = TOP_PADDING;

	// initialising all the menu buttons
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		pm_elm_data[i].bg_color = (Color){200, 23, 23, 255};
		pm_elm_data[i].color = (Color){255, 255, 255, 255};
		pm_elm_data[i].x = x_coor;
		pm_elm_data[i].y = y_coor;
		y_coor += (ELEMENTS_HEIGHT + offset);
	}

	UIGroup_setup(pm_uigrp, ELEMENTS_COUNT, &pm_elm_data[0]);
};

void pause_menu_update()
{
	UIGroup_update(pm_uigrp);
};

void pause_menu_render()
{
	// ClearBackground(WHITE);
	UIGroup_render(pm_uigrp);
};

bool pause_menu_exit()
{
	isPaused = false;
	UIGroup_exit(pm_uigrp);
	free(pm_uigrp);

	printf("Pause menu resources freed ! \n");
	return true;
};


SCENE pause_menu_SCENE = {
	.setup=&pause_menu_setup,
	.update=&pause_menu_update,
	.render=&pause_menu_render,
	.exit=&pause_menu_exit
};
