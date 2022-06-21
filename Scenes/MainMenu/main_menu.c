#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "../../scenes.h"
#include "../../UI/ui.h"

#include "main_menu.h"
#include "buttons.h"

// distinction between HUD ELEMENTS | absolutely positioned rendered elements !, stay still can be responsive if camera draw_distance is used
// and normal graphics ! elements  | camera relative graphics (x,y are affected by camera position),

#define ELEMENTS_COUNT 4
#define ELEMENTS_WIDTH 500
#define ELEMENTS_HEIGHT 100
#define TOP_PADDING 50

// Elements_data
char* strings[ELEMENTS_COUNT] = {
	"Play Game",
	"Settings",
	"Design a Level",
	"Credits"
};

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

void (*onclick_functions[])() = {
	&change_to_game,
	&btn_clicked,
	&change_to_wip,
	&btn_clicked,
};

Element_t* elements = (Element_t*)0;

void mm_setup()
{
	// allocating space for elements !;
	elements = calloc(sizeof(Element_t), ELEMENTS_COUNT);

	int w  = GetScreenWidth();
	// int h  = GetScreenHeight();
	int x_coor = w/2 - ELEMENTS_WIDTH/2;
	int y_coor = 0 + TOP_PADDING;
	int offset = TOP_PADDING;

	// initialising all the menu buttons
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		*thisElm = ui_create_button(strings[i]);

		thisElm->bg_color = (Color){200, 23, 23, 255};
		thisElm->color = (Color){255, 255, 255, 255};
		thisElm->x = x_coor;
		thisElm->y = y_coor;
		y_coor += (ELEMENTS_HEIGHT + offset);

		thisElm->w = ELEMENTS_WIDTH;
		thisElm->h = ELEMENTS_HEIGHT;

		// todo: add custom click logic to swap scene
		thisElm->onClick = onclick_functions[i];
	}
};

void mm_update()
{
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->pollClick(thisElm);
		// debug info:
		// after pollClick calls the onClicked which calls the switch_scene the control flow jumps back here
		//  and it leads to errors as this scene's exit function has already been called and all the objects have been freed !
	}
};

void mm_render()
{
	ClearBackground((Color){255, 255, 255, 255});
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->render(thisElm);
	}
};

bool mm_exit()
{
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->onFree(thisElm);							// having these function pointers in structs might feel useless, but remember they are for custom unique functions
	}																				// like with onclick

	free(elements);
	printf("MAIN_MENU_SCENE Scene Over !\n");
	return true;
};


SCENE MAIN_MENU_SCENE = {
	.setup=&mm_setup,
	.update=&mm_update,
	.render=&mm_render,
	.exit=&mm_exit
};