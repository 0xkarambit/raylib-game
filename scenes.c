#include "scenes.h"


// i dont think we need the extern include and the ALL_SCENES array we can just extern def it in the files where we need it !
extern SCENE MAIN_MENU_SCENE;
extern SCENE WIP_SCENE;

SCENE* ALL_SCENES[] = {
	&MAIN_MENU_SCENE,
	&WIP_SCENE
};

extern SCENE* current_scene;

bool switch_scene(SCENE* next_scene)
{
	if (current_scene->exit())
	{
		current_scene = next_scene;
		current_scene->setup();
	} else {
		// unable to exit scene ! user must have something going on ...??
		return false;
	}

	return true;
}