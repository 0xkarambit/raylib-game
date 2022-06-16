
#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "../../scenes.h"
#include "../../UI/ui.h"

extern SCENE MAIN_MENU_SCENE;

void go_back(Element_t *self)
{
	printf("CLICKED : %s\n", self->text);
	switch_scene(&MAIN_MENU_SCENE);
};

Element_t back_btn = {0};

void wip_setup()
{
	printf("WIP SCENE INITIATED !");	// dont rely on print debuggin since its buffered

	back_btn = ui_create_button("Go Back");
	
	back_btn.bg_color = (Color){200, 23, 23, 255};
	back_btn.color = (Color){255, 255, 255, 255};
	back_btn.x = 100;
	back_btn.y = 100;
	back_btn.w = 400;
	back_btn.h = 400;

	back_btn.onClick = &go_back;
};

void wip_update()
{
	back_btn.pollClick(&back_btn);
};

void wip_render()
{
	ClearBackground((Color){255, 255, 255, 255});
	// DrawRectangle(100, 100, 345, 400, (Color){123,34,45,255});
	back_btn.render(&back_btn);
};

bool wip_exit()
{
	printf("WIP Scene left !\n");
	back_btn.onFree(&back_btn);		// this works as well although i should keep the style consistent
	return true;
};


SCENE WIP_SCENE = {
	.setup=&wip_setup,
	.update=&wip_update,
	.render=&wip_render,
	.exit=&wip_exit
};