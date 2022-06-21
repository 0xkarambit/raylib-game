#include <stdio.h>

#include "scenes.h"


// i dont think we need the extern include and the ALL_SCENES array we can just extern def it in the files where we need it !
extern SCENE MAIN_MENU_SCENE;
extern SCENE WIP_SCENE;

SCENE* ALL_SCENES[] = {
	&MAIN_MENU_SCENE,
	&WIP_SCENE
};

extern SCENE* current_scene;
extern SCENE* next_scene;

bool switch_scene(SCENE* nxt_scene)
{
	printf("QUEUEING SCENE !\n");
	next_scene = nxt_scene;
	return true;
}

bool swap_scenes()
{
	if (next_scene != NULL)
	{
		if (current_scene->exit())
		{
			current_scene = next_scene;
			current_scene->setup();
			next_scene = NULL;
		} else {
			return false;
		}
		return true;
	}
	return false;
}

// okay so we need to change the switch_scene function !