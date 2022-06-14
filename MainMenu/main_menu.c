#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "../types.h"
#include "../UI/ui.h"

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
		
		printf("index %d y-coor : %d\n", i, thisElm->y);

		thisElm->w = ELEMENTS_WIDTH;
		thisElm->h = ELEMENTS_HEIGHT;

		// todo: add custom click logic to swap scene
		thisElm->onClick = &btn_clicked;
	}
};

void mm_update()
{
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->pollClick(thisElm);
	}
};

void mm_render()
{
	ClearBackground((Color){255, 255, 255, 255});
	// render ui
	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->render(thisElm);
	}
};

void mm_exit()
{

	for (int i = 0; i < ELEMENTS_COUNT; ++i)
	{
		Element_t *thisElm = &elements[i];
		thisElm->onFree(thisElm);							// having these function pointers in structs might feel useless, but remember they are for custom unique functions
	}																				// like with onclick

	free(elements);
	printf("Scene Over !");
};


SCENE MAIN_MENU_SCENE = {
	.setup=&mm_setup,
	.update=&mm_update,
	.render=&mm_render,
	.exit=&mm_exit
};