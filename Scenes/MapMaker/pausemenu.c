// Scene Template

#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>
#include "../../scenes.h"
#include "../../UI/ui.h"

#include "pausemenu.h"

#define ELEMENTS_COUNT 3
#define ELEMENTS_WIDTH 500
#define ELEMENTS_HEIGHT 100
#define TOP_PADDING 50

bool isPaused = false;

// Elements_data
char* pm_strings[ELEMENTS_COUNT] = {
	"Continue",
	"Settings",
	"Exit to Main Menu"
};

void btn_clicked_new(Element_t *self) {
	printf("You clicked %s!\n", self->text);
};

extern SCENE MAIN_MENU_SCENE;
void goto_main_menu(Element_t *self) {
	printf("You clicked %s!\n", self->text);
	pause_menu_exit();
	switch_scene(&MAIN_MENU_SCENE);
};
void unpause(Element_t *self) {
	printf("You clicked %s!\n", self->text);
	isPaused = false;
	// pause_menu_exit(); // should i even be calling it here ? wouldnt it be better to keep the resources allocated as long as the parent scene is active and the game can be paused
};

// these functions always take `Element_t *self` as the only arg so i should typedef it
void (*pm_onclick_functions[])() = {
	&unpause,
	&btn_clicked_new,
	&goto_main_menu
};


Element_t* pm_elements = (Element_t*)0;

void pause_menu_setup()
{
	isPaused = true;

	pm_elements = calloc(sizeof(Element_t), ELEMENTS_COUNT);
	int w  = GetScreenWidth();
	
	int x_coor = w/2 - ELEMENTS_WIDTH/2;
	int y_coor = 0 + TOP_PADDING;
	int offset = TOP_PADDING;

	// initialising all the menu buttons
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &pm_elements[i];
		*thisElm = ui_create_button(pm_strings[i]);

		thisElm->bg_color = (Color){200, 23, 23, 255};
		thisElm->color = (Color){255, 255, 255, 255};
		thisElm->x = x_coor;
		thisElm->y = y_coor;
		y_coor += (ELEMENTS_HEIGHT + offset);

		thisElm->w = ELEMENTS_WIDTH;
		thisElm->h = ELEMENTS_HEIGHT;

		// todo: add custom click logic to swap scene
		thisElm->onClick = pm_onclick_functions[i];
	}
};

void pause_menu_update()
{
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &pm_elements[i];
		thisElm->pollClick(thisElm);
	}
};

void pause_menu_render()
{
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &pm_elements[i];
		thisElm->render(thisElm);
	}
};

bool pause_menu_exit()
{
	isPaused = false;
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &pm_elements[i];
		thisElm->onFree(thisElm);							// having these function pointers in structs might feel useless, but remember they are for custom unique functions
	}																				// like with onclick

	free(pm_elements);

	printf("Pause menu scene off \n");
	return true;
};


SCENE pause_menu_SCENE = {
	.setup=&pause_menu_setup,
	.update=&pause_menu_update,
	.render=&pause_menu_render,
	.exit=&pause_menu_exit
};
